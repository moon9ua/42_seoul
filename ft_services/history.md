# ft_services

## 20.07.06 1일차

* https://subicura.com/2019/05/19/kubernetes-basic-1.html

* https://github.com/t0mm4rx/ft_services

    <details>
    <summary> 번역 </summary>

    ## 개요

    ### 도커와 쿠버네티스란?
    도커는 가벼운 가상머신을 실행할 수 있게 하는 소프트웨어이다. 당신은 dockerfile을 이용해서 컨테이너를 만들 수 있고, 컨테이너란 자체 메모리 공간과 스토리지가 있는 OS를 실행하는 가벼운 가상머신이다. 그러나 컨테이너는 호스트 컴퓨터와 동일한 커널을 사용한다는 점이 가상머신과는 다르다. 컨테이너가 보다 빠르고 가볍다.

    많은 컨테이너와 서비스(데이터베이스, 웹 서버들, 모니터링 툴, ftp, ssh 등)가 필요한 큰 앱을 실행하는 경우, 여러 컨테이너를 관리하는 방법이 필요하다. 충돌한 컨테이너를 자동으로 다시 시작하고, 컨테이너 간 데이터를 공유하고, 일부는 외부에서 가져올 수 있거나 없게 해야 한다. 이러한 이유로 쿠버네티스를 사용한다.

    쿠버네티스에는 다음이 존재한다:<br>
    * deployment: 도커 이미지의 n개 인스턴스를 실행하고 관리하는 개체. 예를 들어, 10개의 아파치 서버를 실행하고 관리하는 deployment.
    * service: deployment를 외부 또는 다른 컨테이너로 연결하는 개체. 예를 들어, 192.168.0.1을 10개의 아파치 서버에 연결하고 가장 적은 작업 부하를 가진 서버를 선택하는 것.
    * pod: deployment의 실행중인 인스턴스. 따라서 셸을 실행할 수 있다. pod는 자체 IP와 메모리 공간을 지닌다.

    위의 모든 개체들은 YAML 파일에 기술된다.

    minikube는 (쿠버네티스를 실행하고 virtualbox와의 호환성을 보장하는) 가상 머신을 만드는 데 사용되는 소프트웨어이다. 많은 tool이 있는 것이 특징인데, 예를 들어 당신의 pod가 어떻게 돌아가고 있는지 보여주는 대쉬보드와 같은 도구가 있다.

    ### 도커 기본 명령어
    ```
    docker build -t <이미지명> <도커파일위치>
    docker run -it <이미지명>
    docker run -it debian:apache -p 80:80
    docker images
    docker ps
    docker kill <컨테이너>
    docker system prune # 사용하지 않는 이미지나 캐시 삭제
    ```

    ### 쿠버네티스를 사용한 pod 관리
    ```
    # YAML 파일로부터 pod 생성하기
    kubectl create -f <YAML 파일>

    # pod 삭제하기
    kubectl delete deployment <deployment>
    kubectl delete service <service>

    # pod에서 셸 실행
    kubectl get pods
    kubectl exec -it <pod명> -- /bin/sh

    # 내 컴퓨터에서 pod로 파일 복사, 혹은 반대
    kubectl cp <pod명>:<파일> <to>
    kubectl cp <from> <pod명>:<to>

    # deployment 재실행
    kubectl rollout restart deployment <deployment명>

    # minikube 대쉬보드 실행
    minikube dashboard

    # 클러스터의 외부 IP 얻기
    minikube ip

    # minikube vm 리셋
    minikube delete
    ```

    ### 쿠버네티스로 IP를 관리하는 법
    쿠버네티스는 모든 컨테이너들을 연결하는 네트워크를 만든다. 각 컨테이너에는 고유한 개인 IP 주소가 있다. 네트워크는 (minikube ip로 얻을 수 있는) 외부 IP가 있다. 때로는 당신은 컨테이너를 다른 컨테이너와 연결하고 싶을 수 있다. 예를 들어, 당신은 컨테이너 안에 다른 컨테이너의 데이터베이스를 필요로 하는 웹사이트를 가지고 있다고 하자. 이럴 때엔 데이터베이스 컨테이너에 쉽게 접근할 수 있는 service를 만들어야 할 것이다.

    쿠버네티스 네트워크에서는 service에 IP가 아닌 서비스명으로 접근할 수 있다. 예를 들어, MySQL 컨테이너와 연결된 mysql 서비스가 있다. 이 컨테이너를 Nginx 컨테이너에서 접근하려면 다음과 같이 할 수 있다:

    ```
    mysql <database> -u <user> -p -h mysql
    mysql <database> -u <user> -p -h 127.0.0.10
    ```

    다른 예로, "test"라는 서비스와 포트 1000으로 호스트된 웹페이지가 있다고 하자. minikube ip는 192.168.0.1이다.
    ```
    # 컨테이너에서 웹페이지에 접근
    curl http://test:1000
    # 외부에서 웹페이지에 접근
    curl http://192.168.0.1:1000
    ```

    ### minikube와 도커 연결하기
    minikube는 도커 이미지를 실행할 특정 VM을 VirtualBox에 만든다. 당신은 당신의 셸과 minikube를 연결해야 한다. 다음 명령어를 통해 수행할 수 있다:
    ```
    eval $(minikube docker-env)
    ```
    다음을 통해 실행되고 있는지 테스트해볼 수 있다:
    ```
    docker images
    ```
    당신은 현재 환경에 연결된 모든 이미지를 확인할 수 있다.

    기본적으로 쿠버네티스 deployment는 온라인 도커 이미지를 찾지만, 우리는 사용자의 로컬 이미지를 로드하고자 한다. 당신은 컨테이너 객체에 "imagePullPolicy:Never"을 추가하여 이것을 수행할 수 있다.

    ## 컨테이너들

    ### Nginx
    ### FTPs
    ### Wordpress
    ### PHPMyAdmin
    ### Grafana

    </details>
    

