## cpp00: 네임스페이스, 클래스, 멤버 함수, 표준입출력 스트림, 초기화 리스트, static, const...

### cin clear ignore
* https://satrol.tistory.com/m/69 : 숫자만 입력받기
* https://dodnet.tistory.com/488 : 숫자를 입력해야 빠져나가는 루프문.

### 초기화 리스트
* https://m.blog.naver.com/PostView.nhn?blogId=krinlion&logNo=40138012756&proxyReferer=https:%2F%2Fwww.google.com%2F
* https://psychoria.tistory.com/11
    > 초기화 리스트를 사용해야만 하는 경우들.  
    > 특히 부모 클래스의 멤버 변수를 초기화하려면, 초기화 리스트에 부모 클래스의 생성자를 써주어야 한다.   
    > ```c++
    > Peon::Peon(std::string name)
    > :   Victim(name) // 부모 클래스의 생성자로 멤버 변수 초기화.
    > // :   name_(name) // 컴파일 에러.
    > {
    >     std::cout << "Zog zog." << std::endl;
    > }
    > ```

### const
* https://dhna.tistory.com/25 : const 위치에 따른 동작
* https://www.cppkorea.org/CppCoreGuidelines/Const/ : C++ 핵심 가이드라인 - const
* https://dydtjr1128.github.io/cpp/2020/01/08/Cpp-const.html

### const 멤버변수
* 생성자에서 초기화 리스트로 초기화하고, 이후 불변.
* 복사생성자에서도 초기화 리스트.
    ```c++
    Form::Form(const Form& ref)
    throw(GradeTooHighException, GradeTooLowException)
    :   name_(ref.name_),
        grade_for_sign_(validGrade(ref.grade_for_sign_)),
        grade_for_exec_(validGrade(ref.grade_for_exec_)) // 초기화 리스트
    {
        *this = ref;
    }
    ```
* 할당연산자에서도 const 멤버변수는 (불변이므로) 할당하지 못한다.
    ```c++
    Form&
    Form::operator = (const Form& ref)
    {
        if (this != &ref)
        {
            sign_ = ref.sign_; // const가 아닌 멤버변수만 할당
        }
        return (*this);
    }
    ```

### const 함수
* https://dydtjr1128.github.io/cpp/2019/08/05/Cpp-const-after-function.html
    > 함수 뒤에 const는 함수가 멤버 변수를 변경할 수 없다는 뜻.

### const와 포인터
* https://boycoding.tistory.com/206
* `const int* ptr`
    ```c++
    int value = 5;
    const int* ptr = &value;

    value = 4; // 컴파일 가능. 상수가 아닌 값이므로.
    *ptr = 6; // 컴파일 에러. 변경 불가능. (상수 취급)

    int value2 = 7;
    ptr = &value2; // 컴파일 가능. 변경 가능.
    ```
    * (const int)* ptr 이라는 뜻으로, 즉 '상수를 가르키는 포인터'.
    * 포인터가 가르키는 값이 상수로, 변경 불가능. 포인터는 변경 가능.
    * 상수가 아닌 값을 가르켜도, 상수로 취급한다.
* `int* const ptr`
    ```c++
    int value = 5;
    int* const ptr = &value;

    *ptr = 6; // 컴파일 가능. 변경 가능.

    int value2 = 7;
    ptr = &value2; // 컴파일 에러. 변경 불가능.
    ```
    * **일반 상수 변수와 마찬가지로, 선언 시 초기화해야 한다.** (반대로, 상수는 선언 시 초기화해야 한다는 뜻.)
    * int* (const ptr) 이라는 뜻으로, 즉 '상수 포인터'.
    * 포인터가 상수로, 변경 불가능. 포인터가 가르키는 값은 변경 가능.

