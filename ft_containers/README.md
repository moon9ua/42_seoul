# ft_containers

## 참고

### 레퍼런스
* https://www.cplusplus.com/
* https://en.cppreference.com/w/
* https://docs.microsoft.com/ko-kr/cpp/standard-library/
* https://modoocode.com/
* https://runebook.dev/ko/docs/cpp/-index-
* https://www.cppkorea.org/CppCoreGuidelines/
* https://gcc.gnu.org/onlinedocs/gcc-4.6.2/libstdc++/api/a00588.html ⭐️
* https://docs.microsoft.com/ko-kr/cpp/standard-library/cpp-standard-library-header-files?view=msvc-160

### 읽어보면 좋을 글들
* https://ehclub.co.kr/1213?category=656403
* https://narss.tistory.com/entry/new%EC%97%90-%EB%8C%80%ED%95%B4%EC%84%9C?category=617883 : Advanced C++
* https://devsophia.tistory.com/entry/STL-%ED%9B%91%EC%96%B4%EB%B3%B4%EA%B8%B0-01-%ED%85%9C%ED%94%8C%EB%A6%BF-%EC%BB%A8%ED%85%8C%EC%9D%B4%EB%84%88-%EB%B0%98%EB%B3%B5%EC%9E%90?category=779494 : 꺼내먹어요/C++
* https://supark7.tistory.com/entry/22-%EC%BB%A8%ED%85%8C%EC%9D%B4%EB%84%88-C-Idioms-Thin-Template?category=509074 : 디자인패턴
* https://ehpub.co.kr/category/programming-language/%eb%94%94%eb%94%a4%eb%8f%8c-c/ : 디딤돌 C++
* https://docs.microsoft.com/ko-kr/cpp/cpp/?view=msvc-160
* https://blog.hexabrain.net/category/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EA%B4%80%EB%A0%A8/C/C%2B%2B : C++ 강좌
* http://www.soen.kr/
* http://www.martinbroadhurst.com/stl/table_of_contents.html
* http://ajwmain.iptime.org/programming/book_summary/%5B02%5Deffective_stl/effective_stl.html : effective C++, effective STL
* https://c-annotationskr.sourceforge.io/cplusplus.html : C++ 주해서

## 공부 내용

### std와 stl
* *std*
    * https://ko.wikipedia.org/wiki/C%2B%2B_%ED%91%9C%EC%A4%80_%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC
* *stl*
    * https://namu.wiki/w/%ED%91%9C%EC%A4%80%20%ED%85%9C%ED%94%8C%EB%A6%BF%20%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC
        > * STL은 컨테이너, 반복자, 알고리즘의 3가지로 구성.
* ❓ stl인지 std인지 어떻게 알지?

### vector
* https://lazyren.github.io/devlog/vector.html
* https://ehpub.co.kr/3-1-vector/
    > * 배열은 같은 종류의 자료를 연속적인 메모리에 보관하는 자료구조.
    > * 배열은 원소의 개수를 변경할 수 없는 한계를 가짐.
    > * vector은 동적으로 연속적인 메모리에 할당. 배열의 크기를 신경 안써도 됨.
* https://ehpub.co.kr/vector/
* https://hyeonstorage.tistory.com/324 ⭐️
* https://modoocode.com/178 ⭐️
    > * default 생성자: 빈 벡터를 생성한다. (size는 0)
    > * fill 생성자: 값이 T인 원소를 n개 가지는 벡터를 생성한다.
    > * range 생성자: first부터 last까지 순회하며, 각 원소를 벡터의 원소로 취한다.
    > * copy 생성자: 벡터 x와 동일한 원소(복사본)를 가지는 벡터를 생성한다.
* https://woodforest.tistory.com/206
* https://2jinishappy.tistory.com/67
* *size vs capacity vs max_size*
    * https://sollu.wordpress.com/2010/03/25/stl-vector-size-vs-capacity-vs-max_size/
    * http://www.java2s.com/Code/Cpp/Vector/vectormaxsizesizecapacity.htm

### list
* https://ssinyoung.tistory.com/46
    > * list는 이중 연결리스트.
* https://blockdmask.tistory.com/76
* https://kswims.tistory.com/136
* https://ehclub.co.kr/1236
* https://stackoverflow.com/questions/34875315/implementation-my-own-list-and-iterator-stl-c
* https://gist.github.com/DaeGwang/5125a7aaf7273bf56c6cb95a97652f5f

