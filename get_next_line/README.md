# get_next_line

## 20.02.29

- BUFFER_SIZE는 따로 define이나 선언을 안해줘도 된다.
- gcc -D BUFFER_SIZE=10 get_next_line.c get_next_line_utils.c
컴파일은 이런 식으로.
- static 변수를 쓰는 법을 몰라서 헤맸다. 정적변수는 전역변수가 아닌 이상 선언한 함수 내부에서만 쓸 수 있는 것 같다. 그것도 모르고 다른 함수에서 쓰려고 한다거나, static을 쓴 채 매개변수로 주려고 해서 오래 걸렸다. [[위키백과(ko)]](https://ko.wikipedia.org/wiki/%EC%A0%95%EC%A0%81_%EB%B3%80%EC%88%98)
- `ft_cut(buf)`을 하고 `printf("%s\n", ft_cut(buf))`를 하면 어쩔 때는 출력이 되고, 어쩔 때는 안된다. 이거 왜 이런 것일까..? `printf("[%s]\n", ft_cut(buf))`를 하면 심지어 '']moongua test'' 이런 식으로 나온다. 전혀 모르겠다...
- [[파일 디스크립터]](https://dev-ahn.tistory.com/m/96) 파일 디스크립터는 고정된 값.
- 엄청난 것을 배웠다! 어제 "]moongua test"로 나왔던 이유가 바로 CR(캐리지 리턴) 때문이었던 것 같다. [[캐리지 리턴, 라인 피드]](https://jink1982.tistory.com/122)

    ```
    // 파일 디스크립터와 read 함수 공부int main(){    // test.txt의 내용    // first line\n    // second line    int fd;    char buf[5];    fd = open("test.txt", O_RDONLY);    printf("%d\n", fd);    printf("========\n");        read(fd, buf, sizeof(buf));    printf("%d\n", fd); // fd는 고정이라 같음.    printf("[%s]\n", buf); // 결과: [first]    printf("========\n");    read(fd, buf, sizeof(buf));    printf("[%s]\n", buf); // 결과: [ line]    printf("========\n");    read(fd, buf, sizeof(buf));    printf("[%s]\n", buf);    printf("[%d] [%d] [%d]\n", buf[0], buf[1] , buf[2]);    // 엔터가 null문자로 들어가나? 왜 buf에 4개밖에 안들어갔지? 는 해결!    // 결과: buf[0]:CR(캐리지 리턴) buf[1]:LF(개행, 라인피드) buf[2]:s    printf("ft_strlen test: %ld\n", ft_strlen(buf));    // 널문자가 안들어갔을거라 생각했는데 잘 작동한다. 잘 모르겠음.}
    ```

    굉장한 사실은, 위에서는 test.txt를 윈도우 환경에서 작성해서 CR이 들어간 것이고, 우분투를 통해 `vi test.txt`를 해주면 CR이 들어가지 않는다. 그냥 공부한 셈 치고 CR이 없는 상태로 다시 프로젝트를 진행하면 되겠다.

- read 함수의 반환 값은 읽기에 성공한 글자 수(바이트라고 해야하나?)이다. 그런데 test.txt의 내용보다 큰 수를, 예를 들어 BUFFER_SIZE = 100을 주면 read 함수의 반환 값은 28이 된다. 이 것은 개행문자와 글자수를 모두 더한 값에 +1 한 값이다. +1 된 값은 아마 파일의 마지막을 나타내는... 널문자, 혹은 어떠한 문자의 개수가 함께 카운트 된 것일까? 모르겠다.

    ```
    int a = read(fd, buf, BUFFER_SIZE);printf("%d\n", a);// BUFFER_SIZE = 3 이고 세 글자 모두 들어왔으면, 출력은 3.// BUFFER_SIZE = 100 이고 test.txt가 개행까지 27글자면, 출력은 28.// 아마 test.txt의 마지막에 무언가가 함께 세져서 28인 것?
    ```

    ```
    // test.txt: 012345int a = read(fd, buf, BUFFER_SIZE);printf("1. %d [%s]\n", a, buf); // 출력: 3 [012]a = read(fd, buf, BUFFER_SIZE);printf("2. %d [%s]\n", a, buf); // 출력: 3 [345]a = read(fd, buf, BUFFER_SIZE);printf("3. %d [%s]\n", a, buf); // 출력: 2 [6\n5]// read 반환값이 2라는 것을 이용해야겠다. buf에 5가 출력된 것은 아마 쓰레기값이 아닐까..?a = read(fd, buf, BUFFER_SIZE);printf("4. %d [%s]\n", a, buf); // 출력: 0 [6\n5]// read 반환값은 -1이 아니라 0이었다. 읽은 수니까... 반복문을 수정할 수 있겠다.
    ```

- get_next_line의 매개변수 line이 왜 이중포인터인지 모르겠다. 다중 포인터에 대한 공부 필요.
- static 변수를 왜 쓰는지 이해했음. buf의 내용을 유지하기 위해서 get_next_line에서 정적 변수로 정의해준 것.

## 20.03.01

- get_next_line의 매개변수 line은 왜 이중포인터인지의 고찰.
대충 말하자면 **일중포인터는 그 안의 값을 바꾼 채로 다시 돌아올 수 없지만, 이중포인터는 가능하다**는 내용. **값에 의한 호출과 참조에 의한 호출**이 이와 관련된 내용인 듯. [[참고]](https://programist.tistory.com/m/entry/C-%EC%96%B8%EC%96%B4-Call-by-Value%EA%B0%92%EC%97%90-%EC%9D%98%ED%95%9C-%ED%98%B8%EC%B6%9C-Call-by-Reference%EC%B0%B8%EC%A1%B0%EC%97%90-%EC%9D%98%ED%95%9C-%ED%98%B8%EC%B6%9C%EC%9D%98-%EC%9D%B4%ED%95%B4)
- get_next_line에서 내가 구현한 알고리즘이 **자료구조 '큐'** 알고리즘과 유사하다고 한다.
- []과 [(null)]의 차이:

    ```
    // 다른분 결과[0123456] 1[secondline] 1[hello] 1[] 0[] 0// 내 결과[0123456] 1[secondline] 1                                                         [hello] 1[(null)] 0[(null)] 0
    ```

    []은 ***line이 '\0'을 가르키고 있는 것**이고, [(null)]은 ***line이 0을 가르키고 있는 것**이다. (**정확한 개념과 용어공부 필요!!!** 틀린 말같은데... 일단 느낌만 알았다.) 따라서 []을 구현하기 위해 다음과 같이 수정하였다.

    ```c
    if (read_len == 0){    *line = ft_strdup(buf, read_len);    return 0;}
    ```

- 예전부터 궁금했었던, buf에는 '\0'이 없을 것 같은데 ft_strlen(buf)가 제대로 동작하는 문제를 보완하였다. read_len을 매개변수로 줘서 그 이상 읽는 것을 방지하였다. (안해줘도 내가 테스트한 경우에서는 strlen이 잘 작동하긴 했다. 왜 잘 작동했는지는 공부 필요할 듯.) 따라서 ft_strdup 함수에도 read_len을 매개변수로 추가하였는데, 이 경우 read_len은 0이므로 *line에는 1칸짜리 '\0'만 들어있는 배열이 malloc되게 된다.
- -1을 리턴하는 경우:
`if (fd < 0 || line == NULL || BUFFER_SIZE < 1)`인 경우와, `if (!(buf = (char *)malloc(BUFFER_SIZE)))`인 경우, 그리고 마지막에 return (-1)을 추가하였다.
- 메모리 누수:
메모리 누수는 **valgrind**와 **-fsanitize=address** 옵션을 이용하여 검사하였다.
valgrind는 `sudo apt update`과 `sudo apt install valgrind`를 통해서 valgrind를 설치하였다. 사용은 `valgrind --leak-check=full ./a.out` 로, 이 때 **컴파일에 -g 옵션을 붙여주면, 오류가 나는 줄 수가 함께 보인다.** [[메모리 누수 종류]](https://m.blog.naver.com/PostView.nhn?blogId=mura482&logNo=220254775970&proxyReferer=https%3A%2F%2Fwww.google.com%2F) [[메모리 누수 종류(공식)]](http://valgrind.org/docs/manual/mc-manual.html)
우선은 다음의 경우에 free를 해주어 누수를 해결하였다.
    - ft_strjoin, ft_strjoin_until_lf 함수에서 s1(line을 의미)을 free.
    - get_next_line 함수에서 read_len이 0일때 buf를 free.

    이 외에도 여러 테스트 케이스를 통해 검사해보면, free가 더 필요할 수도 있다.

- 일단은 아주 대충 돌아가게 해놓은 상태인데, 뭔가 마지막 줄이 잘 해결이 안된 것 같다. 내일 일어나서 해보자!

## 20.03.02

- 마지막 줄에 개행이 없는 경우를 처리하였다.

    ```c
    // 알파벳[65번째 줄]MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm[66번째 줄]NNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNNn // ret: 1[67번째 줄] // ret: 0// 심슨[13번째 줄]     oooooooo[14번째 줄]    /        \ // ret: 0
    ```

    정확히는 모르겠지만... 아마 마지막 줄을 읽으면, 그러니까 eof가 있는 줄을 읽으면 0을 리턴한다. 마지막 줄에 개행이 들어갔던 것은 내가 실수로 저장했었거나, 환경에서 자동으로 개행을 추가했기 때문일 것이다. 어쨌거나 **마지막 줄에 개행이 없으면, 그 줄의 리턴값은 0이다.**

- **표준 입력과 리다이렉션** 검사는 다음과 같이 진행해보았다.

    ```c
    int main(void){    char *line = 0;    int ret;    int fd;    while ((ret = get_next_line(0, &line)) > 0)    {        printf("%s\n", line);        free(line);    }    free(line);    return (0);}
    ```

    맞는지는 모르겠으나 일단 대충 돌아간다. ctrl+d 를 만났을 때도 음... 그때는 그냥 중단되긴 하는데 뭐가 맞는지를 모르겠다.

- 보너스 파트도 남았지만 시도할 마음은 아직...

## 20.03.03

- 다음 경우에 정의되지 않은 행동 하는 것을 주의: binary 파일을 읽을 경우. 그러나 당신이 원한다면, 당신은 이 행동을 coherent하게 만들 수 있다.

    binary file 테스트는 ./a.out < /dev/random로.
    나는 애초에 '\0' 문자를 신경쓰지 않고(memory 단위로?) 함수를 구현하였기에, binary file에서도 segmantation faulf가 뜨지 않고 일관되게 동작하였다.

- **binary 파일이 무엇인지, /dev/random, 스트링단위와 메모리단위의 차이점, '\0'는 언제 생성되는지** 등에 대해 개념정리 필요.

## 20.03.05

- 다음 경우에 정의되지 않은 행동 하는 것을 주의: (두 번의 호출 사이에) 같은 파일 디스크립터가 첫 번째 EOF에 도달하기 전에 다른 파일로 전환될 경우.

    ```c
    // 무슨 말인지 이해를 못했었는데, 다음과 같이 테스트하면 될 것 같다.
    int main(void)
    {
    	char *line = 0;
    	int ret;
    	int fd;
    	fd = open("files/alphabet", O_RDONLY);
    	ret = get_next_line(fd, &line);
    	printf("%s\n", line);
    	free(line);
    	ret = get_next_line(fd, &line);
    	printf("%s\n", line);
    	free(line);
    	fd = open("files/empty_lines", O_RDONLY);
    	ret = get_next_line(fd, &line);
    	printf("%s\n", line);
    	free(line);
    }
    ```

- GNL_lover은 통과하는데, 그 외에 gnlkiller나 42TESTERS-GNL에서는 통과못함.

    gnlkiller원래 코드로 검사하면, Segmemtation fault가 뜸. 원인은 double-free라고 뜸.  free(buf); 후에 buf = 0;을 추가하면 Seg fault는 안뜨는데, KO가 뜨게됨.

    42TESTERS-GNL원래 코드로 검사하면, Seg fault가 뜸. 원인은 Use-After-Free라고 뜸. [예제를 통해 알아보는 Use-After-Free 발생 원인] [해킹-Use After Free] 마찬가지로 buf = 0;을 추가하면 Seg fault는 안뜨는데, KO가 뜸.

- 원인은 read 반환값이 -1일 때의 예외 처리를 안해줘서였다. 따라서 gnl 함수의 리턴값을 `return(read_len);`로 수정해주었다.

    원래 나는 fd < 0인 경우만 오류처리를 해주었었다. 따라서 다음과 같은 경우가 문제가 되었다. 예를 들어 fd = 180으로 테스트를 하면(42TESTERS-GNL이 이렇게 했다) fd < 0이 아니라 나는 gnl이 0을 리턴하였다. 하지만 fd = 180일 때, read를 실패하면 read 함수는 -1을 반환한다. 이 때 gnl은 -1을 리턴해야 하는 것이다. 따라서 이 예외처리를 추가하였다.

- 참조에 의한 호출

    ```c
    // 줄 수를 줄이기 위해, free(buf); buf = 0;을 다른 함수로 빼주었다. 함수는 다음과 같다.
    void free_and_null(char **buf)
    {
    	free(*buf);
    	*buf = 0;
    	return ;
    }
    // 이 때, buf를 일중포인터로 받아오니까 잘 실행이 안되었다. 완벽한 개념은 익히지 못했지만, 어쨌거나 이중포인터로 받아와서 성공하였다. 함수 사용은 free_and_null(&buf);로 한다.
    ```

- 보너스가 이해가 안됐었는데, 이제 알 것 같다.

    ```c
    int main(void)
    {
    	char *line = 0;
    	int ret;
    	int fd1;
    	int fd2;
    	fd1 = open("files/alphabet", O_RDONLY);
    	ret = get_next_line(fd1, &line);
    	printf("%s\n", line);
    	free(line);
    	ret = get_next_line(fd1, &line);
    	printf("%s\n", line);
    	free(line);

    	fd2 = open("files/empty_lines", O_RDONLY);
    	ret = get_next_line(fd2, &line);
    	printf("%s\n", line);
    	free(line);

    	fd1 = open("files/alphabet", O_RDONLY);
    	ret = get_next_line(fd1, &line);
    	printf("%s\n", line); // 보너스 안해서, "AAA..." 출력됨.
    	free(line);
    }
    // 보너스에선 맨 아래가 "AAA..."가 아니라, "CCC..."로 나오게 하라는 내용같다.
    ```

---

## 새로 짜보는 gnl

- 포인터 배열

    [https://blockdmask.tistory.com/56](https://blockdmask.tistory.com/56)

- 틀렸던 부분

    ```c
    // 고치기 전. 출력해보면 [(null)]로 나오는 듯.
    *line = 0;
    // 고친 후. 출력해보면 []로 나오는 듯.
    if (!(*line = (char *)malloc(1)))
    		return (-1);
    	**line = '\0';
    ```

    ```c
    if (ret < 0)
    {
    	free(*line);
    	*line = 0; // 댕글링 포인터 방지해줘야.
    	return (-1);
    }
    free(*buf);
    *buf = 0;
    return (0);
    ```

- 헷갈리는 부분

    ```c
    static void	pull_buf(char *buf)
    {
    	gnl_memmove(buf,
    				buf + strlen_lf(buf) + 1,
    				gnl_strlen(buf) - strlen_lf(buf));
    }
    // pull_buf를 꼭 해줘야하는지. 처음에 이렇게 해서 계속 고수하고 있긴 한데...
    // 길이가 헷갈린다. 위치도 헷갈리지만 길이는 특히나.
    ```

- 틀렸던 부분들과 헷갈리는 부분들이 있어, 다시 해보면 아직 공부가 될 것 같다. 방식에 있어서는 더 나은 방식이 있는지 찾고 싶은데... 코드 읽는 것이 느리고, 평가가 활발히 이루어지지 않아 어려우려나?