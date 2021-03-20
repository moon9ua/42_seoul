# ft_containers



## 참고

### 레퍼런스
* https://www.cplusplus.com/
* https://en.cppreference.com/w/
* https://docs.microsoft.com/ko-kr/cpp/standard-library/
* https://modoocode.com/
* https://ehclub.co.kr/1213?category=656403
* https://www.cppkorea.org/#/
* https://runebook.dev/ko/docs/cpp/-index-

### 읽어보면 좋을 묶음 글들
* https://narss.tistory.com/entry/new%EC%97%90-%EB%8C%80%ED%95%B4%EC%84%9C?category=617883 : Advanced C++
* https://devsophia.tistory.com/entry/STL-%ED%9B%91%EC%96%B4%EB%B3%B4%EA%B8%B0-01-%ED%85%9C%ED%94%8C%EB%A6%BF-%EC%BB%A8%ED%85%8C%EC%9D%B4%EB%84%88-%EB%B0%98%EB%B3%B5%EC%9E%90?category=779494 : 꺼내먹어요/C++
* https://supark7.tistory.com/entry/22-%EC%BB%A8%ED%85%8C%EC%9D%B4%EB%84%88-C-Idioms-Thin-Template?category=509074 : 디자인패턴
* https://ehpub.co.kr/category/programming-language/%eb%94%94%eb%94%a4%eb%8f%8c-c/ : 디딤돌 C++
* https://docs.microsoft.com/ko-kr/cpp/cpp/?view=msvc-160
* https://blog.hexabrain.net/category/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D%20%EA%B4%80%EB%A0%A8/C/C%2B%2B : C++ 강좌
* http://www.soen.kr/ ⭐️



## 공부 내용

### allocator 클래스
* https://docs.microsoft.com/ko-kr/cpp/standard-library/allocator-class?view=msvc-160
* https://woo-dev.tistory.com/51 ⭐️
    > * `<memory>` 헤더에 존재. 유연한 메모리 관리를 위한 클래스.  
    > * 메모리 동적 할당 및 해제에는 new/delete를 사용하는데, allocator은 라이브러리를 작성할 때(특히 표준 라이브러리의 컨테이너를 구현할 때) 세밀한 사용을 위해 사용된다.  
    > * `T* allocate(size_t);`: 메모리 할당  
    > * `void deallocate(T*, size_t);`: 메모리 해제  
    > * `void construct(T*, const T&);`: 요소 저장  
    > * `void destory(T*);`: 객체 소멸
* ❓ deallocate와 destroy의 차이점 및 사용법은?
* https://m.blog.naver.com/PostView.nhn?blogId=et3569&logNo=130118830696&proxyReferer=https:%2F%2Fwww.google.com%2F
    > * allocator란? 메모리의 할당과 해제를 담당하는 객체.  
    > * STL 컨테이너 템플릿들은 메모리 관리에 이용할 allocator 객체를 인자로 받는다.  
    > * `template < class T, class Alloc = std::allocator<T> > class list {...}`  
* http://www.cplusplus.com/reference/memory/allocator/construct/
* https://openmynotepad.tistory.com/57?category=854742
* https://openmynotepad.tistory.com/58
* https://challengeok.tistory.com/31

### std와 stl
* *std*
    * https://ko.wikipedia.org/wiki/C%2B%2B_%ED%91%9C%EC%A4%80_%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC
* *stl*
    * https://namu.wiki/w/%ED%91%9C%EC%A4%80%20%ED%85%9C%ED%94%8C%EB%A6%BF%20%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%AC
        > * STL은 컨테이너, 반복자, 알고리즘의 3가지로 구성.
* ❓ stl인지 std인지 어떻게 알지?

### explicit
* https://dydtjr1128.github.io/cpp/2019/07/13/Cpp-explicit-keyowrd.html
* https://hyeonstorage.tistory.com/313

### iterator
* *iterator*
    * https://narss.tistory.com/entry/%EC%BB%A8%ED%85%8C%EC%9D%B4%EB%84%88-%EB%B0%98%EB%B3%B5%EC%9E%90?category=617883
    * https://mayple.tistory.com/entry/CSTL2%EC%9E%A5-%EB%B0%98%EB%B3%B5%EC%9E%90iterator
    * https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html : 영어라...
* *iterator 구현*
    * https://devsophia.tistory.com/entry/%EB%B0%98%EB%B3%B5%EC%9E%90%EB%A5%BC-%EC%A7%81%EC%A0%91-%EC%A0%95%EC%9D%98%ED%95%98%EA%B3%A0-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0 ⭐️
        > STL의 알고리즘은 컨테이너가 아닌 반복자만 받아서 처리한다. 알고리즘은 어떻게 반복자가 가리키는 타입을 추론하는 것인가?  
        > (다시 읽어보자. 정확히 이해 못했다.)