### map
* https://modoocode.com/224
* 레드블랙트리
    * https://itstory.tk/entry/%EB%A0%88%EB%93%9C%EB%B8%94%EB%9E%99-%ED%8A%B8%EB%A6%ACRed-black-tree
* https://stackoverflow.com/questions/18414579/what-data-structure-is-inside-stdmap-in-c

### allocator(할당자)
* https://woo-dev.tistory.com/51 ⭐️
    > * `<memory>` 헤더에 존재. 유연한 메모리 관리를 위한 클래스.  
    > * 메모리 동적 할당 및 해제에는 new/delete를 사용하는데, allocator은 라이브러리를 작성할 때(특히 표준 라이브러리의 컨테이너를 구현할 때) 세밀한 사용을 위해 사용된다.  
    > * `T* allocate(size_t);`: 메모리 할당  
    > * `void deallocate(T*, size_t);`: 메모리 해제  
    > * `void construct(T*, const T&);`: 요소 저장  
    > * `void destory(T*);`: 객체 소멸
* https://m.blog.naver.com/PostView.nhn?blogId=et3569&logNo=130118830696&proxyReferer=https:%2F%2Fwww.google.com%2F 
    > * allocator란? 메모리의 할당과 해제를 담당하는 객체.  
    > * STL 컨테이너 템플릿들은 메모리 관리에 이용할 allocator 객체를 인자로 받는다.  
    > * `template < class T, class Alloc = std::allocator<T> > class list {...}`  
* https://openmynotepad.tistory.com/57?category=854742
* https://openmynotepad.tistory.com/58

### explicit
* https://dydtjr1128.github.io/cpp/2019/07/13/Cpp-explicit-keyowrd.html
* https://hyeonstorage.tistory.com/313

### iterator
* vector iterator는 전체적으로 다음을 보고 구현하였다.
    * https://www.cplusplus.com/reference/iterator/RandomAccessIterator/
    * https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
    * https://www.cplusplus.com/reference/iterator/reverse_iterator/
* https://mayple.tistory.com/entry/CSTL2%EC%9E%A5-%EB%B0%98%EB%B3%B5%EC%9E%90iterator
* https://devsophia.tistory.com/entry/%EB%B0%98%EB%B3%B5%EC%9E%90%EB%A5%BC-%EC%A7%81%EC%A0%91-%EC%A0%95%EC%9D%98%ED%95%98%EA%B3%A0-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0
    > 내가 아직 공부하지 않은 iterator_traits에 대한 내용.
* http://www.soen.kr/lecture/ccpp/cpp4/39-2-6.htm

### iterator의 카테고리
* https://narss.tistory.com/entry/%EB%B0%98%EB%B3%B5%EC%9E%90-%EC%B9%B4%ED%85%8C%EA%B3%A0%EB%A6%ACiterator-category ⭐️
    > iterator의 카테고리란?  
    > * iterator은 다섯가지의 종류로 나누어지며, 각 iterator은 제공하는 연산자의 종류가 다르다.  
    >   1. 입력 반복자: 입력, ++연산자
    >   2. 출력 반복자: 출력, ++연산자
    >   3. 전진형 반복자: 입/출력, ++연산자
    >   4. 양방향 반복자: 입/출력, ++연산자, --연산자
    >   5. 임의접근 반복자: 입/출력, ++연산자, --연산자, +연산자, -연산자, []연산자
    > * ex) singly linked-list의 반복자는 전진형. doubly linked-lisk의 반복자는 양방향. vector나 배열과 같은 연속된 메모리의 반복자는 임의접근.

    > 반복자 카테고리를 왜 분류하였는가?
    > * 컨테이너의 반복자 카테고리를 알면, 해당 컨테이너에 적용 가능한 알고리즘 함수를 판별할 수 있다.
    > * ex) list는 양방향 반복자를 지원하므로, 알고리즘의 reverse 함수가 사용 가능하다. 하지만 sort 함수는 사용 불가능하다. 따라서 list는 sort를 멤버함수로 따로 구현하고 있다. 즉, sort 메서드(내부적으로도 구현 방법이 다름)를 사용해야 한다.
    > * 즉, STL의 알고리즘 함수를 지원하는 반복자를 가지는 컨테이너는 해당 함수를 따로 구현할 필요가 없으며, 그렇지 않은 경우 따로 구현해야 하거나 메서드를 사용해야 한다.
