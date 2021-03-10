# philosophers

## 식사하는 철학자
* https://namu.wiki/w/%EC%8B%9D%EC%82%AC%ED%95%98%EB%8A%94%20%EC%B2%A0%ED%95%99%EC%9E%90%20%EB%AC%B8%EC%A0%9C
* https://www.hanbit.co.kr/media/channel/view.html?cms_code=CMS2554000338&cate_cd=001
* https://github.com/tyrue/3th_Operating-System
* https://simsimjae.tistory.com/72
* https://m.blog.naver.com/hirit808/221788147057
* https://blog.naver.com/hirit808/221790851401
* https://has3ong.github.io/dining-philosopher/

## 스레드와 프로세스
* https://gmlwjd9405.github.io/2018/09/14/process-vs-thread.html
* https://brunch.co.kr/@kd4/3
* https://www.crocus.co.kr/481?category=204622
* https://www.crocus.co.kr/482?category=204622

## 메모리 영역(code, data, stack, heap)
* https://sfixer.tistory.com/entry/%EB%A9%94%EB%AA%A8%EB%A6%AC-%EC%98%81%EC%97%ADcode-data-stack-heap

## 뮤텍스와 세마포어
* https://velog.io/@conatuseus/OS-%EC%84%B8%EB%A7%88%ED%8F%AC%EC%96%B4%EC%99%80-%EB%AE%A4%ED%85%8D%EC%8A%A4
* https://jwprogramming.tistory.com/13
* https://worthpreading.tistory.com/90
* https://loginfo.dev/Semaphore-and-Mutex
* https://dduddublog.tistory.com/25

## 시간 관련 함수

* `void usleep(unsigned long useconds);`
    * 헤더: `<unistd.h>`
    * 매개변수 `useconds`: 마이크로초만큼 대기. (마이크로초는 1/1000000초, 밀리초는 1/1000초.)

* `int gettimeofday(struct timeval *tv, struct timezone *tz);`
    * 현재 시간을 가져온다.
    * 헤더: `<sys/time.h>`
    * 반환값: 성공시 1, 실패시 -1.
    * 두번째 인자에는 NULL을 넣으면 된다고 한다.

<details>
<summary>코드</summary>

```c
#include <sys/time.h> // gettimeofday()
#include <unistd.h> // usleep()

int main()
{
    struct timeval start_time;
    struct timeval now_time;

    gettimeofday(&start_time, NULL);
    while (1)
    {
        gettimeofday(&now_time, NULL);
        printf("1초마다 출력! %ld\n",
                (now_time.tv_sec - start_time.tv_sec));
        usleep(1000 * 1000);
    }
}
```

</details>

## 스레드 함수

> * https://www.crocus.co.kr/484
> * https://www.crocus.co.kr/482?category=204622
> * https://bitsoul.tistory.com/160
> * https://reakwon.tistory.com/56

* `int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);`  
    * 새로운 스레드를 생성한다.  
    * 매개변수 `thread`: 새로운 스레드의 ID가 이 변수에 저장된다.
    * 매개변수 `attr`: 스레드의 특성을 정의하기 위해 사용하는데, 보통 NULL을 준다.
    * 매개변수 `start_routine`: 스레드가 실행하는 함수 포인터.
    * 매개변수 `arg`: 스레드 함수로 넘어가는 매개변수.
    * 반환값: 성공시 0.  
    * create만 하면 자원(메모리)를 회수하지 않으므로, join이나 detach를 써주어야 함.

* `int pthread_join(pthread_t thread, void **retval);`  
    * 다른 스레드가 종료되는걸 기다린다.  
    * 메인 스레드가 종료되면 자식 스레드까지 종료되므로, 자식 스레드가 수행되기 전에 종료될 수 있다. 따라서 이 함수를 사용해서 자식 스레드의 종료까지 대기하는 것.  
    * 즉, 자식 스레드가 끝이 나면, 부모 스레드가 움직인다.  
    * 결과 값에 관심이 있을 때, 리턴 값을 받고 자원을 반환시킴.
    * 매개변수 `thread`: 기다릴 스레드의 ID.
    * 매개변수 `retval`: 스레드의 리턴값을 받을 곳.

* `int pthread_detach(pthread_t th);`  
    * 실행중인 스레드를 분리(detach) 상태로 만든다.  
    * join으로 기다리지 않고, 독립적으로 동작하기를 원할 때 사용.  
    * 결과 값에 관심이 없을 때, 스레드가 끝나면 알아서 자원을 반환하도록 함.  
    * 매개변수 `th`: 분리시킬 스레드의 ID.

