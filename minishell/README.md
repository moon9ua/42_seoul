
# :pineapple: PINE APPLE SHELL

***minishell by [gmoon](https://github.com/moon9ua) and [sanam](https://github.com/simian114).***<br>
***@ 42 Seoul***

![GIF](GIF.gif)

---

공부한 기록은 [노션](https://www.notion.so/minishell-d7163467fb3b441f98b972b18e1447b8)으로.<br>
내가 보려고 만든 서브젝트 번역본은 [여기](https://github.com/moon9ua/42_seoul/blob/master/minishell/subject_kr_by_gmoon.md)로.

### 참고자료

\# redirection
* http://www.sarathlakshman.com/2012/09/24/implementation-overview-of-redirection-and-pipe-operators-in-shell

\# pipe
* https://gist.github.com/iomonad/a66f6e9cfb935dc12c0244c1e48db5c8
* https://github.com/LambdaSchool/CS-Wiki/wiki/How-Unix-Pipes-are-Implemented

\# escape 문자
* https://unix.stackexchange.com/questions/390148/escaping-in-double-quotes-in-bash-scripts

그 외
* https://brennan.io/2015/01/16/write-a-shell-in-c/
: 당시에는 참고하지 않았지만 읽어볼만한 글.

### 개선할 점

* minishell에서 환경변수를 수정 후 다른 프로그램을 실행시키면, 수정된 환경변수가 아닌 원본 환경변수가 전달되는 문제점이 있다. 이는 환경변수를 다루는 함수를 만들 때, 복사본(연결리스트로 구현함)을 수정하게 만들었기 때문.

* 리다이렉션이 여러 번 수행되는 경우를 고려하지 못했다! 예를 들어 `echo a > b > c`... 이럴 수가!
