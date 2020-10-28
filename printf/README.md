# printf

## 20.03.03

**Makefile**

> 현재는 libft를 포함하는 경우의 Makefile 작성도 어렵다. 일단 이분의 makefile을 참고 중. 왜냐하면 다른분들은 makefile에서 @를 앞에 쓴다거나, echo를 쓴다거나 하기 때문에 아직 잘 모르겠기 때문... 그런데 이분 Makefile이 꽤 마음에 든다. 문법을 배워서 내가 작성할 수 있는 수준은 아니지만, 어쨌거나 베껴써서 사용을 해보았는데 내가 원하는 폴더구조로 자료를 분리해놔서 마음에 들었다. 문법을 배워서 원하는대로 쓸 수 있도록 해보자.

**가변인자 함수**

> [코딩도장 1] [코딩도장 2] [참고]

**스텁(stub) 매개변수**

> [참고] 아마 이 내용은 공부 안해도 될 것 같다. 왜냐하면 외국분들의 코드를 보면 int ft_printf(const char *format, ...)으로 프로토타입을 지정해주었다. subject에는 int ft_printf(const char *, ...)이어야 한다고 나와있는데, 왜 저렇게 해도 상관없는지는 아직 모르겠다.

**형식지정자와 플래그**

> [모두의 코드] 몰랐던 것을 정리하면 다음과 같다.u : 부호가 없는 10진수 정수 형식지정자.x, X : 부호가 없는 16진수 소문자, 대문자 형식지정자.% : % 다음에 %을 또 써주면 stdout에 %를 출력한다.- : 필드에서 값을 왼쪽으로 정렬. (기본은 오른쪽)0 : 오른쪽 정렬일 때(-를 쓰지 않았을 때), 공백을 0으로 채운다.* : 폭. *는 정수로 입력한다..* : 정밀도. *는 정수로 입력한다.

## 20.03.04 - 20.03.06

계-속 코드 짰다. 매개변수가 많아져서 리스트들을 사용. 어렵다 어려워...

## 20.03.07

미뤄뒀던 유효성 검사를 대폭 수정하려 한다. 그리고 아마 처음에 연결리스트를 썼으면 좋았을 것 같지만... 나는 이미 해놓은게 있기때문에 일단 그냥 있던 코드를 수정하는 방향으로 해보자. 하다가 안되면 엎고 연결리스트를 써보려고 한다.

## 20.03.11

대충 완료 했다. 그런데 너무 비효율적으로 짜서, 다른 사람들과 코드 양이 두배는 차이가 나는 것 같다. 나중에 다시 할 기회가 있다면... 새로운 버전으로 짜보고 싶다.

---

## 20.04.08 (printf2 1일차)

- Makefile

    [http://doc.kldp.org/KoreanDoc/html/GNU-Make/GNU-Make-4.html](http://doc.kldp.org/KoreanDoc/html/GNU-Make/GNU-Make-4.html)

    이번 기회에 Makefile에 대해, sh에 대해 공부를 해보고싶다.

    [http://doc.kldp.org/KoreanDoc/html/gcc_and_make/gcc_and_make.html#toc3](http://doc.kldp.org/KoreanDoc/html/gcc_and_make/gcc_and_make.html#toc3)

    형식은 비슷하나 두개의 독립적인 문서인 듯?

- 📔 오류노트

    구조체 안에 또다른 구조체 포인터가 있는 경우. 구조체 포인터를 동적할당한 후, memset 0으로 초기화시켜버리면, 포인터를 잃어버리게 된다. 따라서 서순을 잘 지켜줘야!

    ```c
    typedef struct	s_info
    {
    	va_list	va;
    	int		  arg_num;
    	t_flag	*flag;
    }			          t_info;

    // 수정 전
    info = (t_info *)malloc(sizeof(t_info));
    if (!(info->flag = (t_flag *)malloc(sizeof(t_flag))))
    	return (0);
    ft_memset(info, 0, sizeof(t_info)); // 할당한 포인터를 잃어버린다!

    // 수정 후
    info = (t_info *)malloc(sizeof(t_info));
    ft_memset(info, 0, sizeof(t_info)); // 따라서 0 초기화를 먼저.
    if (!(info->flag = (t_flag *)malloc(sizeof(t_flag))))
    	return (0);
    ft_memset(info->flag, 0, sizeof(t_flag));
    // 내가 의도한대로 다 0으로 초기화해주려면 만든 후 다시 memset 해줘야함.
    ```

- 포인터 변수의 크기

    [https://m.blog.naver.com/123gtf/220905979083](https://m.blog.naver.com/123gtf/220905979083)

    64bit의 경우 8바이트로 동일하다.

- 연결리스트 free

    [https://yeobi27.tistory.com/entry/20130422연결리스트free기초](https://yeobi27.tistory.com/entry/20130422%EC%97%B0%EA%B2%B0%EB%A6%AC%EC%8A%A4%ED%8A%B8free%EA%B8%B0%EC%B4%88)

    [https://codevkr.tistory.com/50](https://codevkr.tistory.com/50)

## 20.04.09 (printf2 2일차)

- 📔 오류노트

    t_list 에서는 (void *)를 쓰기 때문에, 형변환을 해주어야 한다! 형식은 다음과 같이 해주면 된다.

    ```c
    t_list *curr;

    curr = info->flag;
    while (curr)
    {
    	// printf("[%c]\n", curr->content->spec; // 수정 전
    	printf("[%c]\n", ((t_cont *)curr->content)->spec);
    	curr = curr->next;
    }
    ```

- 값에 의한 참조, 주소에 의한 참조

    malloc이 되어있으면 그냥 줘도 되고, 아니면 주소를 줘야하는게 헷갈린다. 다음 두 함수에서 특히 헷갈린다.

    ```c
    static int ci_process(char **mover, t_info *info); // info를 그냥 주는 것이 헷갈림. (mover은 주소를 주는 반면.)
    int free_and_ret(t_info *info, int ret); // info를 그냥 주는 것이 헷갈림.
    ```

## 20.04.10 (printf2 3일차)

- 📔 오류노트

    `%` 도 하나의 spec으로 봐야한다. 왜냐하면 flag의 변환을 받기 때문.

## 20.04.11 (printf2 4일차)

- %p
    - arg를 unsigned int로 받던 것을 long long으로 바꿔주었다.
    - arg가 null인 경우, prec이 0이고 met_dot이 1이면 s_arg가 "" 되는 경우를 추가함.
- %c에 널문자 들어가는 경우

    ```c
    s_arg = (char *)malloc(2);
    if (arg != 0)
    	s_arg[0] = arg;
    s_arg[1] = '\0';
    ```

    이렇게 해주었는데, arg == 0 인 경우, 그러니까 널문자가 들어가는 경우에는 쓰레기값이 들어가야 할 것 같은데, 잘 안된다. 왜 쓰레기값이 안들어가지?

- *에 음수가 들어가는 경우

    width에 음수가 들어가면, - flag가 생긴다. prec에 음수가 들어가면 prec이 없는 것으로 처리된다.

- 주소에 의한 참조 주의점

    ```c
    while (i < (size_t)flag->prec - ft_strlen(s_arg))
    	(*str)[i++] = '0'; // 괄호!
    ```

    괄호를 항상 안해줘서 헤맨다. 괄호를 안해준 뜻이 뭔지 정확히 몰라서, 나는 괄호가 있는 경우로만 쓰기때문에 항상 괄호를 안해주는 것 같다. 괄호를 안해주면 무슨 뜻이 되는거지?