<details>
<summary>코드</summary>

```c
#include <pthread.h> // 컴파일시 clang(gcc) -pthread 옵션을 붙여줘야.
    
void* thread_fuction(void* data)
{
    *(int*)data += 10; // 전달받은 포인터가 가르키는 값 변경.

    printf("자식 스레드: %d\n", *(*int)data);
    return (NULL);
}

int main()
{
    pthread_t threadID;
    int data = 1;

    printf("스레드 생성\n");
    pthread_create(&threadID, NULL, thread_fuction, (void*)&data); // 성공하면 0 리턴.

    printf("메인 스레드가 자식 스레드를 기다립니다.\n");
    pthread_join(threadID, NULL); // "자식 스레드: 11" 출력
    // join 함수가 없으면 자식 스레드의 출력이 나오지 않는다.

    printf("메인 스레드가 자식 스레드를 기다리는 것을 마쳤습니다.\n");
    printf("메인 스레드: %d\n", data); // "메인 스레드: 11" 출력
    return (0);
}
```

```c
#include <pthread.h>

void* thread_fuction(void* data)
{
    *(int*)data += 10;
    printf("자식 스레드 실행\n");
    return (data);
}

int main()
{
    pthread_t threadID;
    int data = 1;
    void* return_value;

    pthread_create(&threadID, NULL, thread_fuction, (void*)&data);
    printf("스레드 생성\n");

    printf("메인 스레드가 자식 스레드를 기다립니다.\n");
    pthread_join(threadID, &return_value); // &return_value에 리턴값 저장.

    printf("메인 스레드가 자식 스레드를 기다리는 것을 마쳤습니다.\n");
    printf("return_value: %d\n", *(int*)return_value); // "return_value: 11" 출력
    return (0);
}
```

</details>

## pthread_join vs pthread_detach
* pthread_create 시 함수는 실행을 시작한다. join은 메인 스레드에서 종료를 대기하는 것 뿐.

<details>
<summary>코드</summary>

```c
int g_count = 0;

void *t_function(void *data)
{
    char* thread_name = (char*)data;

    for (int i = 0; i < 5; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;
        sleep(1);
    }
    return (NULL);
}

int main()
{
    pthread_t p_thread1;
    pthread_t p_thread2;

    pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
    pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2"); // 스레드2도 시작
    pthread_join(p_thread1, NULL);
    pthread_join(p_thread2, NULL);
}
/*
Thread1 COUNT 0
Thread2 COUNT 0
Thread1 COUNT 2
Thread2 COUNT 2
Thread1 COUNT 4
Thread2 COUNT 4
*/
```

```c
int g_count = 0;

void *t_function(void *data)
{
    char* thread_name = (char*)data;

    for (int i = 0; i < 5; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;
        sleep(1);
    }
    return (NULL);
}

int main()
{
    pthread_t p_thread1;
    pthread_t p_thread2;

    pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
    pthread_join(p_thread1, NULL); // 이후 코드가 바로 실행되지 않으므로, 스레드1이 종료된 후 스레드2가 생성됨.
    pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");
    pthread_join(p_thread2, NULL);
}
/*
Thread1 COUNT 0
Thread1 COUNT 1
Thread1 COUNT 2
Thread2 COUNT 3
Thread2 COUNT 4
Thread2 COUNT 5
*/
```

</details>

* join을 사용하면 뒤의 코드가 바로 실행되지 않는다. (**blocking**이라고 표현)

<details>
<summary>코드</summary>

```c
int g_count = 0;

void *t_function(void *data)
{
    char* thread_name = (char*)data;

    for (int i = 0; i < 4; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;
        sleep(1);
    }
    return (NULL);
}

int main()
{
    pthread_t p_thread1;

    pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1"); // 스레드의 함수 실행
    for (int i = 0; i < 2; i++)
    {
        printf("main: %d\n", i);
        sleep(1);
    } // 그러나 메인문이 종료되면 프로그램 종료
}
/*
main: 0
Thread1 COUNT 0
main: 1
Thread1 COUNT 1
*/
```

```c
int g_count = 0;

void *t_function(void *data)
{
    char* thread_name = (char*)data;

    for (int i = 0; i < 4; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;
        sleep(1);
    }
    return (NULL);
}

int main()
{
    pthread_t p_thread1;

    pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
    pthread_join(p_thread1, NULL); // 스레드의 함수가 실행
    for (int i = 0; i < 2; i++) // 이후 나머지 코드 실행
    {
        printf("main: %d\n", i);
        sleep(1);
    }
}
/*
Thread1 COUNT 0
Thread1 COUNT 1
Thread1 COUNT 2
Thread1 COUNT 3
main: 0
main: 1
*/
```