* http://www.tcpschool.com/cpp/cpp_iterator_category

### iterator의 operator
* *operator->*
    * https://www.codentalks.com/t/topic/8397
    * https://stackoverflow.com/questions/9007775/how-to-implement-operator-for-iterator-type
        > ❓ const도 해줘야 하나? 아직 const 부분이 헷갈린다.
* *전치/후치 증감 연산자*
    * https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=60205596079&proxyReferer=https:%2F%2Fwww.google.com%2F ⭐️
    * https://stackoverflow.com/questions/9386266/overloading-the-operator-to-increment-an-iterator

### const_iterator
* https://nedy.tistory.com/30
    > const value_type을 가리키는 iterator.  
    > 즉, iterator은 변경 가능(`it++`), iterator가 가리키는 값은 변경 불가능(`*it += 1`).  
* https://pythonq.com/so/c%2B%2B/1600510
* https://pythonq.com/so/c%2B%2B/11500
* https://yonomi.tistory.com/380
* https://stackoverflow.com/questions/7758580/writing-your-own-stl-container/7759622#7759622 ⭐️
* https://stackoverflow.com/questions/3582608/how-to-correctly-implement-custom-iterators-and-const-iterators ⭐️
* https://stackoverflow.com/questions/2150192/how-to-avoid-code-duplication-implementing-const-and-non-const-iterators/41306206#41306206 ⭐️

### reverse_iterator
* https://www.daniweb.com/programming/software-development/threads/76622/need-help-writing-my-own-reverse-iterator-class
* http://www.martinbroadhurst.com/stl/table_of_contents.html
* http://cplusplus.com/forum/beginner/196504/
* https://docs.microsoft.com/ko-kr/cpp/standard-library/reverse-iterator-class?view=msvc-160
* https://www.python2.net/questions-37187.htm
* https://www.slideshare.net/HyunJoonPark6/c-advanced-4-77458324
* https://nekoplu5.tistory.com/90
* https://docs.microsoft.com/ko-kr/cpp/standard-library/vector-class?view=msvc-160#const_iterator
* *base()*
    * http://egloos.zum.com/sweeper/v/2970390

### friend
* https://genesis8.tistory.com/98
* *연산자 오버로딩 friend*
    * https://thrillfighter.tistory.com/283
    * https://choryeonworkshop.tistory.com/130
* https://blog.hexabrain.net/172
* https://en.cppreference.com/w/cpp/language/friend
* https://hombody.tistory.com/312
* http://www.tcpschool.com/cpp/cpp_encapsulation_friend
* https://stackoverflow.com/questions/8967521/class-template-with-template-class-friend-whats-really-going-on-here/8967610
* https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=60205572356&proxyReferer=https:%2F%2Fwww.google.com%2F
* https://min-zero.tistory.com/entry/C-%EA%B8%B0%EB%B3%B8-%EA%B3%B5%EB%B6%80%EC%A0%95%EB%A6%AC-15-1-OOP-%EC%BA%A1%EC%8A%90%ED%99%94-%ED%94%84%EB%A0%8C%EB%93%9Cfriend

### 연산자 오버로딩
* https://blog.hexabrain.net/177
* https://mandy8303.tistory.com/53
* https://mandy8303.tistory.com/57?category=762830

### 전방 선언
* `error: use of undeclared identifier 'ft'`
* https://stackoverflow.com/questions/22197030/what-is-an-undeclared-identifier-error-and-how-do-i-fix-it
* https://boycoding.tistory.com/143
    > 전방 선언과 정의
* https://gpgstudy.com/forum/viewtopic.php?t=20355
    > 템플릿 클래스의 전방 선언 `template < class T, class Alloc > class vector;`
* https://jacking.tistory.com/899
    > 다른 namespace 안에 있는 클래스 전방 선언

### 템플릿
* https://int-i.github.io/cpp/2020-03-11/cpp-template-review/
    > * class 키워드는 어감으로 인해 비권장되며, typename이 이를 대체하게끔 권장된다.  
    > * 함수, 클래스, 구조체(struct) 등에 템플릿을 사용할 수 있다.
    > * 비타입(non-type) 템플릿 인자: typename처럼 자유로운 형식이 아니라, 형식을 정해져있는 인자.
