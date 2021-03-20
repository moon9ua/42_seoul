# ft_containers
C++ containers, easy mode  
요약: C++에서 사용가능한 여러 컨테이너들은 모두 다른 용도를 가집니다.  
이것들을 모두 이해할 수 있도록, 다시 구현해봅시다!

## Chapter 1. 일반 지침
C++ module과 동일.

## Chapter 2. 목표
이 프로젝트에서는 C++ 표준 템플릿 라이브러리의 다양한 컨테이너 타입들을 구현합니다.  
각 컨테이너에 대해, 적절한 이름의 클래스 파일들을 제출하세요.  
네임스페이스는 항상 ft이고 컨테이너는 ft::\<container\>을 사용하여 테스트됩니다.  
당신은 참조 컨테이너의 구조를 존중해야 합니다. 만약 코플린 폼이 누락되어 있다면, 구현하지 마십시오.  
다시 말해, 우리는 C++98로 코딩하고 있으므로, 컨테이너의 새로운 기능은 구현하면 안되지만, 모든 오래된 (사용되지 않더라도) 기능은 구현해야 합니다.  

## Chapter 3. 필수 파트
* 다음 컨테이너를 구현하고 필요한 파일 \<container\>.hpp을 제출하세요.
* 또한 평가를 위한 모든 것을 테스트하는 main.cpp을 제출해야 합니다.
* The member function get_allocator is not expected here, the remaining member functions are. Non-member overloads are expected aswell.
* 만약 컨테이너가 반복자 시스템을 가진다면, 재구현해야 합니다.
* 구현할 항목의 참조로 https://www.cplusplus.com/ 을 사용할 수 있습니다.
* 표준 컨테이너에서 제공하는 것보다 더 많은 public 함수를 구현하면 안됩니다. 그 외 모든 것은 private이거나 protected여야 합니다. 각 public 함수 또는 변수는 정당화되어야 합니다.
* non-member 오버로드의 경우, freind 키워드가 허용됩니다. 각 freind의 사용은 정당화되어야 하고, 평가 시 체크됩니다.

다음의 컨테이너들과 관련 함수들을 제출하세요.
* List
* Vector
* Map
* Stack
* Queue
당연히, STL은 금지입니다. 하지만 STD 라이브러리를 사용하는 것은 허용됩니다.

## Chapter 4. 보너스 파트
필수 파트를 완벽히 끝냈다면, 보너스를 시도할 수 있습니다.  
보너스로서, 다음의 컨테이너들과 관련 함수들을 제출하세요.
* Deque
* Set
* Multiset
* Multimap