## 20.07.15 (수) 2일차

\# ft_services

* https://github.com/woolimi/ft_services
* https://www.notion.so/ft_service-85d6cd8b023043f08ed0f5e1f04848cf
* https://github.com/ClemaX/ft_services

\# 쿠버네티스
* https://github.com/kubernetes/examples/tree/master/staging/https-nginx/
* https://kubernetes.io/ko/docs/tasks/tools/install-minikube/ : `brew install minikube`
* https://judo0179.tistory.com/66?category=349244 : 쿠버네티스 기본 명령어

\# minikube

* https://judo0179.tistory.com/70 : # *the connection to the server localhost 8080 was refused minikube* 기본적인 내용이 잘 나와있다.
* https://aidanbae.github.io/code/devops/k8s/start/
* https://m.blog.naver.com/PostView.nhn?blogId=sharplee7&logNo=221737855770&categoryNo=0&proxyReferer=https:%2F%2Fwww.google.com%2F
* https://medium.com/humanscape-tech/kubernetes-%EB%8F%84%EC%9E%85-%EC%A0%84-minikube-%EC%82%AC%EC%9A%A9%EA%B8%B0-2eb2b6d8e444
* https://medium.com/@cratios48/minikube-%EC%84%A4%EC%B9%98-%EB%B0%8F-%ED%99%9C%EC%9A%A9-4a63ddbc7fcb
* https://bum752.github.io/posts/minikube%EB%A5%BC-%EC%9D%B4%EC%9A%A9%ED%95%B4-%EB%A1%9C%EC%BB%AC-%EC%BF%A0%EB%B2%84%EB%84%A4%ED%8B%B0%EC%8A%A4-%ED%81%B4%EB%9F%AC%EC%8A%A4%ED%84%B0-%EA%B5%AC%EC%84%B1%ED%95%98%EA%B8%B0/

## 20.07.19 (일) 3일차

* https://kubernetes.io/ko/docs/tutorials/hello-minikube/ : 공식 문서 - 튜토리얼
* https://judo0179.tistory.com/71?category=349244
* https://coffeewhale.com/kubernetes/cka/2019/01/13/cak/
* https://coffeewhale.com/k8s/network/2019/04/19/k8s-network-01/
* https://kubernetes.io/ko/docs/concepts/workloads/pods/pod/ : 공식 문서 - 파드