### const와 레퍼런스
* https://boycoding.tistory.com/208
* `const int& ref`의 초기화
    ```c++
    int value = 5;
    const int& ref = value; // 가능. non-const l-value.

    const int value2 = 6;
    const int& ref2 = value2; // 가능. const l-value.

    const int& ref3 = 7; // 가능. r-value.
    ```
    * const 참조는 non-const 값, const 값, r-value로 초기화할 수 있다.
    * 포인터와 마찬가지로 상수가 아닌 값을 참조해도 상수로 취급.
* `const int& ref`의 사용
    ```c++
    void changeN(const int& ref) // 복사본을 만들지 않음.
    {
        ref = 6; // 불가능.
    }
    ```
    * 함수의 매개변수로 상수 참조를 사용할 수 있다. 이렇게 하면, **복사본을 만들 필요 없이** 매개변수를 전달할 수 있다. (따라서 큰 자료형은 상수 참조로 전달할 것.)
    * 상수 참조이므로, 값은 변경할 수 없다.

    ```c++
    std::string add_world(const std::string& str)
    // const std::string& add_world(const std::string& str) // 컴파일 에러
    {
        return (ret);
    }
    int main()
    {
        std::string a = "hello";
        std::cout << add_world(a) << std::endl;
    }
    ```
    * 지역변수는 사라지므로, const int&로 반환할 수 없다.

    ```c++
    const std::string& Sorcerer::get_name() const
    {
        return (name_);
    }
    ```
    * 하지만 클래스의 멤버변수는 유지되는 동안 const int&로 반환할 수 있다. (적절한 방법인지는 모르겠다.)

### l-value와 r-value
* https://m.blog.naver.com/luku756/221808884092
    > l-value: 식 이후에 사라지지 않는 값. 이름을 지니는 변수.  
    > r-value: 표현식 이후에 사라지는 값. 임시 변수.



## cpp01: 메모리 할당, 레퍼런스, 포인터, 파일 스트림

### C++ 네이밍
* https://torbjorn.tistory.com/257
    > 구글에서는 멤버변수 뒤에 추가로 언더바(_) 붙여서 구분.

### 랜덤 문자열 생성
* https://m.blog.naver.com/ktguni/221249010968
    > `rand()`, `srand()`, `time()`을 사용.

### stringstream
* `#include <sstream>`

### 파일 입출력
* `#include <fstream>`
* https://modoocode.com/213
* https://modoocode.com/215



## cpp02: Ad-hoc 다형성, 연산자 오버로드, 캐노니컬 클래스

### Ad-hoc 다형성
* http://blog.daum.net/it-focus/143
    > Ad-hoc 다형성이란 가짜 다형성. 실제로 진짜 다형성을 가진 것이 아니라, 다른 것들이 모여 하나처럼 보이는 것.  
    > 오버로딩과 코어션으로 나뉨.  
    > * 오버로딩: 하나의 함수를 매개변수의 수나 타입에 따라 사용.  
    > * 코어션: float 매개변수가 필요할 때, int를 넣어줘도 됨. 즉, 타입 변환.
* http://wiki.hash.kr/index.php/%EB%8B%A4%ED%98%95%EC%84%B1
    > Ad-hoc 다형성이란 임시 다형성. 오버로딩을 의미.

### Coplien form, Canonical class form
* 두 용어의 차이는 잘 모르겠다. 캐노니컬이 코플린을 포함한다고 들었다.
* https://stackoverflow.com/questions/21219590/coplien-form-example-c
* http://www.cplusplus.com/articles/y8hv0pDG/
* https://www.francescmm.com/orthodox-canonical-class-form/
    > **기본 생성자, 복사 생성자, 소멸자, 할당 연산자.**

### 할당 연산자 오버로딩
* https://edykim.com/ko/post/c-operator-overloading-guidelines/
    > `if (this != &ref)`를 하는 이유.
* https://modoocode.com/202

### ostream 연산자 오버로딩
* https://docs.microsoft.com/ko-kr/cpp/standard-library/overloading-the-output-operator-for-your-own-classes?view=vs-2019

