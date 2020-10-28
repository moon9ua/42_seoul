# cub3d

공부한 기록은 [노션](https://www.notion.so/cub3D-b821e70bc0de4b52ac9c3e0567f833c3)으로.<br>
내가 보려고 만든 서브젝트 번역본은 [여기](https://github.com/moon9ua/42_seoul/blob/master/minishell/subject_kr_by_gmoon.md)로.

### 레이캐스팅

기본적으로 나는 (벡터가 아니라) 라디안 방식으로 구현하였다. 라디안 방식은 이해하기에 더 쉽고 직관적이라는 장점이 있으나, 아이템(stripe) 등을 구현할 때 참고 자료가 없어 직접 수식을 만들어야 하는 단점이 있었다.

### 참고자료

라디안 방식으로 구현하기 위해 참고한 사이트는 다음과 같다.

* https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/ <br>
전체적으로 이 곳의 내용을 기반으로 삼았다.
* https://courses.pikuma.com/courses/raycasting <br>
raycast를 구현하는 구체적인 방법은 이 곳을 참고하였다.

아이템을 구현할 때에는 lodev 사이트의 아이디어를 참고하였다. 부분적으로 벡터를 사용하는 식.
* https://lodev.org/cgtutor/raycasting.html <br>

### 개선할 점

집에서 원격으로 제출했어서, 클러스터에서 작동시켰을 때 다음과 문제점이 발견되었다. (추가될 수 있음)

* 키 입력을 유지할 때 제대로 동작하지 않는다. 예를 들어, w키를 누른 채 유지해도 앞으로 나아가지 않고 한 번만 이동하게 된다. 이는 key release 함수 등을 사용해서 해결해야 하는 것으로 안다.

고치기는 귀찮아서... 언젠가...
