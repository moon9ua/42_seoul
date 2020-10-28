# cub3D

**My first RayCaster with miniLibX**<br>

요약: 이 프로젝트는 세계적으로 유명한 90년대 최초의 FPS 게임에서 영감을 받은 것이다. 이것은 당신이 ray-casting을 경험할 수 있게 해줄 것이다. 당신의 목표는 당신이 길을 찾아야 할 미로 안에서 역동적인 시선을 만드는 것이다.

## Chapter 1. 머리말

울펜슈타인 3D는 1992년 아포지 소프트웨어에서 개발되었으며, 비디오게임 역사상 최초의 FPS 게임이다. 울펜슈타인 3D는 Doom, Doom 2, Duke Nukem 3D, Quake와 같은 게임의 조상으로, 비디오게임 세계에서 영원한 이정표다. 이제, 다시 당신이 역사를 체험할 시간이다...

## Chapter 2. 목표

이 프로젝트의 목표는 올해의 첫 목표였던 '엄격성(Rigor), C의 사용, 기본 알고리즘의 사용, 정보 검색' 등과 유사하다. cub3D는 그래픽 디자인 프로젝트로서, 'windows, 색상, events, 채우기 모양' 등의 분야에서 당신의 기술을 향상시킬 것이다. 결론적으로 cub3D는 구체적인 내용을 이해하지 않고도 수학의 실용적인 적용을 탐색할 수 있는 놀라운 놀이터이다. 인터넷에서 사용할 수 있는 수많은 문서를 통해, 당신은 수학을 우아하고 효율적인 알고리즘을 만드는 도구로 사용할 것이다. 이 프로젝트를 시작하기 전에 [오리지널 게임](http://users.atw.hu/wolf3d/)을 먼저 시험해 볼 것을 추천한다. 

## Chapter 3. 일반 지침

생략

## Chapter 4. 필수 파트 - cub3D

| 프로그램명 | cub3D                                                        |
| ---------- | ------------------------------------------------------------ |
| 제출 파일  | 당신의 모든 파일                                             |
| Makefile   | all, clean, fclean, re, bonus                                |
| Arguments  | a map in format                                              |
| 허용 함수  | open, close, read, write, malloc, free, perror, strerror, exit.<br>math library의 모든 함수 (-lm man man 3 math).<br>MinilibX의 모든 함수. |
| Libft 허용 | O                                                            |
| 요약       | 당신은 1인칭 시점에서 미로 안의 "현실적인" 3D 그래픽 표현을 만들어야한다. 당신은 이러한 표현을 만들기 위해 앞에서 언급한 ray-casting 원칙을 사용해야 한다. |

제약조건은 다음과 같다:

* 당신은 반드시 miniLibX를 사용해야 한다. 운영체제 또는 해당 소스에서 사용할 수 있는 버전이다. 만약 소스로 작업하기로 선택했으면, 일반 지침에 작성된 것과 동일한 규칙을 당신의 libft에 적용해야 한다.
* 창 관리가 원활하게 유지되어야 한다: 다른 창으로 변경, 최소화, 기타 등등.
* 벽이 향하는 면(동, 서, 남, 북)에 따라 다른 텍스처를 표시해야 한다.
* 벽 대신 아이템(sprite)를 표시할 수 있어야 한다.
* 바닥과 천장의 색을 두개의 다른 색으로 설정할 수 있어야 한다.(to two different ones.)
* 두번째 인수가 "--save" 인 경우, 렌더링된 이미지를 bmp 형식으로 저장해야 한다.
* 두번째 인수가 없으면, 프로그램은 이미지를 창에 표시하고 다음 규칙을 따른다.
  * 키보드의 좌우 화살표 키를 사용하면 미로에서 좌우를 볼 수 있어야 한다.
  * w, a, s, d 키를 사용하면 미로에서 시점을 이동할 수 있어야 한다.
  * ESC를 누르면 창을 닫고 프로그램을 완전히 종료해야 한다.
  * 창 프레임의 빨간 x 버튼을 누르면 창을 닫고 프로그램을 완전히 종료해야 한다.
  * 만약 맵에서 선언된 화면 크기가 디스플레이 해상도보다 큰 경우, 창 크기는 디스플레이 해상도에 따라 설정된다.
  * minilibX의 이미지 사용을 적극 권장한다.
* 프로그램은 확장자가 .cub인 배경 묘사 파일을 첫 번째 인수로 사용해야 한다.
  * 맵은 4개의 가능한 문자로 구성되어야 한다: 빈 공간은 0, 벽은 1, 아이템은 2, 플레이어의 시작 위치 및 스폰 방향은 N, S, E, W. 다음은 간단한 유효 맵이다.
    ```
    111111
    100101
    102001
    1100N1
    111111
    ```
  * 프로그램이 에러를 반환하지 않는 경우, 맵은 벽으로 둘러싸여 있어야 한다.
  * 맵 컨텐츠을 제외하고, 각 유형 요소는 하나 이상의 빈 줄로 분리될 수 있다.
  * 항상 마지막이어야 하는 맵 컨텐츠를 제외하고, 각 유형 요소는 파일에서 임의의 순서로 설정할 수 있다.
  * 맵을 제외하고, 요소의 각 정보 유형은 하나 이상의 공백으로 분리할 수 있다.
  * 맵은 파일에서 보이는대로 구문 분석해야 한다.(The map must be parsed as it looks like in the file.) 공백은 맵의 유효한 부분이며, 당신이 하기에 달려있다. 당신은 규칙을 준수하는 어떠한 종류의 맵도 parse 할 수 있어야 한다.
  * 각 요소(맵 제외)의 첫번째 정보는 유형 식별자(1~2개의 문자로 구성)이며, 다음과 같은 엄격한 순서로 특정 정보가 이어진다.
    > ∗ Resolution:<br>
    > `R 1920 1080` <br>
    > · identifier: R <br>
    > · x render size <br>
    > · y render size<br>
    >
    > <br>
    >
    > ∗ North texture:<br>
    > `NO ./path_to_the_north_texture<br>`
    > · identifier: NO<br>
    > · path to the north texure<br>
    >
    > <br>
    >
    > ∗ South texture:<br>
    > `SO ./path_to_the_south_texture`<br>
    > · identifier: SO<br>
    > · path to the south texure<br>
    >
    > <br>
    >
    > ∗ West texture:<br>
    > `WE ./path_to_the_west_texture`<br>
    > · identifier: WE<br>
    > · path to the west texure<br>
    >
    > <br>
    >
    > ∗ East texture:<br>
    > `EA ./path_to_the_east_texture`<br>
    > · identifier: EA<br>
    > · path to the east texure<br>
    >
    > <br>
    >
    > ∗ Sprite texture:<br>
    > `S ./path_to_the_sprite_texture`<br>
    > · identifier: S<br>
    > · path to the sprite texure<br>
    >
    > <br>
    >
    > ∗ Floor color:<br>
    > `F 220,100,0`<br>
    > · identifier: F<br>
    > · R,G,B colors in range [0,255]: 0, 255, 255<br>
    >
    > <br>
    >
    > ∗ Ceilling color:<br>
    > `C 225,30,0`<br>
    > · identifier: C<br>
    > · R,G,B colors in range [0,255]: 0, 255, 255<br>
  * 필수 파트의 최소 .cub scene 예시이다.
    ```
    R 1920 1080
    NO ./path_to_the_north_texture
    SO ./path_to_the_south_texture
    WE ./path_to_the_west_texture
    EA ./path_to_the_east_texture
    S ./path_to_the_sprite_texture
    F 220,100,0
    C 225,30,0
    		1111111111111111111111111
    		1000000000110000000000001
    		1011000001110000002000001
    		1001000000000000000000001
    111111111011000001110000000000001
    100000000011000001110111111111111
    11110111111111011100000010001
    11110111111111011101010010001
    11000000110101011100000010001
    10002000000000001100000010001
    10000000000000001101010010001
    11000001110101011111011110N0111
    11110111 1110101 101111010001
    11111111 1111111 111111111111
    ```
  * 파일에 어떤 종류의 오류라도 발생하면 프로그램은 올바르게 종료되고 "Error\n"을 표시한 다음 당신이 선택한 오류 메세지가 표시되어야 한다.

## Chapter 5. 보너스 파트

❗ 필수 파트가 완벽하지 않으면, 보너스 파트는 무시될 것.

보너스 리스트:

> • Wall collisions. • A skybox. • Floor and/or ceiling texture. • An HUD. • Ability to look up and down. • Jump or crouch. • A distance related shadow effect. • Life bar. • More items in the maze. • Object collisions. • Earning points and/or losing life by picking up objects/traps. • Doors which can open and close. • Secret doors. • Animations of a gun shot or animated sprite. • Several levels. • Sounds and music. • Rotate the point of view with the mouse. • Weapons and bad guys to fight!

🔅 모든 보너스를 받기 위해선 최소 14개를 해야하므로, 현명하게 선택하되 시간을 낭비하지 않도록 주의!

💬 You are allowed to use other functions to complete the bonus part as long as their use is justified during your evaluation. You are also allowed to modify the expected scene file format to fit your needs.
Be smart!

## Chapter 6. 예시

1. RayCasting을 사용한 울펜스테인3D 오리지널 게임.
2. 필수 파트를 완료한 프로젝트의 예시.
3. 미니맵, 바닥과 천장 텍스처, 움직이는 캐릭터가 있는 보너스 파트의 예시.
4. HUD, 라이프 바, 사운드와 음악, 그림자 효과, 쏠 수 있는 총이 있는 보너스 파트의 예시.
5. 다른 무기로의 교체가 가능한 보너스 파트의 예시.