\# Load Balander

* https://post.naver.com/viewer/postView.nhn?volumeNo=27046347&memberNo=2521903

\# /dev/null

* https://twpower.github.io/201-ignore-stderr-using-dev-null

\# 쉘 명령어

* https://mug896.github.io/bash-shell/eval.html : eval

\# 알파인 리눅스 \# apk add --no-cache

* https://jhhwang4195.tistory.com/67
* https://www.it-swarm-ko.tech/ko/docker/nocache-%eb%8c%80-alpine-dockerfile%ec%9d%98-%ec%9e%a5%ec%a0%90-rm-var-cache-apk/837954939/
* https://www.lesstif.com/docker/alpine-linux-35356819.html
* https://unix.stackexchange.com/questions/361814/whats-the-difference-between-software-update-and-upgrade: update vs upgrade

\# nginx default.conf

* https://sarc.io/index.php/nginx/61-nginx-nginx-conf
* https://wedul.site/579
* https://12bme.tistory.com/366

## 20.07.21 (화) 4일차

* https://www.redhat.com/ko/topics/containers/what-is-kubernetes
* https://www.notion.so/ft_service-a71586e4e6ed4c43965b9c9254e95dfc
* https://kubernetes.io/ko/docs/tutorials/stateless-application/expose-external-ip-address/

\# 쿠버네티스 오브젝트 \# yaml
* https://kubernetes.io/ko/docs/concepts/overview/working-with-objects/kubernetes-objects/

\# 레플리카셋
* https://kubernetes.io/ko/docs/concepts/workloads/controllers/replicaset/

## 20.07.22 (수) 5일차

* https://stackoverflow.com/questions/52310599/what-does-minikube-docker-env-mean
* https://medium.com/@yunhochung/k8s-%EB%8C%80%EC%89%AC%EB%B3%B4%EB%93%9C-%EC%84%A4%EC%B9%98-%EB%B0%8F-%EC%99%B8%EB%B6%80-%EC%A0%91%EC%86%8D-%EA%B8%B0%EB%8A%A5-%EC%B6%94%EA%B0%80%ED%95%98%EA%B8%B0-22ed1cd0999f
* https://kubernetes.io/ko/docs/reference/kubectl/cheatsheet/
* https://velog.io/@labyu/kubernetes-1
* https://bcho.tistory.com/1255?category=731548

\# ssh
* https://storycompiler.tistory.com/112

## 20.07.23 (목) 6일차

* https://minikube.sigs.k8s.io/docs/commands/start/#options : minikube start 옵션
* https://cheatsheet.dennyzhang.com/cheatsheet-minikube-a4 : minikube cheet sheet

\# nginx
* https://www.cyberciti.biz/faq/how-to-install-nginx-web-server-on-alpine-linux/
* https://www.osetc.com/en/how-to-install-and-configure-nginx-web-server-on-alpine-linux.html
* https://www.osetc.com/en/how-to-start-stop-restart-services-on-alpine-linux.html
* https://github.com/gliderlabs/docker-alpine/issues/437

\# CreateContainerConfigError
* https://stackoverflow.com/questions/50424754/pod-status-as-createcontainerconfigerror-in-minikube-cluster


## 20.07.25 (토) 7일차

* https://kubernetes.io/ko/docs/tutorials/stateless-application/expose-external-ip-address/ : external-ip pending

\# minikube metallb
* https://medium.com/faun/metallb-configuration-in-minikube-to-enable-kubernetes-service-of-type-loadbalancer-9559739787df
* https://medium.com/@shoaib_masood/metallb-network-loadbalancer-minikube-335d846dfdbe

\# nginx service
* https://kubernetes.io/ko/docs/concepts/services-networking/connect-applications-service/
* https://github.com/kubernetes/examples/tree/master/staging/https-nginx/

## 20.07.26 (일) 8일차

* https://hello-bryan.tistory.com/168?category=771155
* https://blog.voidmainvoid.net/138 : yaml

\# ssh
* https://opentutorials.org/module/432/3742
* http://egloos.zum.com/totoriver/v/2975161 : ssh_config vs sshd_config
* https://storycompiler.tistory.com/112
* https://thisblogfor.me/web/ssh/ : ssh 개념 설명
* https://zetawiki.com/wiki/Sshd : sshd