* *reverse_iterator*
    * https://hyeonstorage.tistory.com/322
* 왜 컨테이너마다 iterator을 따로 구현하는가? iterator은 어디서 참고하지? 어디까지 구현해야하지?
    > 컨테이너의 Member types을 참고해 만들면 된다. 어디까지 구현해야 하는지는 iterator의 카테고리를 보면 된다.

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
* 그렇다면 컨테이너 별로 반복자를 만들 것이 아니라, 반복자 카테고리 별로 만드는 것이 낫지 않나?
    > 일단 원래 C++ 자체에서도 반복자 종류들은 빈 클래스로 정의되어 있고, 오버로딩해서 쓰는 것 같다.  
    > 내겐 너무 어려우므로 최대한 간소화하는 방향으로 가보자.  
    > 하지만 무엇을 기준으로, 어디서 어디까지 해야하나?  
    > 아마 (vector의 경우) random_access_iterator_tag 페이지의 모든 것들을 구현하면 될 듯.

### iterator의 operator
* https://docs.microsoft.com/ko-kr/cpp/standard-library/iterator-operators?view=msvc-160
* https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
* *operator->*
    * https://www.codentalks.com/t/topic/8397
    * https://stackoverflow.com/questions/9007775/how-to-implement-operator-for-iterator-type
* *operator-*
    * http://www.cplusplus.com/reference/iterator/move_iterator/operator_minus-free/
        > cplusplus에 iterator::operator을 검색하면 나온다.  
        > 하지만 이는 rev나 move iterator에 대한 내용이고... ❓ 그냥 iterator에 대한 것은 없는걸까?  
        > 위의 iterator들은 predefined라고 미리 정의되어 있는 애들이라 그런 것 같다. ❓ iterator은 원래 컨테이너마다 오버로딩(재구현)해서 쓰는 존재여서 그런가?
* *전치/후치 증감 연산자*
    * https://m.blog.naver.com/PostView.nhn?blogId=kks227&logNo=60205596079&proxyReferer=https:%2F%2Fwww.google.com%2F ⭐️
    * https://stackoverflow.com/questions/9386266/overloading-the-operator-to-increment-an-iterator
* 전체적으로는 다음을 보고 구현하였다. ⭐️
    * https://www.cplusplus.com/reference/iterator/reverse_iterator/
        > predefined iterator. 멤버함수(연산자)를 참고하려면 이걸 하면 될 듯?
    * https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator

### const_iterator
* https://nedy.tistory.com/30
    > const value_type을 가리키는 iterator.  
    > 즉, iterator은 변경 가능(`it++`), iterator가 가리키는 값은 변경 불가능(`*it += 1`).  

### iterator의 주소
* http://grindawayat.blogspot.com/2015/05/vector-iterator-vectoriteratorelementer_21.html
    > `&(*if)`의 형태로 가능한 듯.

### operator 오버로딩
* https://mufflemumble.tistory.com/27

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
* https://blog.hexabrain.net/177 ⭐️
* https://mandy8303.tistory.com/53
* https://mandy8303.tistory.com/57?category=762830 ⬜ 정리해볼 것

### 템플릿
* https://www.cppkorea.org/CppCoreGuidelines/Templates/

### :: 연산자
* https://zoonvivor.tistory.com/92

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
* size vs capacity vs max_size
    * https://sollu.wordpress.com/2010/03/25/stl-vector-size-vs-capacity-vs-max_size/
    * http://www.java2s.com/Code/Cpp/Vector/vectormaxsizesizecapacity.htm

### list
* https://ssinyoung.tistory.com/46
    > * list는 이중 연결리스트.
* https://blockdmask.tistory.com/76
* https://kswims.tistory.com/136
* https://ehclub.co.kr/1236

### 전방 선언
* error: use of undeclared identifier 'ft'
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

### 예외
* *strong guarantee*
    * https://docs.microsoft.com/ko-kr/cpp/cpp/how-to-design-for-exception-safety?view=msvc-160
    * https://m.blog.naver.com/PostView.nhn?blogId=mug896&logNo=140168091611&proxyReferer=https:%2F%2Fwww.google.com%2F
        > * strong guarantee: 예외가 발생했을 때, 오브젝트가 함수 수행 전 상태로 보존되는 것을 보장.
    * https://banaba.tistory.com/2 ⭐️
