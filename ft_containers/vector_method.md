# vector 함수 정리

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
* [x] max_size
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
* [x] at
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
* [x] swap
* [x] clear
    > * `void clear();`
    > * **요소를 모두 제거한다.**  
    >   벡터의 모든 요소(소멸됨)를 제거하고 size를 0으로 만든다.  
    >   재할당이 일어나는 것은 보장되지 않으며, capacity의 변경도 보장되지 않는다.  
    >   재할당을 강제하는 일반적인 방법은, swap을 사용하는 것이다.  
    >   `vector<T>().swap(x);   // clear x reallocating` ❓ 무슨 의미지?


### Non-member function overloads
* [x] relational operators
    > * operator==의 경우, 크기를 먼저 비교한다. 일치하는 경우, operator==를 사용하여 요소가 순차적으로 비교된다.
    > * operator<의 경우, 알고리즘 lexicographical_compare처럼 작동한다. operator<을 사용하여 순차적으로 요소를 비교, 첫번째 발생에서 중지. ❓ 상호 방식으로 비교한다는 것이 무슨 뜻이지?
* [x] swap