\# replicaset
* https://nirsa.tistory.com/136

\# shell script export variable not working
* `sh setup.sh`로 클러스터가 종종 생성되지 않았었다. 그 이유는 shell script를 sh 등으로 실행시키면 export가 작동하지 않았기 때문.
* https://stackoverflow.com/questions/10781824/export-not-working-in-my-shell-script
* https://unix.stackexchange.com/questions/30189/how-can-i-make-environment-variables-exported-in-a-shell-script-stick-around

## 20.07.27 (월) 9일차

\# ftp \# ftps
* https://nhj12311.tistory.com/76
* https://hamonikr.org/board_bFBk25/15985 : 개인 서버 구축 가이드 - ftp 서버
* https://m.blog.naver.com/PostView.nhn?blogId=haejoon90&logNo=220740558965&proxyReferer=https:%2F%2Fwww.google.com%2F : ftp 사용법
* https://heojea.tistory.com/entry/%EB%A6%AC%EB%88%85%EC%8A%A4-vsftp%EC%82%AC%EC%9A%A9%EB%B2%95%EB%B0%8F-%EC%84%A4%EC%A0%95%EB%B0%A9%EB%B2%95 : ftp 사용법 및 설정
* https://systembash.com/evaluating-ftp-servers-proftpd-vs-pureftpd-vs-vsftpd/ : ftp 비교

\# ftps alpine
* https://www.opensourceforu.com/2015/03/set-up-an-ftps-server-in-linux/ : ftps linux
* https://www.hiroom2.com/2018/09/01/alpinelinux-3-8-vsftpd-en/ : ftp alpine
* https://goddaehee.tistory.com/73 : ftp linux

\# docker ftp
* https://lahuman.jabsiri.co.kr/135 : ftp 서버 구축하기

\# vsftpd.conf
* https://zetawiki.com/wiki//etc/vsftpd/vsftpd.conf
* https://2factor.tistory.com/96
* https://purekid79.tistory.com/62 : 설정

\# docker run p 옵션
* https://soft.plusblog.co.kr/139

\# ftp active mode passive mode
* https://sata.kr/entry/5BFTP5D20FTPEC9D9820Active20ModeEC998020Passive20Mode20ECB0A8EC9DB4ECA090
* https://m.blog.naver.com/PostView.nhn?blogId=leekh8412&logNo=100152842034&proxyReferer=https:%2F%2Fwww.google.com%2F

\# ftp 20 21
* https://peemangit.tistory.com/66

* `kubectl delete services,deployment -l app=ftps`

\# tcp_wrappers is set to YES but no tcp wrapper support complined in
* https://dgblog.tistory.com/167

\# kubectl apply vs create

## 20.07.28 (화) 10일차

\# 500 oops child died vsftpd
* https://serverfault.com/questions/574722/vsftp-error-500-oops-child-died

\# alpine wordpress
* https://wiki.alpinelinux.org/wiki/WordPress

\# apk add --no-cache
* https://stackoverflow.com/questions/49118579/alpine-dockerfile-advantages-of-no-cache-vs-rm-var-cache-apk

\# \#!/bin/sh 의미
* https://storycompiler.tistory.com/101

\# php option
* http://www.ktword.co.kr/abbr_view.php?m_temp1=5729

\# mysql vs mysql-client
* https://stackoverflow.com/questions/6962890/what-is-the-difference-between-mysql-server-and-mysql-client

\# my.cnf
* https://mysqldba.tistory.com/26
* https://zetawiki.com/wiki/MySQL_%EC%84%A4%EC%A0%95%ED%8C%8C%EC%9D%BC_my.cnf#cite_note-1

\# mysqld
* https://jjongwoo.tistory.com/29

\# mysql bootstrap option
* https://mysqldba.tistory.com/289
* http://www.mysqlkorea.com/sub.html?mcode=manual&scode=01&m_no=21324&cat1=5&cat2=120&cat3=134&lang=k : MySQL코리아 - 한글매뉴얼 - mysqld 명령어 옵션
* http://www.dbguide.net/db.db?cmd=view&boardUid=146579&boardConfigUid=9&boardIdx=127&boardStep=1 : 데이터 전문가 지식포털 - MySQL 가이드