```c
int g_count = 0;

void *t_function(void *data)
{
    char* thread_name = (char*)data;

    for (int i = 0; i < 4; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;
        sleep(1);
    }
    return (NULL);
}

int main()
{
    pthread_t p_thread1;

    pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
    pthread_detach(p_thread1); // 스레드1이 분리
    for (int i = 0; i < 2; i++) // 메인 스레드도 실행
    {
        printf("main: %d\n", i);
        sleep(1);
    } // 메인 스레드가 끝나면 프로그램 종료..? 자원 해제만 보장하는 건가?
}
/*
main: 0
Thread1 COUNT 0
main: 1
Thread1 COUNT 1
*/
```

</details>

## 뮤텍스 함수

* `int pthread_mutex_init(pthread_mutex_t * mutex, const pthread_mutex_attr *attr);`
    * 뮤텍스 객체를 초기화한다.

<details>
<summary>코드</summary>

```c
pthread_mutex_t mutex_lock;
int g_count = 0;

void *t_function(void *data)
{
    char* thread_name = (char*)data;

    pthread_mutex_lock(&mutex_lock); // lock을 주석처리하면 "0,1,2,0,4,5"
    for (int i = 0; i < 3; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;
    }
    pthread_mutex_unlock(&mutex_lock); // unlock을 주석처리하면 "0,1,2" 출력 후 무한 대기.
    return (NULL);
}

int main()
{
    pthread_t p_thread1, p_thread2;

    pthread_mutex_init(&mutex_lock, NULL);

    pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
    pthread_create(&p_thread2, NULL, t_function, (void *)"Thread2");

    pthread_join(p_thread1, NULL);
    pthread_join(p_thread2, NULL);
    // join 함수는 스레드1이 종료되길 기다리고 스레드2를 실행시키는게 아니다! 부모 스레드가 기다려줄 뿐.
}
/*
Thread1 COUNT 0
Thread1 COUNT 1
Thread1 COUNT 2
Thread2 COUNT 3
Thread2 COUNT 4
Thread2 COUNT 5
*/
```

</details>

* `int pthread_mutex_destroy(pthread_mutex_t *mutex);`
    * 뮤텍스를 파괴한다.

<details>
<summary>코드</summary>

```c
pthread_mutex_t mutex_lock;
int g_count = 0;

void *t_function(void *data)
{
    char* thread_name = (char*)data;

    pthread_mutex_lock(&mutex_lock);
    for (int i = 0; i < 3; i++)
    {
        printf("%s COUNT %d\n", thread_name, g_count);
        g_count++;
    }
    // pthread_mutex_unlock(&mutex_lock); // 잠금을 해제하지 않음.
    return (NULL);
}

int main()
{
    pthread_t p_thread1;

    pthread_mutex_init(&mutex_lock, NULL);
    pthread_create(&p_thread1, NULL, t_function, (void *)"Thread1");
    pthread_join(p_thread1, NULL);

    printf("ret: %d\n", pthread_mutex_destroy(&mutex_lock)); // mutex가 다른 스레드에 의해 락되고 있으므로 실패. 에러코드 반환.
}
/*
Thread1 COUNT 0
Thread1 COUNT 1
Thread1 COUNT 2
ret: 16
*/
```

</details>

* `int pthread_mutex_lock(pthread_mutex_t *mutex);`
    * 뮤텍스 객체를 잠근다.

* `int pthread_mutex_unlock(pthread_mutex_t *mutex);`
    * 뮤텍스 객체의 락을 해제한다.

## 세마포어(POSIX) 함수

> * https://yebig.tistory.com/305
> * https://blackinkgj.github.io/semaphore/
> * https://samse.tistory.com/entry/POSIX-semaphore
> * https://www.joinc.co.kr/w/Site/system_programing/IPC/semaphores
> * https://jhnyang.tistory.com/notice/31 운영체제

* `sem_t *sem_open(const char *name, int oflag, mode_t mode, int value);`
    * 세마포어를 초기화한다. 세마포어의 주소를 반환한다.

* `int sem_close(sem_t *sem);`
    * 세마포어를 종료한다. 성공하면 0을 반환한다.

* `int sem_post(sem_t *sem);`
    * 세마포어의 잠금을 해제한다. (값을 증가시킨다.)

* `int sem_wait(sem_t *sem);`
    * 세마포어를 잠근다. (값을 감소시킨다.)

* `int sem_unlink(const char *name);`
    * 세마포어를 제거한다.
    > * https://stackoverflow.com/questions/15164484/when-to-call-sem-unlink unlink는 언제 사용?