* *std::out_of_range*
    * https://www.cplusplus.com/reference/stdexcept/out_of_range/

### difference_type
* http://www.soen.kr/lecture/ccpp/cpp4/39-2-6.htm ⭐️



## vector 함수 정리

### 코플린 폼
* [x] 생성자
* [x] 소멸자
* [x] operator=

### Iterators
* [x] begin
* [x] end
* [x] rbegin
* [x] rend

### Capacity
* [x] size
* [ ] max_size
* [x] resize
    > * `void resize (size_type n, value_type val = value_type());`
    > * **n개 요소를 갖도록 컨테이너를 리사이즈한다.**  
    >   n이 size보다 작다면, 앞의 n개 요소만 남고 이후는 제거(소멸)된다.  
    >   n이 size보다 크다면, 컨테이너가 확장되어 val이 추가된다.  
    >   n이 capacity보다 크다면, 할당된 저장공간이 자동으로 재할당된다.
* [x] capacity
* [x] empty
* [x] reserve
    > * `void reserve (size_type n);`
    > * **capacity의 변경을 요청한다.**  
    >   벡터가 최소 n개 요소를 포함하도록 capacity의 변경을 요청한다.  
    >   n이 capacity보다 크다면, 저장공간을 재할당하여 n(혹은 그 이상)으로 늘린다.  
    >   그 외의 경우에는 재할당이 이루어지지 않으며, capacity에 변화는 없다.  
    >   이 함수는 size나 요소에 영향을 주지 않는다.

### Element access
* [x] operator[]
    > ❓ const는 어떻게?
* [x] at
    > ❓ std::out_of_range 쓰면 되나?  
    > ❓ 예외에 인자 안주면 어떻게 되나? 인자를 줘야 하나?
* [x] front
* [x] back

### Modifiers
* [x] assign
    > * `template <class InputIterator> void assign (InputIterator first, InputIterator last);`  
    >   `void assign (size_type n, const value_type& val);`
    > * **vector에 내용을 할당한다.**  
    >   현재 내용을 대신하여 새로운 내용을 할당하고, size를 수정한다.  
    >   재할당이 발생하면, 필요한만큼 내부 allocator에 의해 할당된다.  
    >   호출 전에 컨테이너에 있던 모든 요소는 소멸되고 새로운 요소로 대체된다. ❓ 원문 다시 봐야!  
    >   새 벡터 size가 capacity를 초과하는 경우에만 재할당.
* [x] push_back
    > * void push_back (const value_type& val);
    > * **끝에 요소를 추가한다.**  
    >   마지막 요소 뒤에 새 요소를 추가한다.  
    >   이렇게 하면 size가 1 증가하는데, 이것이 capacity를 초과하면 할당된 저장공간이 자동으로 재할당된다.
* [x] pop_back
    > * `void pop_back();`
    > * **마지막 요소를 삭제한다.**  
    >   마지막 요소를 삭제하고 size가 1 감소한다.  
    >   제거된 요소는 소멸한다.
* [x] insert ⭐️
    > * **요소를 삽입한다.**  
    >   지정된 위치에 새 요소를 삽입해서 벡터를 확장한다. 삽입된 요소 수만큼 size가 늘어난다.  
    >   새 백터 size가 capacity를 초과하면 재할당.  
    >   벡터는 배열을 저장소로 사용하므로, 벡터 끝이 아닌 곳에 insert를 하면 전체적인 재배치가 이루어져 비효율적. 이는 다른 시퀀스 컨테이너(ex. list, forward_list)와 비교하면 알 수 있다.  
* [x] erase
    > * `iterator erase (iterator position);`  
    >   `iterator erase (iterator first, iterator last);`  
    > * **요소들을 삭제한다.**  
    >   단일 요소 또는 요소 범위를 삭제한다.  
    >   제거된 요소 수만큼 컨테이너 size를 줄일 수 있다.  
    >   하지만 이또한 다른 시퀀스 컨테이너(ex. list, forward_list)에 비해 비효율적인 작업이다.
* [ ] swap
* [x] clear
    > * `void clear();`
    > * **요소를 모두 제거한다.**  
    >   벡터의 모든 요소(소멸됨)를 제거하고 size를 0으로 만든다.  
    >   재할당이 일어나는 것은 보장되지 않으며, capacity의 변경도 보장되지 않는다.  
    >   재할당을 강제하는 일반적인 방법은, swap을 사용하는 것이다.  
    >   `vector<T>().swap(x);   // clear x reallocating` ❓ 무슨 의미지?


### Non-member function overloads
* [x] relational operators
* [ ] swap