* https://stackoverflow.com/questions/23711389/template-with-bool-parameter
    > bool 인자를 이용해 타입을 정하게 하는 방법은 다음과 같다.
    > * std::conditional을 이용한다. -> 규칙에 위반된다. 따라서 공부하진 않았다.
    > * template specialization를 이용한다. -> 이 방법을 사용하였다.
* *템플릿 클래스 상속*
    * https://m.blog.naver.com/PostView.nhn?blogId=vjhh0712v&logNo=221561418596&proxyReferer=https:%2F%2Fwww.google.com%2F
* *템플릿 friend*
    * https://blog.plorence.kr/528

### 예외
* *strong guarantee*
    * https://docs.microsoft.com/ko-kr/cpp/cpp/how-to-design-for-exception-safety?view=msvc-160
    * https://m.blog.naver.com/PostView.nhn?blogId=mug896&logNo=140168091611&proxyReferer=https:%2F%2Fwww.google.com%2F
        > * strong guarantee: 예외가 발생했을 때, 오브젝트가 함수 수행 전 상태로 보존되는 것을 보장.
    * https://banaba.tistory.com/2
* *std::out_of_range*
    * https://www.cplusplus.com/reference/stdexcept/out_of_range/

### enable_if
* https://hellobird.tistory.com/135
* https://bckim.com/posts/cpp11-std-enable_if/
* https://modoocode.com/255
* https://modoocode.com/295

### 출력 스타일 지정하기
* *색상*
    * http://www.gisdeveloper.co.kr/?p=9772
    * https://sonseungha.tistory.com/474
* *포맷*
    * https://m.blog.naver.com/PostView.nhn?blogId=ahalinux&logNo=220856924222&proxyReferer=https:%2F%2Fwww.google.com%2F
    * https://doitnow-man.tistory.com/234
    * https://m.blog.naver.com/PostView.nhn?blogId=start3535&logNo=30146765701&proxyReferer=https:%2F%2Fwww.google.com%2F
    * https://repilria.tistory.com/243

### 헤더 파일 중복
* https://yesarang.tistory.com/64
* hpp 파일들을 어떻게 구성해야 하는지에 어려움을 겪었다.  
    순서나 위치를 잘 못 하면 컴파일이 되지 않았다. 어떻게 정리하는 것이 보편적인 스타일인지 공부가 필요하다.  

### vector의 capacity 증가 매커니즘
* *reserve*
    * clang++의 경우, arg만큼 capacity를 배정한다.
* *resize*
    * clang++의 경우, 두배씩 늘어나는 것을 확인할 수 있다.
    * https://stackoverflow.com/questions/48537812/why-does-stdvector-reserve-not-double-its-capacity-while-resize-does
    > 다시 말해, reserve(n)은 capacity가 n이 되지만, resize(n)은 capacity가 현재 값의 두배가 된다.
* *push_back*
    * https://stackoverflow.com/questions/45403052/when-does-a-stdvector-enlarge-itself-when-we-push-back-elements
        ```
        std::vector<int> v;
        unsigned long previouscapacity = 0;
        for (unsigned int i = 0; i < 10; i++)
        {
            v.push_back(i);
            if (v.capacity() != previouscapacity)
            {
                std::cout << "new capacity: " << v.capacity() << " new size: " << v.size() << " ratio: " << ((float) v.capacity()) / previouscapacity << '\n';
                previouscapacity = v.capacity();
            }
        }
        /*
        new capacity: 1 new size: 1 ratio: inf
        new capacity: 2 new size: 2 ratio: 2
        new capacity: 4 new size: 3 ratio: 2
        new capacity: 8 new size: 5 ratio: 2
        new capacity: 16 new size: 9 ratio: 2
        */
        ```
    * clang++의 경우, 두배씩 늘어나는 것을 확인할 수 있다. 
* *assign*
    * clang++의 경우, 할당하는 요소 수만큼 capacity를 새로 할당한다.
* *그 외 읽어볼만한 글*
    * https://stackoverflow.com/questions/1100311/what-is-the-ideal-growth-rate-for-a-dynamically-allocated-array
        > 대충 대부분의 컴파일러에서는 capacity + capacity / 2 로 증가한다는 내용.

### error: use of undeclared identifier 'pos_'
* https://stackoverflow.com/questions/22197030/what-is-an-undeclared-identifier-error-and-how-do-i-fix-it
    > private한 멤버 변수에 직접 접근할 수 없어 발생하는 에러.  
    > ❗️ `&(*pos_)`로 해결.