<details>
<summary>코드</summary>

```c
#include <pthread.h> // pthread 함수가 없더라도, 컴파일 시 -pthread 옵션 넣어줘야.
#include <semaphore.h>
#include <unistd.h> // sleep(), usleep()
#include <stdio.h> // printf()
#include <fcntl.h> // oflag

void *th_func(void *data)
{
    sem_t *sem;

    sem = (sem_t *)data;
    sem_wait(sem);
    printf("child: sem_wait\n");
    sleep(1);
    sem_post(sem);
    printf("child: sem_post\n");
    return (NULL);
}

int main()
{
    pthread_t thread;
    sem_t *sem;
    int value;

    sem_unlink("sem1"); // 중요! 이름이 이미 사용되고 있을 수 있으니 제거.
    if ((sem = sem_open("sem1", O_CREAT | O_EXCL, 0777, 1)) == NULL) // 세마포어 값 1로 설정.
    {
        printf("error return.\n");
        return (1);
    }
    
    sem_getvalue(sem, &value);
    printf("%d\n", value);

    pthread_create(&thread, NULL, th_func, sem);
    pthread_detach(thread);
    printf("parent: sem_wait\n");
    sem_wait(sem);
    printf("parent: sem_post\n");
    // 세마포어 값이 1이면, 자식 스레드가 반환할 때까지 대기.
    // 세마포어 값이 1보다 크면, 바로 반환 실행.
    sem_post(sem);

    printf("waiting...\n");
    sleep(5);
}
```

</details>

## 프로세스 함수

* `pid_t fork();`
    > * http://forum.falinux.com/zbxe/index.php?mid=C_LIB&document_srl=412814
    * 자식프로세스를 생성한다.

<details>
<summary>코드</summary>

```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() // 프로세스와 메모리 예제
{
    int *a;
    pid_t pid;

    a = (int *)malloc(sizeof(int)); // heap에 할당.
    *a = 1;
    pid = fork(); // 부모에서는 자식프로세스 id를 리턴. 자식에서는 0을 리턴.
    printf("fork start: %d / %d\n", pid, getpid()); // getpid(): 현재 프로세스 id 리턴.
    if (pid == 0)
    {
        *a += 1;
        printf("child process: %d / %d / %d\n", *a, pid, getpid());
    }
    else
    {
        wait(NULL); // 자식 프로세스가 끝날 때까지 대기.
        *a += 10;
        printf("parent process: %d / %d / %d\n", *a, pid, getpid());
        // 자식프로세스에서 값을 더해도, 부모프로세스에는 영향이 없다.
        // 힙(다른 메모리 영역도)을 공유하지 않기 때문.
    }
}
/* 출력 결과
fork start: 405 / 404
fork start: 0 / 405
child process: 2 / 0 / 405
parent process: 11 / 405 / 404
*/
```

```c
# include <stdio.h>
# include <semaphore.h> // pthread.h를 인클루드하지 않지만, 컴파일 시 -pthread를 해줘야 sem 함수가 돌아간다.
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>

int main() // 프로세스와 세마포어 예제
{
    sem_t *sem;
    int pid;
    int value;

    sem_unlink("sem"); // sem_close()를 해줘도, unlink를 안해주면 open에 실패할 수.
    if ((sem = sem_open("sem", O_CREAT | O_EXCL, 0777, 5)) == NULL)
    {
        printf("sem error.\n");
        return (1);
    }
    pid = fork();
    if (pid == 0)
    {
        sem_wait(sem);
        sem_getvalue(sem, &value);
        printf("child: %d\n", value);
    }
    else
    {
        wait(NULL);
        sem_wait(sem);
        sem_getvalue(sem, &value);
        printf("parent: %d\n", value);
        // 세마포어는 메모리에 존재하는 것이 아닌 파일로 존재하기 때문에,
        // 자식프로세스에서 값을 변경하면 부모프로세스에서도 변경된다.
    }
    sem_close(sem); // sem_close()는 free의 역할을 하는 것 같다.
}
/*
child: 4
parent: 3
*/
```
</details>

* `int kill(pid_t pid, int sig);`
    > * https://www.joinc.co.kr/w/man/2/kill
    > * http://forum.falinux.com/zbxe/index.php?document_srl=413771&mid=C_LIB
    * 특정 프로세스에 시그널을 보낸다.
        * pid > 0: pid로 시그널을 보낸다.
        * pid == 0: 현재 프로세스가 속한 프로세스 그룹에게 시그널을 보낸다.
        * (그 외는 필요할 때 찾아볼 것)
    * 헤더: `<signal.h>`
    * 매개변수 `pid`: 시그널을 받을 프로세스 id.
    * 매개변수 `sig`: 보내려는 시그널.
    * 반환값: 성공하면 0, 실패하면 -1.
    > * https://blockdmask.tistory.com/23 시그널 기본 설명 및 관련 함수

