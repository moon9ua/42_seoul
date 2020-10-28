# ft_server

요약: 이것은 시스템 관리 주제이다. 당신은 도커를 발견하고 첫 번째 웹 서버를 설정할 것이다.

## Chapter 1. 서론

이 주제는 시스템 관리를 소개한다. 스크립트를 사용한 작업 자동화의 중요성을 알게해줄 것이다. 이를 위해 당신은 도커 기술을 발견하고, 이를 이용해 완전한 웹 서버를 설치할 것이다. 이 서버는 Wordpress, phpMyAdmin, SQL database와 같은 다중 서비스를 실행할 것이다.

## Chapter 2. 일반 지침

* 서버 구성에 필요한 모든 파일은 srcs 폴더에 있어야 한다.
* Dockerfile은 레포지토리의 루트에 있어야 한다. 이것은 당신의 container을 빌드한다. docker-compose는 사용할 수 없다.
* WordPress 웹사이트에 필요한 모든 파일은 srcs 폴더에 있어야 한다.

## Chapter 3. 필수 파트

* 단 하나의 도커 container에만 Nginx를 사용해서 웹 서버를 설정해야 한다. container OS는 반드시 debian buster이어야 한다.
* 웹 서버는 여러 서비스를 동시에 실행할 수 있어야 한다. 서비스는 WordPress 웹사이트, phpMyAdmin, MySQL이다. 당신의 SQL 데이터베이스가 WordPress 및 phpMyAdmin과 잘 작동하는지 확인해야 한다.
* 서버는 SSL 프로토콜을 사용할 수 있어야 한다.
* URL에 따라 서버가 올바른 웹사이트로 redirect 되는지 확인해야 한다.
* 비활성화 할 수 있는 autoindex로 서버가 실행 중인지 확인해야 한다.