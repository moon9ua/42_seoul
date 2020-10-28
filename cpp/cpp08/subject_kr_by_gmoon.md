# C++ - Module 08
Templated containers, iterators, algorithms

## 일반 지침
cpp00와 동일.

## 모듈 룰
이번 모듈의 문제들은 표준 컨테이너와 표준 알고리즘을 사용하지 않고도 해결할 수 있다는 것을 압니다. 하지만 그것들을 사용해보는 것이 목표이며, 적절한 곳에서 표준 컨테이너와 표준 알고리즘을 사용하도록 노력하지 않으면 점수를 받지 못할 것입니다.

## Exercise 00: Easy find

| Exercise : 00 |
| --- |
| 제출 디렉토리: ex00/ |
| 제출할 파일: easyfind.hpp main.cpp |
| 금지 함수: 없음 |

한 걸음 내딛기에 쉬운 것부터...

easyfind라는 T와 int를 취하는 T 유형의 템플릿 함수를 만드세요.

T가 int의 컨테이너라고 가정하고 첫 번째 매개 변수에서 두 번째 매개 변수의 첫 번째 항목을 찾습니다.

찾을 수 없는 경우, 예외를 사용하거나 오류 리턴 값을 사용해서 처리하세요.

표준 컨테이너의 작동 방식에서 아이디어를 얻으세요.

철저히 테스트하는 메인문을 제출하세요.

## Exercise 01: Span

| Exercise : 01 |
| --- |
| 제출 디렉토리: ex01/ |
| 제출할 파일: span.cpp span.hpp main.cpp |
| 금지 함수: 없음 |

N개의 int를 저장할 수 있는 클래스를 만드세요. N은 unsigned int이며 생성자에 유일한 매개변수로 전달됩니다.

이 클래스는 이를 채우기 위한 단일 숫자를 저장하는 함수인 `addNumber`을 갖습니다. 개체에 이미 N개가 저장되어 있는 경우, 새 번호를 추가하려고 하면 오류가 발생하고 예외처리됩니다.

이제 `shortestSpan`과 `longestSpan` 두 함수를 만들어서 개체에 포함된 모든 숫자 사이의 최단 및 최장 거리를 찾아 반환합니다. 저장된 숫자가 없거나 하나만 있을 경우, 예외를 던집니다.

아래는 (너무 짧은) 테스트 메인 및 출력의 예시입니다. 물론, 당신의 메인은 이것보다 더 철저해야 합니다. 최소 10000개의 숫자로 테스트해야 합니다. 또한 iterator의 범위를 전달하여 숫자를 추가할 수 있다면 좋을 것입니다. 그러면 addNumber을 수천번 호출하는 번거로움을 피할 수 있습니다.

```c++
int main()
{
    Span sp = Span(5);
    sp.addNumber(5);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}
```
```
$> ./ex01
2
14
$>
```

## Exercise 02: Mutated abomination

| Exercise : 02 |
| --- |
| 제출 디렉토리: ex02/ |
| 제출할 파일: mutantstack.cpp mutantstack.hpp main.cpp |
| 금지 함수: 없음 |

std::stack 컨테이너는 매우 멋지지만, 반복할 수 없는 유일한 STL 컨테이너입니다. 유감이죠.

`MutantStack` 클래스를 만드세요. 이 클래스는 std::stack의 측면에서 구현될 것이며, 모든 멤버 함수를 제공할 것이고, 또한 반복자를 제공합니다.

아래는 코드의 예입니다. 출력은 예를 들어 MutantStack을 std::list로 바꾼 것과 동일해야 합니다. 메인문에서 충분한 테스트를 제공해야 합니다.

```c++
int main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
    std::cout << *it << std::endl;
    ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}
```
