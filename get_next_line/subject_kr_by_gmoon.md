# get_next_line

## Chapter 1. 목표

유용한 함수를 배울 수 있다. 정적(static) 변수에 대해 배울 수 있다.

## Chapter 2. 일반 지침

* norm 규정을 지켜라. bonus 함수 또한 마찬가지.
* 함수가 정의되지 않은 행동을 하거나 예기치 않게 중단(segmentation fault, bus error, double free, etc)되어서는 안된다.
* 힙의 메모리는 꼭 적절히 free되어야 한다. leak은 허용되지 않는다.
* makefile을 요구할 경우, makefile은 -Wall -Wextra -Werror 플래그로 쓰여야 하며 $(NAME), all, clean, fclean, re 규칙을 포함해야 한다.
* bonus 함수를 추가한 경우, makefile에 bonus 룰을 추가해야 한다. 여기엔 메인 파트에서 금지되었었던 다양한 헤더와 라이브러리가 추가될 것이다. bonus 파일들은 _bonus.{c/h}로 만들어져야 한다. 메인 파트와 bonus 파트는 분리되어 평가될 것이다.
* libft 사용이 허락된 경우, source들과 makefile을 libft 폴더 안에 복사해라.<br>
* 평가는 하지 않겠지만 테스트 프로그램을 만들 것을 권장한다. 
* git 저장소의 작업물만 평가된다.

## Chapter 3. Mandatory part

| 함수명        | get_next_line                                                |
| ------------- | ------------------------------------------------------------ |
| 프로토타입    | int get_next_line(int fd, char **line);                      |
| Turn in files | get_next_line.c, get_next_line_utils.c, get_next_line.h      |
| 매개변수      | \#1. file descriptor for reading<br>#2. The value of what has been read |
| 반환값        | 1 : A line has been read<br>0 : EOF has been reached<br>-1 : An error happened |
| 허용 함수     | read, malloc, free                                           |
| 설명          | Write a function which returns a line read from a file descriptor, without the newline. |

* 루프에서 get_next_line 함수를 사용하면, 파일 디스크립터의 텍스트를 EOF 전까지 한 줄씩 읽을 것이다.
* 함수가 잘 작동하는지 확인: 파일을 읽을 때, 표준 입력을 읽을 때.
* libft는 이 프로젝트에서 허용되지 않는다. 대신 get_next_line_utils.c 파일을 추가해야 한다. 이 파일은 get_next_line을 위해 필요한 함수들을 포함한다.
* 플래그 -D BUFFER_SIZE=xx 로 컴파일해야 한다. 이는 get_next_line에서 읽기 호출의 버퍼 사이즈에 사용될 것이다. 이 값은 평가자와 moulinette에 의해 수정된다.
* 컴파일은 다음과 같이 수행: gcc -Wall -Wextra -Werror -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
* read 함수는 파일이나 표준 입력을 읽기 위해 BUFFER_SIZE를 이용해야 한다.
* 헤더 파일 get_next_lint.h에는 최소 get_next_line의 프로토타입은 있어야 한다.<br>
* :loudspeaker:  함수가 BUFFER_SIZE = 9999 일때도 작동하는가? BUFFER_SIZE = 1 일때도 작동하는가? 10000000일때도? 왜인지 아는가?
* :loudspeaker: 함수가 호출될 때 가능한 적은 횟수로 읽어야 한다. 만약 새로운 line을 만나면, 현재 라인을 return해야 한다. 전체 파일을 읽지 말고, 각 행을 처리해라.<br>
* :loudspeaker: 테스트 없이 프로젝트를 제출하지 마라. 파일에서, redirection에서, 표준 입력에서 읽어보아라. 표준 출력에 새 line을 보낼 때, 프로그램이 어떻게 작동하는가? ctrl-d를 보내면 어떻게 되는가?
* 다음 경우에 정의되지 않은 행동 하는 것을 주의: (두 번의 호출 사이에) 같은 파일 디스크립터가 첫 번째 fd에 도달하기 전에 다른 파일로 전환될 경우.<br>
* lseek 함수는 허용되지 않는다. 파일 읽기는 단 한번에 수행되어야 한다.
* 다음 경우에 정의되지 않은 행동 하는 것을 주의: binary 파일을 읽을 경우. 그러나 당신이 원한다면, 당신은 이 행동을 coherent하게 만들 수 있다.<br>(Finally we consider that get_next_line has an undefined behavior when reading from a binary file. However, if you wish, you can make this behavior coherent.)
* 전역 변수는 금지.
* :mega: static 변수에 대해 알고 싶으면 [[참고]](https://en.wikipedia.org/wiki/Static_variable)

## Chapter 4. Bonus part

이 프로젝트는 간단하므로 보너스를 받을 여지가 거의 없지만, 나는 네가 상상력이 풍부할 것이라 확신한다. 만약 당신이 필수 파트를 완벽히 수행했다면, 이 보너스 파트를 시도해라. 반복한다, 필수 파트가 완벽하지 않으면 보너스는 소용 없다. 보너스를 위해 3개의 _bonus 파일을 추가해라. 

* 단 하나의 static 변수로 get_next_line을 성공시켜라.
* 여러 파일 디스크립터를 관리할 수 있도록 해라. 예를 들어, 파일 디스크립터 3, 4, 5가 읽기 가능하다면, get_next_line을 3에 한번, 4에 한번, 다시 3에 한번, 5에 한번 등등 호출할 수 있다. 각각의 파일 디스크립터에 대한 읽기를 잃지 않고 말이다. <br>