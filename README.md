# MultiThread_Data_Receiver
- 수행계획서 내용
    1. 프로젝트 정보
    ![image](https://user-images.githubusercontent.com/110087545/236786771-57b7ce6f-9c26-4b7c-b61e-ae262a0d7ab7.png)   
    2. 프로젝트 수행계획
        1. 프로젝트 개요
            1. 프로젝트 소개
                - 멀티 스레드 기반 UDP 통신을 이용한 데이터 전송 프로그램
            2. 추진배경 및 필요성
                - UDP 통신의 데이터 전송은 패킷 단위로 데이터를 보내 순차적으로 데이터를 전송한다. 하지만 이러한 방식은 싱글프로세스 방식으로 많은 양의 데이터를 전송하기에 는 데이터 전송 속도 저하와 대기 시간의 증가로 프로그램의 효율성을 떨어뜨린다. 해당 문제를 해결하기 위해서는 멀티프로세스 또는 멀티스레드 방식을 이용한다면 더 높은 효율을 낼 수 있을 것이다.
        2. 프로젝트 내용
            1. 주요 기능
                ![image](https://user-images.githubusercontent.com/110087545/236787345-cc2d4bf6-69db-4369-8d18-723a61ba1e47.png)
                1. 멀티스레드 방식을 통한 데이터 분할 송신
                2. 멀티스레드 방식을 통한 데이터 전송 안정성 향상
            2. 적용 기술
                1. UDP 통신 연결 : UDP는 비연결성의 특성을 가지고 있기 때문에 TCP와 비교해서 빠른 속도로 데이터를 전송할 수 있다.
                2. 이미지 데이터 분할 전송 : 데이터를 일정한 크기로 분할하여 전송하는 기능이다. 이를 통해 데이터 전송 속도를 향상시킬 수 있다. 예를 들어, 100MB의 데이터를 한번에 전송하는 것보다, 10MB 단위로 분할하여 전송하는 것이 더 빠른 전송을 가능하게 해준다.
                3. 오류 감지 및 수정 : 프로젝트는 오류 감지 및 수정 기술을 구현하여 신뢰성을 보장한다. 각 패킷은 도착 시 무결성이 확인되며 손상된 패킷은 올바르게 전송되도록 재전송된다.
            3. 성과 목표
                1. UDP 통신 기반 데이터 송수신 프로그램 제작
                2. 데이터 전송 속도 향상
                3. 데이터 전송 안정성 향상
        3. 프로젝트 수행방법
            1. 프로젝트 추진 일정
                ![image](https://user-images.githubusercontent.com/110087545/236788565-a1675127-3e50-4a12-ad3a-28aee2355cfc.png)
            2. 역할분담
                1. 황태욱 : 팀장, 발표, 오류사항 보완
                2. 강태호 : 멀티스레드 방식 데이터 전송 알고리즘 구현
                3. 이재휘 : 싱글프로세스 / UDP 기반 이미지 전송 구현 및 테스트
                4. 허병규 : 보고서 작성, 프로그램 개발 보조
    3. 기대효과 및 활용분야
        1. 기대효과
            - 빠르고 효율적인 패킷 전달 : UDP 통신을 기반으로 빠른 전송 속도 확보와 Multi Thread 방식을 사용하여 데이터 전송 속도를 더욱 향상시킨다.
            - 안정성 향상 및 대기 시간 감소 : 시스템의 전체적인 소도의 딜레이로 인해 불안정한 시스템을 원할하게 동작하면서 안정적으로 유지한다. Multi Thread 기반 UDP 통신이기 때문에 저송 중 손실이 나더라도 빠르게 재전송 할 수 있다면 속도의 딜레이로 인한 불안정성 및 대기 시간 감소가 가능하다.
            - 대용량 데이터 전송 : 데이터 사이즈가 큰 이미지를 분할하여 전송함으로써 대용량 데이터에서도 빠른 속도 유지가 가능하다.
        2. 활용분야
            - 실시간 통신 분야 서비스 개선 : 온라인 게임, 화상 회의, 스트리밍 서비스 등에서 실시간으로 빠른 데이터 전송이 가능하기 때문에 실시간 서비스 분야 에서 사용자들의 더욱 높은 서비스 품질보장이 가능하다.
            - 산업 제어 시스템 성능 개선 및 중단 시간 단축 : 실시간 데이터 송수신 기능을 필요로 하는 산업 제어 시스템은 다양한 센서 및 장비들이 연결되어있다.  이 때 데이터 전송 속도가 늦어지면 하나의 장비에서만 문제가 생기는 것이 아닌 연쇄적으로 시스템에 문제가 발생할 수 있다. 따라서 산업 제어 시스템 성능 개선 및 이상 현상 감지가 가능하여 생산성 향상과 장비 이상 동작을 예방할 수 있다.