* `pid_t waitpid(pid_t pid, int *status, int options);`
    > * https://www.it-note.kr/133
    > * https://codetravel.tistory.com/42
    > * https://mintnlatte.tistory.com/21
    > * https://codingdog.tistory.com/entry/%EB%A6%AC%EB%88%85%EC%8A%A4-waitpid-%ED%95%A8%EC%88%98-%EC%9E%90%EC%8B%9D-%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4%EB%A5%BC-%EA%B8%B0%EB%8B%A4%EB%A6%B0%EB%8B%A4
    * 헤더: `<sys/wait.h>`
    * 매개변수 `pid`: 기다릴 프로세스 id.
        * pid > 0:
        * pid == 0:
        * pid == -1:
        * pid \< -1:
    * 반환값: 성공하면 프로세스 id, 실패하면 -1.
    * wait와의 차이는 `pid`와 `options` 매개변수.

<details>
<summary>코드</summary>

```c
# include <unistd.h>
# include <sys/wait.h>

int main()
{
    int pid;
    int value;

    pid = fork();
    if (pid == 0)
    {
        sleep(3);
    }
    else
    {
        kill(pid, SIGINT); // 주석처리하면 프로그램은 3초 후에 종료됨.
        waitpid(pid, NULL, 0);
    }
}
```

```c
# include <unistd.h>
# include <sys/wait.h>

int main()
{
    int pid;

    pid = fork();
    if (pid == 0)
    {
        kill(pid, SIGINT); // 주석처리하면 프로그램은 3초 후에 종료됨.
    }
    else
    {
        waitpid(pid, NULL, 0);
        sleep(3);
    }
}
```

</details>

* `void exit(int status);`
    * 프로세스를 종료시킨다.
    * 부모 프로세스는 wait나 waitpid를 이용해서 자식 프로세스의 종료값을 얻을 수 있다.

<details>
<summary>코드</summary>

```c
# include <unistd.h> // fork, sleep
# include <sys/wait.h> // waitpid
# include <stdlib.h> // exit
# include <stdio.h> // printf

int main()
{
    int pid;
    int status;

    pid = fork();
    if (pid == 0)
    {
        sleep(3);
        exit(1);
    }
    else
    {
        waitpid(pid, &status, 0);
        printf("%d\n", WEXITSTATUS(status));
        // (하위 8비트를 참조해서) exit 함수에 넘겨준 값을 얻는 매크로.
    }
}
```

```c
void *th_func(void *data)
{
    int i = 0;

    while (1)
    {
        if (i == 3)
            exit(0); // 3초 후에 여기서 종료하면, 자식 프로세스까지 다 종료됨.
        printf("thread\n");
        sleep(1);
        i++;
    }
    return (NULL);
}

int main()
{
    pid_t pid;
    int i;

    pid = fork();
    if (pid == 0)
    {
        pthread_t thread;
        int i = 0;

        pthread_create(&thread, NULL, th_func, NULL);
        while (1)
        {
            if (i == 8)
                exit(0);
            printf("child process\n");
            sleep(1);
            i++;
        }
    }
    else
        waitpid(pid, NULL, 0);
}
```

</details>

## 여러 자식 프로세스 생성 및 대기
```c
static void	fork_and_wait(t_args *args, t_man *man, pid_t *pids)
{
	int				status;
	unsigned int	i;

	i = 0;
	status = 0;
	while (i < args->num_of_ph) // 철학자 수만큼 자식 프로세스 생성.
	{
		pids[i] = fork();
		if (pids[i] == 0)
			child_func(args, man, i);
		i++;
	}
	i = 0;
	while (i < args->num_of_ph)
	{
		waitpid(pids[i], &status, 0);
		if (WEXITSTATUS(status) == 0) // 0번 철학자가 죽으면(exit(0)) 리턴.
			return ;
		else if (WEXITSTATUS(status) == 1) // 0번 철학자가 정해진 식사 횟수를 채우면(exit(1)), 다음 철학자 기다림.
			i++;
	}
}
```

## 프로세스
* https://studymake.tistory.com/619
* https://12bme.tistory.com/222

## 시그널
* https://12bme.tistory.com/224
* https://www.joinc.co.kr/w/Site/system_programing/Book_LSP/ch06_Signal
* https://base-on.tistory.com/362
