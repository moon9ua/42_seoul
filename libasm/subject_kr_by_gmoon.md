# libasm

Assembly yourself!

요약: 이 프로젝트의 목표는 어셈블리 언어에 익숙해지는 것이다.

## 1. 개요

어셈블리 언어(약어로 asm)는 컴퓨터나 기계장치에 쓰이는 저수준 프로그래밍 언어이다. 어셈블리어는 (종종 일대일은 아니지만) 아키텍처의 기계 코드 구조와 매우 강력한 대응관계에 있다. 각 어셈블리어는 특정 컴퓨터 아키텍처에 따라 다르다. 이와 대조적으로, 대부분의 고수준 프로그래밍 언어들은 해석이나 컴파일을 요구하긴 하지만 일반적으로 여러 아키텍처에 걸쳐 이식이 가능하다. 어셈블리어는 심볼릭 머신 코드(symbolic machine code)라고도 불린다.

## 2. 일반 지침

- 함수가 정의되지 않은 행동으로 인해 갑자기 중단(segmeatation fault, bus error, double free, etc)되면 안된다.
- Makefile은 $(NAME), all, clean, fclean, re 규칙을 포함해야 한다. 리링크, 리컴파일은 필요한 파일만 해야한다.
- 보너스에 돌입하려면, Makefile에 bonus 룰을 포함해야 한다. 메인파트에서 금지된 다양한 헤더와 라이브러리, 함수를 추가할 수 있다. 보너스는 분리된 파일(_bonus.c, _bonus.h)로 저장되어야 한다.
- 평가에 반영되진 않지만, 테스트 프로그램을 만들 것을 권장한다.
- 64비트 ASM을 작성해야 한다. 호출 규약(calling convention)에 주의해라.
- 인라인 ASM은 할 수 없고, '.s' 파일만 가능하다.
- 어셈블리 코드는 nasm으로 컴파일되어야 한다.
- AT&T가 아니라, Intel 구문을 사용해야 한다.

## 3. 필수 파트

- 라이브러리는 libasm.a 여야 한다.
- 당신의 함수를 테스트하고 라이브러리와 함께 컴파일해서 작동하는 것을 보여줄 메인문을 제출해야 한다. (You must submit a main that will test your functions and that will compile with your library to show that it’s functional.)
- 다음의 함수들을 asm으로 재작성해라.
    - ft_strlen (man 3 strlen)
    - ft_strcpy (man 3 strcpy)
    - ft_strcmp (man 3 strcmp)
    - ft_write (man 2 write)
    - ft_read (man 2 read)
    - ft_strdup (man 3 strdup, you can call to malloc)

## 4. 보너스 파트

다음의 함수들을 asm으로 재작성할 수 있다. 연결리스트 함수는 다음과 같은 구조체를 사용한다.

    typedef struct s_list
    {
    	void *data;
    	t_list *next;
    }              t_list;

- ft_atoi_base (like the one in the piscine)
- ft_list_push_front (like the one in the piscine)
- ft_list_size (like the one in the piscine)
- ft_list_sort (like the one in the piscine)
- ft_list_remove_if (like the one in the piscine)