#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 9001
#define BUF_SIZE 1024

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUF_SIZE] = {0};
    char *filename = "test.jpeg";
    FILE *fp;

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Receive packets and write to file
    int total_size = 0;
    int expected_packet_size = BUF_SIZE;
    int header_size = 0;
    int first_packet = 1;
    while (total_size < 100000)
    {
        if ((valread = recvfrom(server_fd, buffer, expected_packet_size, 0, (struct sockaddr *)&address, &addrlen)) < 0)
        {
            perror("recvfrom failed");
            exit(EXIT_FAILURE);
        }

        if (first_packet)
        {
            // Check if the first packet is a valid JPEG file
            if (buffer[0] != 0xFF || buffer[1] != 0xD8)
            {
                printf("Not a valid JPEG file\n");
                continue;  // skip this packet and wait for the next one
            }

            // Get the JPEG file header size
            header_size = 2;
            while (buffer[header_size] == 0xFF)
            {
                header_size++;
                if (buffer[header_size] == 0xD8 || buffer[header_size] == 0xD9)
                    break;
                header_size += ntohs(*(unsigned short *)(buffer + header_size)) + 2;
            }
            header_size += 2;

            // Write the first packet to file without the JPEG file header
            fp = fopen(filename, "wb");
            if (fp == NULL) {
                perror("fopen failed");
                exit(EXIT_FAILURE);
            }
            fwrite(buffer + header_size, sizeof(char), valread - header_size, fp);
            first_packet = 0;
        }
        else
        {
            // Write subsequent packets to file
            fwrite(buffer, sizeof(char), valread, fp);
        }

        total_size += valread;
    }

    fclose(fp);
    printf("Image received and written to %s\n", filename);

    close(server_fd);
    return 0;
}