### READ of size 4 at ... thread T0 (heap-buffer-overflow)
* https://stackoverflow.com/questions/51579267/addresssanitizer-heap-buffer-overflow-on-address
    > fsanitizer=address 옵션이 무엇인지, heap-buffer-overflow가 무엇인지 설명하는 글.

### error: overloaded 'operator+' must be a unary or binary operator (has 3 parameters)
* https://stackoverflow.com/questions/13554320/overloaded-operator-must-be-a-unary-or-binary-operator-error
    > 연산자의 인자가 3개라는 에러.  
    > ❗️ friend를 붙여 해결.

### vector와 list의 기본 생성자의 차이
* 왜 이런 차이가 있는 것이지? list는 head가 할당돼서 그런가?
    ```c++ 
    std::list<int> lst;
    std::cout << *(lst.begin()) << std::endl;
    // 컴파일이 되며, 0을 출력.

    std::vector<int> vec; // 오류!
    std::cout << *(vec.begin()) << std::endl;
    // 컴파일 자체가 안됨. "불완전한 형식은 사용할 수 없습니다." 오류.
    ```
* ❗️ vector에서는 기본 생성자 시에 0만큼 할당되므로, 실질적으론 할당되지 않는다. 따라서 접근 불가능.  
    하지만 list에서는 기본 생성자 시에 1만큼(dummy) 할당되므로, 접근 가능한 것 같다.  
* 왜 다 0이 출력될까?
    ```c++
    std::list<int> lst;
    for (int i = 0; i < 10; i++)
        std::cout << *(lst.begin()++) << std::endl; // 0이 10번 출력.
    ```
* ❗️ 처음에 생성된 더미의 val이 T()이며, dummy의 prev와 next가 dummy 자기 자신이기 때문인 듯. 

### iterator의 쓰기 연산자(*it=x)는 어떻게 정의하는가
* 쓰기 연산자가 대입 연산자와 같은 것인 줄 알았으나 아닌 것 같다. 어떻게 정의하나?  
    예를 들어, 출력 반복자에는 쓰기 연산자가 제공된다. 순방향 반복자에는 이에 더불어 대입 연산자가 제공된다.  
    또한, 입력 반복자에는 읽기 연산자는 있지만 쓰기 연산자는 없다.  
    완전히 구분되는 것 같은데, 나는 아직 이를 따로 정의해본 적이 없다. 어떻게 이것을 컨트롤하는걸까?

### 반복문에서 전위 연산자, 후위 연산자 주의할 점
```c++
int i = 0;
while (i++ != 5)
{
    std::cout << i;
} // 12345 출력

int i = 0;
while (i != 5)
{
    std::cout << i;
    i++;
} // 01234 출력
```
위의 두 결과가 같다고 착각하면 안된다.  
조건문의 줄에서 탈출하면 증가하므로, 조건문 내부에는 증가한 변수가 전달된다.

### error: no viable conversion from 'list_iterator<[...], true, [...]>' to 'list_iterator<[...], false, [...]>'
```c++
list& operator= (const list& x)
{
    if (this != &x)
    {
        // iterator it = x.begin(); // 컴파일 오류!
        const_iterator it = x.begin(); // 컴파일 성공.
        while (it != x.end())
        {
            push_back(*it);
            it++;
        }
    }
    return (*this);
}
```
list& 가 아니라 const list& 이므로 그런 것 같다.  
❓ const list& 라는 것은 무엇일까? 내용이 아예 수정 불가능 한 것인가?  
❓ 그리고 레퍼런스에서는 const 위치에 따라 달라지는게 있나?  
* https://stackoverflow.com/questions/15644938/what-does-in-instantiation-of-required-from-here-mean

### iterator와 const_iterator은 어떻게 선택되는가
```c++
iterator begin()
{
    return (iterator(dummy_->next_));
}
const_iterator begin() const
{
    return (const_iterator(dummy_->next_));
}
```
begin()은 iterator와 const_iterator 중 어떻게 선택되는가.  
1. `iterator it = a.begin()`, `const_iterator it = a.begin()`와 같은 식으로, 리턴 값이 정해질 때에는 그 값에 맞게 컴파일되는 것 같다.
2. 하지만 위에서 에러가 났던 것 처럼, 객체에 따라 정해질 때도 있는 듯.
오버로딩에 대해 (특히 const) 더 공부가 필요하다.
* https://stackoverflow.com/questions/42580761/why-does-stdbegin-always-return-const-iterator-in-such-a-case
* https://stackoverflow.com/questions/47794223/getting-const-iterator-from-begin-instead-of-cbegin

