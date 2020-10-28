# Philosophers
철학이 그렇게 치명적일 줄 몰랐어요.  
요약: 이 프로젝트에서, 당신은 프로세스 스레딩의 기본과 동일한 메모리 공간에서 작업하는 방법을 배울 것입니다. 스레드를 어떻게 만드는지를 배울 것입니다. 뮤텍스, 세마포어, 공유 메모리를 배울 것입니다.

## 챕터 1. 개요
생략

## 챕터 2. 필수 파트
당신은 3개의 다른 프로그램을 작성해야 하지만, 기본 규칙은 동일합니다:
* 이 프로젝트는 Norm에 따라 C로 코딩됩니다. 누수, 충돌, 정의되지 않은 동작 및 norm 오류는 0점입니다.
* 많은 철학자들이 식탁에 앉아 세가지 행동 중 하나를 합니다: eating, thinking, sleeping.
* eating 중에, 그들은 thinking이나 sleeping을 하지 않습니다. 당연히 thinking 중에는 eating이나 sleeping을 하지 않고, sleeping 중에는 eating이나 thinking을 하지 않습니다.
* 철학자들은 중앙에 커다란 스파게티 그릇이 있는 원형 테이블에 앉아 있습니다.
* 테이블에는 포크들이 있습니다.
* 스파게티는 한 손에 하나 씩 두 개의 포크로 먹어야합니다.
* 철학자들은 절대 굶주려서는 안됩니다.
* 모든 철학자은 먹어야합니다.
* 철학자들은 서로 얘기하지 않습니다.
* 철학자들은 다른 철학자들이 언제 죽을지 모릅니다.
* 철학자들이 eating을 마치면, 포크를 내려놓고 sleeping을 시작합니다.
* 철학자들이 sleeping을 마치면, thinking을 시작합니다.
* 철학자가 죽으면 시뮬레이션이 종료됩니다.
* 각 프로그램은 동일한 옵션을 가져야합니다: `number_of_philosophers` `time_to_die` `time_to_eat` `time_to_sleep` `[number_of_times_each_philosopher_must_eat]`
    * number_of_philosophers: 철학자의 수와 포크의 수입니다.
    * time_to_die: 밀리 초 단위입니다. 철학자가 마지막 식사 이후나 시뮬레이션 시작 이후 'time_to_die' 밀리 초만큼 먹지 않으면 죽습니다.
    * time_to_eat: 밀리 초 단위입니다. 철학자가 먹는 데 걸리는 시간입니다. 이 시간동안 두 개의 포크를 지녀야 합니다.
    * time_to_sleep: 밀리 초 단위입니다. 이 시간동안 철학자는 잠을 잡니다.
    * number_of_times_each_philosopher_must_eat: 이 인자는 옵션입니다. if all philosophers eat at least 'number_of_times_each_philosopher_must_eat’ the simulation will stop. 지정하지 않으면, 시뮬레이션은 철학자가 사망할 때만 중지됩니다.
* 각 철학자는 1에서 number_of_philosophers 까지의 숫자를 지정해야 합니다.
* 철학자 1번은 철학자 number_of_philosophers번의 옆에 있습니다. 다른 n번의 철학자들은 n-1번과 n+1번 사이에 앉습니다.
* 철학자의 상태 변경은 다음과 같이 작성해야 합니다. (X를 철학자 번호로 바꾸고, timestamp_in_ms는 현재 타임 스탬프의 밀리 초단위.)
    * timestamp_in_ms X has taken a fork
    * timestamp_in_ms X is eating
    * timestamp_in_ms X is sleeping
    * timestamp_in_ms X is thinking
    * timestamp_in_ms X died
* 출력된 상태는 다른 철학자의 상태들과 섞이거나 얽히면 안됩니다.
* 철학자의 죽음과 그 죽음을 그 죽음을 출력하는 시간 사이는 10ms를 초과하면 안됩니다.
* 다시 말하지만 철학자들이 죽는 것은 피해야 합니다.

|||
| --- | --- |
| 프로그램 명 | philo_one |
| 제출 파일 | philo_one/ |
| Makefile | O |
| 인자 | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] |
| 외부 함수 | memset, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock |
| libft 허용 | X |
| 설명 | philosopher with threads and mutex |

이 버전의 일반적이지 않은 규칙은 다음과 같습니다:
* 각 철학자 사이에 포크가 하나씩 있으므로, 각 철학자의 오른쪽과 왼쪽에 포크가 있습니다.
* 철학자가 포크를 복제하지 않도록 하려면, 각각에 대해 뮤텍스를 사용하여 포크 상태를 보호해야 합니다.
* 각 철학자는 스레드여야 합니다.

|||
| --- | --- |
| 프로그램 명 | philo_two |
| 제출 파일 | philo_two/ |
| Makefile | O |
| 인자 | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] |
| 외부 함수 | memset, malloc, free, write, usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, sem_open, sem_close, sem_post, sem_wait, sem_unlink |
| libft 허용 | X |
| 설명 | philosopher with threads and semaphore |

이 버전의 일반적이지 않은 규칙은 다음과 같습니다:
* 모든 포크는 테이블 중앙에 있습니다.
* 메모리에는 상태가 없지만 사용 가능한 포크의 수는 세마포어로 나타납니다.
* 각 철학자는 스레드여야 합니다.

|||
| --- | --- |
| 프로그램 명 | philo_three |
| 제출 파일 | philo_three/ |
| Makefile | O |
| 인자 | number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat] |
| 외부 함수 | memset, malloc, free, write, fork, kill, exit, pthread_create, pthread_detach, pthread_join, usleep, gettimeofday, waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink |
| libft 허용 | X |
| 설명 | philosopher with processes and semaphore |

이 버전의 일반적이지 않은 규칙은 다음과 같습니다:
* 모든 포크는 테이블 중앙에 있습니다.
* 메모리에는 상태가 없지만 사용 가능한 포크의 수는 세마포어로 나타납니다.
* 각 철학자는 프로세스여야 하며, 메인 프로세스는 철학자가 아니어야 합니다.
