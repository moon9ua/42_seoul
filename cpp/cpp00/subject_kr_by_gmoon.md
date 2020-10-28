# C++ - Module 00

Namespace(네임스페이스), class(클래스), member functions(멤버 함수), stdio stream, initialization lists, static, const, and lots of basic stuff

## 일반 지침

* (템플릿의 경우를 제외한) 헤더에서 구현된 모든 함수나 보호되지 않은 헤더는 0점입니다.
* 모든 출력은 표준 출력으로 가야하고, 특별한 언급이 없으면 개행으로 끝나야합니다.
* The imposed filenames must be followed to the letter, as well as class names, function names and method names.
* 기억하세요: 더이상 C가 아니라 C++로 코딩해야 합니다. 그러므로:
    * 다음의 함수들은 금지됩니다. 사용하면 0점 처리될 것입니다: ***alloc, *printf, free.**
    * 기본적으로는 모든 표준 라이브러리를 사용 가능합니다. 하지만, 당신이 알고있는 그대로 하는 것 보다, C에서 사용한 함수들의 C++스러운 버전을 도전하고 사용하는 것이 더 유익할 것입니다. 이것은 완전 새로운 언어입니다. 또한 당신은 STL을 사용할 수 없습니다(실제로는 모듈 08까지). 이것은 벡터, 리스트 등 <algorithm>에 포함된 것들을 사용할 수 없다는 뜻입니다.
* 실제로, 명시적으로 금지된 함수나 기법은 0점처리 될 것입니다.
* 또한 명심하세요. 특별한 언급이 없으면 "네임스페이스 사용"과 "friend"는 금지됩니다. 사용한다면 -42점 처리될 것입니다.
* 클래스와 관련 있는 파일들은 특별한 언급이 없으면 항상 ClassName.hpp과 ClassName.cpp이어야 합니다.
* 디렉토리 ex00/, ex01/, ... , exn/에 넣어주십시오.
* 예제를 철저히 읽어야합니다. 여기에는 문제에서는 명확히 설명되지 않은 요구사항이 포함될 수 있습니다. 무엇인가가 모호해보인다면, 당신이 C++을 충분히 이해하지 못한 것입니다.
* Since you are allowed to use the C++ tools you learned about since the beginning, you are not allowed to use any external library. And before you ask, that also means no C++11 and derivates, nor Boost or anything your awesomely skilled friend told you C++ can’t exist without.
* You may be required to turn in an important number of classes. This can seem tedious, unless you’re able to script your favorite text editor.
* 컴파일러는 clang++을 사용하세요.
* 코드는 다음의 플래그들과 함께 컴파일되어야 합니다: -Wall -Wextra -Werror.
* Each of your includes must be able to be included independently from others. Includes must contains every other includes they are depending on, obviously.
* C++에서는 코딩 스타일이 강요되지 않습니다. 어떠한 스타일이라도 제한없이 사용 가능합니다. 하지만 동료 평가자가 읽을 수 없는 코드는 채점할 수 없는 코드라는 것을 명심하세요.
* 특별한 언급이 없으면 프로그램에 의해 채점되지 않습니다. 그러므로, 어느 정도 문제를 풀 것인지는 어느 정도의 자유가 주어집니다. 하지만 각 문제의 제약조건을 염두에 두고, 게으르지 마십시오. 문제에서 제공하는 것을을 놓치게 될 것입니다!
* 폴더에 관련 없는 파일이 있는 것은 문제되지 않습니다. 당신은 요구된 것 보다 더 파일들을 코드로 분리할 수 있습니다. 프로그램에 평가되지 않는 한, 자유롭게 하십시오.
* 문제가 짧더라도, 당신이 완전히 이해하였고, 최선의 방법으로 수행했다는 것을 확신할 때까지 시간을 투자하는 것이 좋습니다.

## Exercise 00: Megaphone

| Exercise : 00 |
| --- |
| 제출 디렉토리 ex00/ |
| 제출할 파일: Makefile, megaphone.cpp |
| 금지 함수: 없음 |

모두가 깨어있는지 확인하려면, 다음과 같은 동작을 하는 프로그램을 작성하세요:

```
$>./megaphone "shhhhh... I think the students are asleep..."
SHHHHH... I THINK THE STUDENTS ARE ASLEEP...
$>./megaphone Damnit " ! " "Sorry students, I thought this thing was off."
DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF.
$>./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *
$>
```

## Exercise 01: My Awesome PhoneBook

| Exercise : 01 |
| ---- |
| 제출 디렉토리 ex01/ |
| 제출할 파일: Makefile, *.cpp, *.{h, hpp} |
| 금지 함수: 없음 |

80년대와 그 믿을 수 없는 기술에 오신 것을 환영합니다! 엉터리이고 놀라운(crappy awesome) 전화번호부 소프트웨어처럼 작동하는 프로그램을 작성하세요. 당신의 실행 파일을 연관성있는 이름으로 짓도록 시간을 투자하세요. 프로그램이 시작되면, 입력을 기다립니다: 당신은 ADD, SEARCH, EXIT 명령을 해야합니다. 다른 입력은 버립니다.

프로그램은 비어있는 채(연락처 없음)로 시작되며, 동적 할당을 사용하지 않으며, 8개 이상의 연락처를 저장할 수 없습니다. 만약 9번째 연락처가 추가된다면, 관련 동작을 정의하세요.

💡 http://www.cplusplus.com/reference/string/string/ 와 http://www.cplusplus.com/reference/iomanip/ 를 참고하세요.

* if, 명령이 EXIT라면:
    * 프로그램은 종료되고 연락처들은 영원히 사라집니다.

* else if, 명령이 ADD라면:
    * 프로그램은 새로운 연락처의 정보에 대한 유저의 입력을 대기합니다. 한 번에 한 필드 씩, 모든 필드가 입력될 때 까지.
    * 연락처는 다음의 필드들로 정의되어 있습니다: first name, last name, nickname, login, postal address, email address, phone number, birthday date, favorite meal, underwear color and darkest secret.
    * 연락처는 반드시 클래스의 인스턴스로 나타나야 합니다. 클래스를 어떻게 구성할지는 자유이지만, 동료 평가에서 당신의 선택들의 일관성을 검사할 것입니다.

* else if, 명령이 SEARCH라면:
    * 프로그램은 사용 가능한 비어있지 않은 연락처들의 목록을 4열로 표시합니다: index, first name, last name, nickname.
    * 각 열은 너비가 10문자여야하고, 오른쪽으로 정렬되어야 하며, '|' 문자로 구분되어야 합니다. 열의 너비보다 긴 출력은 잘리고, 마지막 표시 가능한 문자는 점('.')으로 대체됩니다.
    * 그 후 프로그램은 원하는 항목의 index를 다시 묻고, 선택된 연락처의 정보를 한 줄에 한 필드씩 표시합니다. 만약 입력이 말이 되지 않는 경우, 관련 동작을 정의하세요.

* else, 입력은 버려집니다.

명령이 적절히 실행되면, 프로그램은 EXIT 명령이 내려질 때까지 또다른 ADD, SEARCH 명령을 대기합니다.