### 클래스 내에서 operator 함수를 사용할 때
```c++
list (const list& x)
: dummy_(init_dummy()), size_(0), alloc_(std::allocator<T>()),
node_alloc_(std::allocator<node>())
{
    *this = x; // 이렇게?
    // operator=(x); // 위와 같은 표현인가?
}
```

### 소멸자
* alloc_.destroy는 왜 쓰는가. -> 아마 T가 클래스인 경우 소멸자를 호출하기 위해서일 듯.
* ❓ 소멸자가 제대로 작동하는지는 어떻게 확인하나?

### 오버로딩 시 템플릿 함수 선택을 방지하는 방법: enable_if
```c++
template <class InputIterator>
void assign (InputIterator first, InputIterator last,
            typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = nullptr)
{
    clear();

    InputIterator it(first);
    while (it != last)
    {
        push_back(*it);
        it++;
    }
}
void assign (size_type n, const value_type& val)
{
    clear();

    for (size_type i = 0; i < n; i++)
        push_back(val);
}
```
enable_if 구를 안써주면 `assign(3, 42);`를 실행해도 위의 템플릿으로 컴파일돼서 다음과 같은 오류가 발생한다.  
> ./inc/list.hpp:209:31: error: indirection requires pointer operand ('int' invalid)
>                     push_back(*it);
따라서 InputIterator가 int인지 확인하기 위해 enable_if 구를 써준다.  
아직 enable_if의 정확한 작동 방법은 공부가 필요!

### predicate(서술자)
* https://modoocode.com/225
* http://occamsrazr.net/tt/entry/predicate-%EC%84%9C%EC%88%A0%EC%9E%90
* list.unique()
    ```c++
    bool same_integral_part (double first, double second) // 서술자
    { return ( int(first)==int(second) ); }

    struct is_near {
    bool operator() (double first, double second)
    { return (fabs(first-second)<5.0); }
    }; // 서술자

    int main ()
    {
        double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                            12.77, 73.35, 72.25, 15.3,  72.25 };
        std::list<double> mylist (mydoubles,mydoubles+10);
        
        mylist.sort();             //  2.72,  3.14, 12.15, 12.77, 12.77,
                                    // 15.3,  72.25, 72.25, 73.0,  73.35

        mylist.unique();           //  2.72,  3.14, 12.15, 12.77
                                    // 15.3,  72.25, 73.0,  73.35

        mylist.unique (same_integral_part);  //  2.72,  3.14, 12.15
                                            // 15.3,  72.25, 73.0

        mylist.unique (is_near());           //  2.72, 12.15, 72.25

        std::cout << "mylist contains:";
        for (std::list<double>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        return 0;
    }
    ```
* list.remove_if()
    ```c++
    bool single_digit (const int& value) { return (value<10); }

    struct is_odd {
    bool operator() (const int& value) { return (value%2)==1; }
    };

    int main ()
    {
        int myints[]= {15,36,7,17,20,39,4,1};
        std::list<int> mylist (myints,myints+8);   // 15 36 7 17 20 39 4 1

        mylist.remove_if (single_digit);           // 15 36 17 20 39

        mylist.remove_if (is_odd());               // 36 20

        std::cout << "mylist contains:";
        for (std::list<int>::iterator it=mylist.begin(); it!=mylist.end(); ++it)
            std::cout << ' ' << *it;
        std::cout << '\n';

        return 0;
    }
    ```
* ⬜️ 책으로 공부 후 정리할 것

### pair
* https://www.crocus.co.kr/597
처음부터 궁금했던 std와 stl의 구분.  
❓ pair은 stl이어서 사용 못하는 것인가? 아니면 std여서 사용 가능한 것인가?

### map의 트리 구현
* 트리를 어떻게 구현할 것인가?
* 트리의 순회 방법은 무엇인가? (예전에 이것도 공부했는데 기억이...)
* *이진트리 구현*
    * https://jizard.tistory.com/110
    * ⬜️ 책으로 공부 후 정리할 것