## 20.07.29 (수) 11일차

\# persistentvolume vs persistentvolumeclaim
* https://stackoverflow.com/questions/48956049/what-is-the-difference-between-persistent-volume-pv-and-persistent-volume-clai

\# wordpress mysql minikube
* https://kubernetes.io/ko/docs/tutorials/stateful-application/mysql-wordpress-persistent-volume/ : 공식 - wordpress와 mysql을 퍼시스턴스 볼륨에 배포하기
* https://arisu1000.tistory.com/27849 : 쿠버네티스 볼륨

\# error establishing a database connection
* https://www.thewordcracker.com/basic/error-establishing-a-database-connection-error/ : 워드프레스에서 '데이터베이스 연결 중 오류'

\# nohup 명령어
* https://medium.com/@jinnyjinnyjinjin/nohup-%EB%AA%85%EB%A0%B9%EC%96%B4%EB%A1%9C-%EC%96%B4%ED%94%8C%EB%A6%AC%EC%BC%80%EC%9D%B4%EC%85%98-%EC%8B%A4%ED%96%89%ED%95%98%EA%B8%B0-d66cc85d4f9

## 20.07.30 (목) 12일차

\# nohup &
* https://velog.io/@jakeseo_me/nohup-disown-%EB%8A%94-%EC%96%B8%EC%A0%9C-%EC%96%B4%EB%96%BB%EA%B2%8C-%EC%8D%A8%EC%95%BC%EB%90%A0%EA%B9%8C-9fjv7q9bz8

\# wsl 쿠버네티스
* https://blog.aliencube.org/ko/2018/06/04/running-kubernetes-on-wsl/

## 20.08.01 (토) 13일차

\# influxDB, telegraf, grafana
* https://portal.influxdata.com/downloads/ : influxDB 공식 - v1.8.1 다운로드
* https://github.com/influxdata/telegraf/releases : telegraf 깃허브
* https://thenewstack.io/
how-to-setup-influxdb-telegraf-and-grafana-on-docker-part-1/ : 도커
* https://www.popit.kr/influxdb_telegraf_grafana_1 : 한국어
* http://blog.naver.com/PostView.nhn?blogId=hanajava&logNo=221842160382&categoryNo=54&parentCategoryNo=40&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postList : 한국어

\# 리눅스 디렉토리 구조
* https://medium.com/harrythegreat/%EB%A6%AC%EB%88%85%EC%8A%A4-%EA%B8%B0%EC%B4%88-%EB%A3%A8%ED%8A%B8%EB%94%94%EB%A0%89%ED%86%A0%EB%A6%AC-%EA%B5%AC%EC%A1%B0-b3e4871af4b3
* https://webdir.tistory.com/101

\# alpine apk add repository
* https://wiki.alpinelinux.org/wiki/Alpine_Linux_package_management

## 20.08.02 (일) 14일차

\# influxdb.conf
* https://semode.tistory.com/236
* https://linux.systemv.pe.kr/influxdb-%EC%84%A4%EC%B9%98-%EB%B0%8F-%EC%84%A4%EC%A0%95/
* https://miiingo.tistory.com/94

\# telegraf.conf \# telegraf input
* https://support.cloudz.co.kr/support/solutions/articles/42000044793-telegraf-%EC%84%A4%EC%A0%95-%EA%B0%80%EC%9D%B4%EB%93%9C

## 20.08.03 (월)

\# sh ./ 차이
* https://ssaemo.tistory.com/43 : shell script 실행 방법 종류와 그 차이
* https://medium.com/humanscape-tech/%EB%A6%AC%EB%88%85%EC%8A%A4-%EC%89%98%EC%97%90%EC%84%9C-%EC%9E%90%EC%A3%BC-%EB%A7%8C%EB%82%98%EB%8A%94-%EC%83%81%ED%99%A9%EB%93%A4-a927615a1b96 : 자식 프로세스에서 설정된 환경변수는 부모 프로세스에서 사용할 수 없다.