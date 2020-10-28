# minishell

요약: 이 프로젝트의 목적은 간단한 shell을 만들어보는 것이다. 맞다, 당신만의 작은 shell, zsh이다. 당신은 프로세스들과 파일디스크립터들에 대한 많은걸 배울 것이다.

## 1. 개요

shell의 존재는 IT의 존재와 밀접한 관련이 있다. 당시 모든 코더들은 0, 1 스위치를 사용해서 컴퓨터와 통신하는 것이 매우 짜증난다고 생각했다. 따라서 영어와 비슷한 언어로 대화형 명령 줄을 사용해서 컴퓨터와 통신한다는 아이디어를 생각하게 된 것은 자연스러운 일이었다. minishell을 통해 당신은 사람들이 windows가 없었을 때 직면했던 문제를 체험해볼 수 있을 것이다.

## 2. 일반 지침

- 프로젝트는 norm을 지켜서 쓰여야 한다.
- 예기치않게 중단되면 안된다.
- 메모리는 다 해제되어야 한다.
- makefile은 -Wall -Wextra -Werror 플래그들로 컴파일해야하며, 리링크돼선 안된다.
- $(NAME), all, clean, fclean, re 규칙을 포함해야 한다.
- 보너스를 한다면 makefile에 bonus 규칙을 추가해라. 파일은 _bonus.c나 _bonus.h로 구분되어야 한다.
- libft가 허용된다면 makefile까지 libft 폴더에 넣어야 한다. 프로젝트의 makefile은 libft의 makefile을 이용해서 컴파일한 후, 프로젝트를 컴파일할 것이다.
- 테스트 프로그램 작성을 추천한다.
- 깃 레포지토리의 것만 평가된다.

## 3. 필수 파트

    프로그램명: minishell
    makefile: O
    허용 함수: malloc, free, write, open, read, close, fork, wait,
    					waitpid, wait3, wait4, signal, kill, exit, getcwd,
    					chdir, stat, lstat, fstat, execve, dup, dup2, pipe,
    					opendir, readdir, closedir, strerror, errno
    libft: O
    설명: 쉘을 작성하라.

당신의 shell은 다음을 지켜야 한다.

- 새로운 명령을 기다리는 동안 프롬프트를 보여줘야 한다.
- bash에서와 같이 올바른 실행 파일을 검색하고 실행해라. (PATH 변수 기반 혹은 상대, 절대 경로 이용)
- bash와 같이 빌트인을 구현해야 한다.
    - `echo`와 옵션 `-n`
    - `cd`와 상대 혹은 절대 경로
    - 옵션 없는 `pwd`
    - 옵션 없는 `export`
    - 옵션 없는 `unset`
    - 옵션과 인자 없는 `env`
    - 옵션 없는 `exit`
- 명령에 `;`가 있으면 명령을 분리해야 한다.
- `'`과 `"`는 다중 명령을 제외하고 bash처럼 작동해야 한다.
- 리다이렉션 `<`, `>`, `>>`는 파일 디스크립터 집합(aggregation)을 제외하고 bash처럼 작동해야 한다.
- 파이프 `|`는 bash처럼 작동해야 한다.
- 환경 변수(`$`)들은 bash처럼 작동해야 한다.
- `$?` 은 bash처럼 작동해야 한다.
- `ctrl-C` , `ctrl-D` , `ctrl-\` 은 bash처럼 작동해야 한다.

## 4. 보너스 파트

- 필수 파트가 완벽하지 않다면 보너스는 생각도 하지 마라.
- 모든 보너스를 할 필요는 없다.
- 리다이렉션 `<<` 은 bash처럼 작동해야 한다.
- Termcaps를 통한 히스토리와 라인 수정 (man tgetent)
    - 커서가 위치한 곳의 라인을 수정한다.
    - Move the cursor left and right to be able to edit the line at a specific location. Obviously new characters have to be inserted between the existing ones similarly to a classic shell.
    - Use up and down arrows to navigate through the command history which we will then be able to edit if we feel like it (the line, not the history).
    - Cut, copy, and/or paste all or part of a line using the key sequence you prefer.
    - Move directly by word towards the left or the right using ctrl+LEFT and ctrl+RIGHT.
    - Go directly to the beginning or the end of a line by pressing home and end.
    - Write AND edit a command over a few lines. In that case, we would love that ctrl+UP and ctrl+DOWN allow to go from one line to another in the command while remaining in the same column or otherwise the most appropriate column.
- &&, || with parenthesis for priorities, like in bash
- wilcard * like in bash