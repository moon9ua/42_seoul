# exam_04

### C 환경변수
* https://ehpub.co.kr/%EB%A6%AC%EB%88%85%EC%8A%A4-%EC%8B%9C%EC%8A%A4%ED%85%9C-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D-7-3-%ED%99%98%EA%B2%BD-%EB%B3%80%EC%88%98-getenv-putenv-%ED%95%A8%EC%88%98/
    > `int main(int argc, char **argv, char** envp);`
* http://mwultong.blogspot.com/2007/01/c-vc-get-print-environment-variable.html
* https://m.blog.naver.com/PostView.nhn?blogId=tipsware&logNo=221249315544&proxyReferer=https:%2F%2Fwww.google.com%2F

### null 포인터를 free하면?
* https://krids.tistory.com/150
    > free가 작동하지 않으므로 null인지 검사하지 않아도 된다.  
    > free 후 null로 초기화해주면 어디선가 또 free를 해도 문제가 없다.  

### argv에 대하여
`./a.out "test""test"`는 "./a.out", "testtest" 두 인자로 인식된다.  
`./a.out "test "test"`는 "./a.out", "test", "test" 세 인자로 인식된다.  

### chdir
* https://velog.io/@springkim/C-chdir-chdir-SetCurrentDirectory
    > 상대경로를 인식한다는데, 왜 안되지?

### execve
* https://www.it-note.kr/157

### pipe
* https://reakwon.tistory.com/80
* https://smeffect.tistory.com/entry/05-pipe-%ED%8C%8C%EC%9D%B4%ED%94%84
* https://gist.github.com/iomonad/a66f6e9cfb935dc12c0244c1e48db5c8

### dup, dup2
* https://ehclub.co.kr/1321
* https://reakwon.tistory.com/104

### && 연산자에서 모든 명령을 실행할까?
* https://blankspace-dev.tistory.com/310
    > 앞 조건이 false이면 이후 조건은 실행하지 않는다.