### 비트 연산자
* http://tcpschool.com/c/c_operator_bitwise
    > `<<` 비트들을 왼쪽으로 이동시킴.

### 고정 소수점
* https://gsmesie692.tistory.com/94
    > 고정 소수점은 10진수를 2진수로 바꾸고 정수부와 소수부에 나누어 그대로 저장.

### 소수 2진법 변환
* http://cjyuko.blogspot.com/2018/05/10-2.html



## cpp03: 상속

### switch case
* https://boycoding.tistory.com/186
* https://studymake.tistory.com/129

### 가상 상속
* 다중 상속에서 생기는 멤버 중복 생성 문제를 해결하기 위해, 상속 시 `virtual` 키워드를 사용하여 가상 상속.
* 즉, 가상 상속을 사용하면, 다이아몬드 구조로 상속받을 때 이미 할당받은 변수공간은 추가로 생성하지 않는다.

### 가상 함수와 오버라이딩
* 가상 함수를 왜 사용하나?
    ```c++
    Child c, *pC;
    pC = &c;
    pC->myfunc(); // Child::myfunc()를 호출.

    Parent *pP;
    pP = &c;
    pP->myfunc(); // Parent::myfunc()를 호출. 이를 '정적 바인딩'이라 함.
    ```
* 오버라이딩이란? 파생 클래스에서 가상 함수를 재작성하여, 기본 클래스의 가상 함수를 무력화시키는 것.
* 즉, 가상 함수를 사용하면, 위와 같은 상황에서 부모 클래스의 포인터를 이용하든 자식 클래스의 포인터를 이용하든 Child::myfunc()를 호출하게 되고, 이를 오버라이딩이라 한다.
    ```c++
    Child c, *pC;
    pC = &c;
    pC->myfunc(); // Child::myfunc()를 호출.

    Parent *pP;
    pP = &c;
    pP->myfunc(); // Child::myfunc()를 호출. 이를 '동적 바인딩'이라 함.
    ```
* 다시 말해, 가상 함수 없이 '함수 재정의'를 하면 '정적 바인딩'이 일어나고, '가상 함수를 통해 오버라이딩'을 하면 '동적 바인딩'이 일어난다.

### 오버로딩과 오버라이딩
* 오버로딩: 이름은 같지만 매개변수의 수나 타입이 다른 메서드를 중복으로 선언하는 것.
* 오버라이딩: 자식 클래스에서 부모 클래스의 가상 함수를 재정의하는 것.



## cpp04: 다형성, 추상 클래스, 인터페이스

### 다형성
* http://blog.daum.net/it-focus/143
* https://micropilot.tistory.com/3072  
* https://github.com/utilForever/modern-cpp-tutorial/blob/master/Articles/The%20Four%20Polymorphisms%20in%20C%2B%2B.md
    > * 서브타입 다형성: 런타임에 가상 테이블을 통해 이뤄지므로, '런타임 다형성'이라고도 한다. Base 클래스의 포인터나 레퍼런스로 상속 클래스를 사용하는 기능을 뜻한다. 가상 함수를 오버라이딩해서 구현한다.  
    > * 매개변수 다형성: 컴파일 타임에 이뤄지므로, '컴파일 타임 다형성'이라고도 한다. 템플릿을 통해 구현한다.  
    > * 임시 다형성: 오버로딩  
    > * 강제 다형성: 캐스팅  

### 추상 클래스
* 순수 가상 함수: `virtual void attack() const = 0;`의 형식. 클래스 내에서 구현하지 않고, 상속 클래스에서 구현한다.
* 추상 클래스: 순수 가상 함수를 하나 이상 가지는 클래스. 상속을 위한 기본 클래스로, 인스턴스화가 불가능.

### 인터페이스
소멸자와 순수가상함수만 선언된 클래스

