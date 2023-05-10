# 개발 중 문제점
개발일자 : 2023.05.10
1. VM간 통신문제
    - 원인 : 각각 다른 Host 환경에서 VM을 생성하여 이미지 전송 프로그램을 동작시키려 했으나, 문제가 발생함. 이유는 Virtual Box에서 Network 설정을 하지 않아 같은 네트워크 상에 존재하더라도 NAT로 인하여 다른 Host에서 반대편 Host 환경 내부에 Virtual Box의 IP에 접근할 수 없었기 때문이다.
    - 해결방법 : Virtual Box **환경설정-Network-브리지** 를 설정하여 Host IP와 같은 Network 환경에 위치할 수 있게 설정을 바꿔줌    
    ![image](https://github.com/WoogiBoogi1129/MultiThread_Data_Receiver/assets/110087545/e1cd9569-cc40-4bd8-b5bd-a78037f3c5db)

2. 이미지 확장자로인한 에러
3. 패킷 누적 문제
------------------------