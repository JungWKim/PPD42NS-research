# Own research about how to control PPD42NS(dust sensor)
## 1. dustTest.c
### - IndoorAirPurificationIoT에서는 아두이노에 미세먼지 센서를 연결해서 라즈베리파이에 시리얼통신으로 데이터를 전송해서 수치에 따라 주변 장치를 제어
### - dustTest.c에서는 아두이노 없이 미세먼지센서를 라즈베리파이에 직접 연결하여 미세먼지 농도를 값을 산출하기 위한 계산을 하여 화면에 출력하는 것까지만 구현
### 결과 : 정상작동
##
## 2. dustTest.py
### - IndoorAirPurificationIoT에서 파이썬으로 아두이노를 제어한 것까진 같지만 pyfirmata라는 패키지를 이용하여 아두이노에서 미세먼지값을 측정함.
### 결과 : 비정상적으로 큰 수치 발생, 원인규명X
##
## 3. serialTest.c
### - C언어로 아두이노와의 시리얼통신으로 데이터를 받기만하는 간단한 프로그램. 학습목적으로 제작
##
## 4. serialTest.py
### - 파이썬으로 아두이노와 시리얼통신을 구현한 코드. 단순 학습목적으로 
