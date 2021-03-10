# exam_04 subject

* 과제명: microshell
* 제출 파일: *.c *.h
* 허용 함수: malloc, free, write, close, fork, waitpid, signal, kill, exit, chdir, execve, dup, dup2, pipe, strcmp, strncmp

다음과 같이 작동하는 프로그램을 작성하세요.
* 실행할 커맨드 라인은 프로그램의 인자가 됩니다.
* 실행 파일의 경로는 절대 또는 상대 경로이지만 당신의 프로그램이 path를 빌드해서는 안됩니다. (예: PATH 변수에서)
* bash처럼 "|"와 ";"를 구현해야 합니다.
    * "|"의 바로 앞이나 뒤에 아무것도 오지 않거나 "|"나 ";"가 올 경우, 시도하지 않습니다.
* 당신의 프로그램은 path를 인자로만 기본 명령 cd를 구현해야 합니다. ('-'나 인자가 없는 경우는 제외.)
    * 인자 수가 잘못된 경우, STDERR에 "error: cd: bad arguments\n"를 출력합니다.
    * cd가 실패할 경우, STDERR에 "error: cd: cannot change directory to path_to_change\n"를 출력합니다. path_to_change는 인자로 대체하세요.
    * cd 명령은 "|"의 바로 앞이나 뒤에 올 수 없습니다.
* 와일드카드는 관리할 필요가 없습니다. (*, ~ ...)
* 환경 변수는 관리할 필요가 없습니다. ($BLA ...)
* 만약 execve와 chdir을 제외한 시스템콜이 오류를 반환할 경우, 바로 STDERR에 "error: fatal\n"을 출력하고 프로그램을 종료해야 합니다.
* 만약 execve가 실패할 경우, STDERR에 "error: cannot execute executable_that_failed\n"을 출력해야 합니다. executable_that_failed은 실패한 실행파일의 경로로 대체하세요(execve의 첫번째 인자여야 합니다)
* 열린 파일의 수를 30개 이하로 제한할 것이지만, 수백개 이상의 "|"을 관리할 수 있어야 합니다.

예를 들어 다음과 같이 작동합니다:
```
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>
```
* 힌트
    * execve에 환경 변수를 전달하는 것을 잊지 마세요.
    * 파일 디스크립터를 누수하지 마세요!