### 공부가 필요한 부분
* [ ] getter을 써야만 하는 경우?
    ```c++
    PlasmaRifle::PlasmaRifle(const PlasmaRifle& ref)
    :   AWeapon(ref.getName(), ref.getDamage(), ref.getAPCost()) // 얘는 왜 그냥 ref.name_이 안되고 getter을 써야하는걸까?
    {}

    Enemy::Enemy(const Enemy& ref)
    :   hp_(ref.hp_),
        type_(ref.type_) // 얘는 getter을 안써도 되는데. 무슨 차이?
    {}
    ```
* [ ] 상속 시, 부모 클래스의 생성자가 실행되는 듯.  
초기화리스트에서 생성자를 지정해주지 않으면, 기본생성자가 실행된다.  
이 때, 부모 클래스의 생성자가 private이면 컴파일 오류.  
컴파일 오류를 피하기 위해서는 private을 protected로 바꾸거나, 초기화 리스트에서 기본생성자가 아닌 다른 생성자를 지정해주어야 한다.



## cpp05: 예외

### try catch exception
* https://egg-money.tistory.com/205
* https://blog.hexabrain.net/179

### 두 클래스가 서로를 사용할 때
* A 클래스와 B 클래스가 멤버함수에서 서로 매개변수로 참조한다고 하자. 이 경우, `error unknown type name 'A'`, `error unknown type name 'B'` 등의 오류가 발생한다.
* 따라서 한 클래스에 프로토타입을 먼저 선언한 후, 클래스의 정의가 끝나면 헤더파일을 포함시켜야 한다.
    ```c++
    class B; // 프로토타입
    class A
    {
        ... // B와 관련된 내용
    };
    # include "B.hpp" // 이후에 헤더파일 포함
    ``` 

### const char*
* `char* str = "hello world!";`을 컴파일하면 `ISO C++11 does not allow conversion from string literal to 'char*'` 오류가 발생한다.
* 따라서 const를 붙여서, `const char* str = "hello world!";`와 같이 해주어야 한다.
* [ ] 한편, 여러줄의 선언은 다음과 같이 한다. 여러 방법이 있는 것 같다.
    ```c++
    const char *TREE =
    {
        "\n"
        "    oxoxoo    ooxoo \n"
        "  ooxoxo oo  oxoxooo \n"
        " oooo xxoxoo ooo ooox \n" 
        " oxo o oxoxo  xoxxoxo \n"
        "  oxo xooxoooo o ooo \n"
        "    ooo\\oo\\  /o/o \n"
        "        \\  \\/ / \n"
        "         |   / \n"
        "         |  | \n"
        "         | D| \n"
        "         |  | \n"
        "         |  | \n"
        "  ______/____\\____ \n"
    };
    ```



## cpp06: 캐스트(형변환)

### 캐스트, 캐스팅
* https://eastroot1590.tistory.com/entry/C-%ED%83%80%EC%9E%85-%EC%BA%90%EC%8A%A4%ED%8C%85
* https://mynameisdabin.tistory.com/20
* https://doitnow-man.tistory.com/215

### float vs double
* https://codingdog.tistory.com/entry/c%EC%96%B8%EC%96%B4-double%ED%98%95-vs-float%ED%98%95-%EC%96%B4%EB%96%A4-%EC%B0%A8%EC%9D%B4%EA%B0%80-%EC%9E%88%EC%9D%84%EA%B9%8C%EC%9A%94<br>
    > 정확도의 차이

### 변수 타입 확인
`std::cout << typeid(<변수>).name() << std::endl;`

### 소수점 자리수 출력
* https://pmoncode.tistory.com/20
* https://semaph.tistory.com/7
* https://boycoding.tistory.com/152
    > `std::cout << std::fixed; std::cout.precision(1);`

### 자료형의 크기 및 범위
* https://myblog.opendocs.co.kr/archives/1230
    > int는 4바이트, char는 1바이트.

### 난수 생성
* https://modoocode.com/304
    > 다른 사람들의 풀이에서 `rand()`가 잘 보이지 않는 이유.

### 정수 제한
* https://docs.microsoft.com/ko-kr/cpp/c-language/cpp-integer-limits?view=vs-2019
    > C++ 표준 라이브러리 헤더 `<limits>`에 정수 제한 상수가 정의되어 있다.
* https://riptutorial.com/ko/cplusplus/example/15879/%EC%88%AB%EC%9E%90-%ED%98%95%EC%9D%98-%EB%B2%94%EC%9C%84
    > `std::numeric_limits<int>::min()`  
    > `INT_MIN`은 안되나? `INT32_MIN`, `INT64_MIN` 등은 뭐지? 내가 아는 int의 최소값은 `INT32_MIN`이던데...



## cpp07: 템플릿

### 템플릿
* https://thrillfighter.tistory.com/408
    > 템플릿이란? 함수나 클래스를 만들 수 있는 틀.

    > 템플릿 문법
    > ```c++
    > template <typename T>
    > T myFunc(T a, T b)
    > {
    >     return a + b;
    > }
    > ```

### 템플릿 사용
* `myfunc<int>(a, b)`
* `myfunc(a, b)`
* `::myfunc(a, b)`
* 첫 번째는 std::stirng을 넣는 경우, `error: call to 'swap' is ambiguous` 오류가 뜨는 경우가 있었음. 왜?
* 두 번째는 컴파일러가 알아서 자료형을 판별한다고 함.
* 세 번째는 두 번째랑 같은 것 아닐까? 네임스페이스가 없어서 저런 형태가 아닐까 추측.

### 함수 포인터
* https://boycoding.tistory.com/233
* https://m.blog.naver.com/PostView.nhn?blogId=tipsware&logNo=221619466275&proxyReferer=https:%2F%2Fwww.google.com%2F
* https://aahc.tistory.com/17
    > 함수의 이름 자체가 하나의 함수 포인터. (그래서 매개변수로 넘겨줄 수 있는건가?)

    > 함수 포인터는 참조하거나 역참조해도 여전히 같은 기능을 수행함.
    > ```c++
    > // 아래는 전부 같은 기능을 하는 코드임.
    > fun_ptr = &fun;
    > fun_ptr = fun;
    > fun_ptr = *fun;
    > fun_ptr = **fun;
    > ```

### 클래스 템플릿
* http://tcpschool.com/cpp/cpp_template_class
* https://blockdmask.tistory.com/45
    > 멤버함수가 클래스 외부에서 선언되면, 다시 템플릿 선언을 해주어야 함.
    > ```c++
    > template <typename T>
    > Array<T>::Array()
    > {
    >     ...
    > }
    > ```

### typename vs class
* https://hashcode.co.kr/questions/554/%ED%85%9C%ED%94%8C%EB%A6%BF%EC%97%90%EC%84%9C-typename%ED%82%A4%EC%9B%8C%EB%93%9C%EC%99%80-class%ED%82%A4%EC%9B%8C%EB%93%9C%EC%9D%98-%EC%B0%A8%EC%9D%B4

### 클래스 템플릿의 멤버함수는 헤더파일에서 구현
* cpp 파일을 따로 만들어서 구현하면 `undefined reference to `Array<int>::Array(unsigned int)'`의 에러가 뜬다.
* 따라서 헤더파일 내에서 멤버함수를 구현해야 하는 듯.

### 배열의 기본 초기화
```c++
int* a = new int;
std::cout << *a << std::endl; // 0으로 초기화
// std::cout << a << std::endl; // int* a의 주소

char* b = new char;
std::cout << (int) *b << std::endl; // 0으로 초기화
```
기본으로 0으로 초기화된다.

### int* array = new int[0];
* https://stackoverflow.com/questions/1087042/c-new-int0-will-it-allocate-memory
* https://roybatty.tistory.com/14
    > `int* array = new int[0];`은 크기가 0인 배열(NULL이 아님) 할당. 그러나 역참조(*array)의 동작은 정의되어 있지 않음.  
    > `delete[]`는 NULL에 대해 동작 취하지 않으므로 안전(권장하지는 않음). 크기가 0인 배열 또한 안전.



## cpp08: 컨테이너, 반복자(iterator), 알고리즘

### exception 클래스
* https://docs.microsoft.com/ko-kr/cpp/standard-library/exception-class?view=vs-2019

### C++ 표준 라이브러리 컨테이너
* https://docs.microsoft.com/ko-kr/cpp/standard-library/stl-containers?view=vs-2019
* https://min-zero.tistory.com/entry/C-STL-2-1-%EB%B0%98%EB%B3%B5%EC%9E%90-%EB%B0%98%EB%B3%B5%EC%9E%90iterator
    > 컨테이너, 반복자, 알고리즘 종류

### array
* https://boycoding.tistory.com/213

### map
* https://blockdmask.tistory.com/87
* https://twpower.github.io/91-how-to-use-map-in-cpp
    > pair 객체로 다룬다. `it->first`, `it->second` 이런 식으로 key나 value에 접근.
* https://hugman.tistory.com/entry/C-map%EC%97%90%EC%84%9C-find-%EB%A5%BC-%EC%9D%B4%EC%9A%A9%ED%95%B4%EC%84%9C-%EC%97%86%EB%8A%94-%ED%95%AD%EB%AA%A9-%EC%B0%BE%EA%B8%B0
    > map의 find 메서드 사용법
* https://en.cppreference.com/w/cpp/utility/pair
    > pair 객체

### sort
* https://blockdmask.tistory.com/178

### stack
* https://kldp.org/node/71479
    > stack이나 queue는 컨테이너에 대한 접근을 제한하는 어댑터. 즉, 컨테이너 어댑터이다.
* https://stackoverflow.com/questions/38136137/does-stack-have-iterators-in-c
    > stack에는 반복자가 없으나, 상속을 통해 protected 멤버인 c(the underlying container)에 접근해서 반복자를 사용하는 클래스를 만들 수 있음. (예제 포함)
* https://docs.microsoft.com/ko-kr/cpp/standard-library/stack-class?view=vs-2019
    > container_type이란 기본 컨테이너. 즉 `std::deque<T>` 인 듯?

### auto
* https://boycoding.tistory.com/184
    > 값에 맞춰서 변수의 형식이 자동으로 결정되는 타입 추론 기능.

### iterator
* https://egg-money.tistory.com/200
* https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=60208809639&proxyReferer=https:%2F%2Fwww.google.com%2F
* `begin()`, `cbegin()`, `rbegin()`, `crbegin`
    * `cbegin()`: const_iterator 반환. 포인터는 변경 가능하나, 포인터가 가르키는 값이 변경 불가능.
        ```c++
        auto it = mst.cbegin();
        std::cout << *it << std::endl;
        it++; // 변경 가능.
        std::cout << *it << std::endl;
        // *it += 10; // 포인터가 가르키는 값 변경 불가능(컴파일 에러).
        ```
    * `rbegin`: 뒤집어진 순서로 반환.
        ```c++
        // mst에 {1,2,3} 저장된 상태
        for (auto it = mst.rbegin(); it < mst.rend(); it++)
            std::cout << *it << std::endl; // 3 2 1 출력
        ```

### ipp 확장자
* https://simcho999.blogspot.com/2018/01/c-cpp-h-hpp-c.html
    > 헤더의 정의는 hpp, 템플릿의 정의는 tpp, 인라인 함수 정의는 ipp에?



## C++ 참고 사이트

### 공식
* https://en.cppreference.com/w/
* http://www.cplusplus.com/

### 준 공식
* https://www.ibm.com/support/knowledgecenter/ko/ssw_ibm_i_73/rzahg/rzahgcandcplus.htm
* https://riptutorial.com/ko/cplusplus
* https://modoocode.com/143
* https://www.cppkorea.org/CppCoreGuidelines/home/

### 그 외
* https://boycoding.tistory.com/category/C%2B%2B%20%EC%9D%B4%EC%95%BC%EA%B8%B0