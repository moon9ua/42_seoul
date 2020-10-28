# C++ - Module 05

Week 1 revisions, Exceptions

## 일반 지침

앞과 동일.

## 특별 규칙

클래스는 요구가 없어도 캐노니컬 폼으로 작성되어야 합니다.

## Exercise 00: Mommy, when I grow up, I want to be a bureaucrat !

| Exercise : 00 |
| --- |
| 제출 디렉토리: ex00/ |
| 제출할 파일: Bureaucrat.hpp Bureaucrat.cpp main.cpp |
| 금지 함수: 없음 |
| 비고: 없음 |

오늘, 우리는 회사, 복도, 양식 및 줄을 서서 기다리는 인공적인 악몽을 만들어 볼 것입니다. 재밌어보이죠? 아니라고요? 안됐군요.

우선, 광활한 기계의 가장 작은 톱니바퀴인 관료부터 시작합니다.

이것은 constant name을 가져야하고, 1(가능한 제일 높은)부터 150(가능한 제일 낮은) 범위의 grade를 가져야합니다. 유효하지 않은 등급으로 관료를 생성하려는 시도는 예외를 던져야 합니다. 이는 `Bureaucrat::GradeTooHighException` 또는 `Bureaucrat::GradeTooLowException`이 될 것입니다.

이 두가지 속성에 대해 getter를 제공합니다(getName과 getGrade). 그리고 grade를 낮추거나 높이는 두 함수를 제공합니다. 이 두 함수는 마찬가지로 성적이 너무 높거나 낮은 경우, 예외를 던집니다. 기억하세요. grade 1이 가장 높고 150이 가장 낮으므로, 3을 올리면 2가 됩니다...

던지는 예외는 다음과 같이 블록에서 캐치할 수 있어야 합니다:
```
try
{
    /* do some stuff with bureaucrats */
}
catch (std::exception & e)
{
    /* handle exception */
}
```

ostream에 `<name>, bureaucrat grade <grade>`를 출력하는 << 연산자 오버로딩을 제공해야 합니다.

당연히, 적절한 메인문도 제출하세요.

## Exercise 01: Form up, maggots !

| Exercise : 01 |
| --- |
| 제출 디렉토리: ex01/ |
| 제출할 파일: Same as before + Form.cpp Form.hpp |
| 금지 함수: 없음 |
| 비고: 없음 |

이제 관료들이 있으니, 그들에게 그들의 시간과 관련된 무언가를 주는 것이 좋습니다. 작성할 서류(form) 더미보다 더 나은 일이 뭡니까?

Form 클래스를 만드세요. name, sign 여부를 나타내는 부울(시작은 False), 서명에 필요한 grade, 실행에 필요한 grade를 가집니다. name과 grade들은 constant하며 (protect가 아니라) private입니다. grade들은 Bureaucrat에서와 동일한 조건을 가지며 범위를 벗어난 경우 Form::GradeTooHighException과 Form::GradeTooLowException 예외가 발생합니다.

이전처럼, 모든 속성에 대한 getter를 만들고, 양식의 상태를 완전히 설명하는 << 연산자에 대한 오버로드를 만드세요.

또한 Bureaucrat를 취하는 `beSigned` 함수를 만들고, 관료의 등급이 충분히 높으면 싸인합니다. 항상 기억하세요. grade 1이 grade 2보다 높습니다. grade가 너무 낮으면, Form::GradeTooLowException를 던지세요.

또한 Bureaucrat에 `signForm` 함수를 만드세요. 싸인이 잘 수행되면 `<bureaucrat> signs <form>`을 출력하고, 그렇지 않으면 `<bureaucrat> cannot sign <form> because <reason>`을 출력하세요.

적절한 메인문을 작성하세요.

## Exercise 02:  No, you need form 28B, not 28C ...

| Exercise : 02 |
| --- |
| 제출 디렉토리: ex02/ |
| 제출할 파일: Same as before + ShrubberyCreationForm.[hpp,cpp] RobotomyRequestForm.[hpp,cpp] PresidentialPardonForm.[hpp,cpp] |
| 금지 함수: 없음 |
| 비고: 없음 |

이제 기본 forms를 만들었으니, 구체적으로 무엇을 할지를 나타내는 forms를 몇 가지 만들어봅시다.

* ShrubberyCreationForm (Required grades : sign 145, exec 137). 행동: 현재 디렉토리에 \<target>_shrubbery 파일을 만들고, ASCII 트리를 작성하세요.
* RobotomyRequestForm (Required grades : sign 72, exec 45). 행동: 드릴 소음을 만들고, \<target>이 50%의 시도에는 로봇화가 성공하였음을 알리세요. 나머지의 시도에는 실패했다고 알리세요.
* PresidentialPardonForm (Required grades : sign 25, exec 5). 행동: \<target>이 Zaphod Beeblebrox에 의해 사면되었음을 알리세요.

이것들은 생성자에 form의 대상(target)을 나타내는 하나의 매개변수만을 가져야합니다. 예를 들어, 집에 관목을 심으려면 "home"을 입력합니다. form의 속성은 기본 클래스에서 private으로 유지되어야 합니다.

기본 form에 `execute(Bureaucrat const & executor) const`를 추가하고, 구체적인 form에서 행동을 구현하세요. form이 서명되어있고, 실행하기에 grade가 충분히 높아야합니다. 그렇지 않으면 적절한 예외가 발생합니다. 모든 구체적인 클래스에서 검사를 수행하든 기본 클래스에서 검사를 수행하고 메서드를 불러오든 그 선택은 자유지만, 어떤 방법이 나머지 방법보다 훨씬 좋은 것은 분명합니다. 어쨌든 기본 form은 반드시 추상 클래스여야 합니다.

bureaucrat에 `executeForm(Form const & form)` 함수를 추가하여 마치세요. form을 실행하고, 만약 성공한다면 `<bureaucrat> executes <form>`을 출력하세요. 실패했다면 오류 메세지를 출력합니다.

적절한 메인문을 작성하세요.

## Exercise 03: At least this beats coffee-making

| Exercise : 03 |
| --- |
| 제출 디렉토리: ex03/ |
| 제출할 파일: Same as before + Intern.hpp Intern.cpp |
| 금지 함수: 없음 |
| 비고: 없음 |

form을 작성하는 것은 귀찮기때문에, 관료들에게 직접 해달라고 하는 것은 너무 잔인할 것입니다. 그냥, 인턴이 작성하도록 합시다.

Intern 클래스를 만들어봅시다. 인턴은 이름도, 등급도, 어떤 특징도 없고, 그 일을 하는 것에만 신경씁니다.

인턴에게 중요한 것은 `makeForm` 함수입니다. 이것은 두개의 문자열을 취하며, 첫번째는 form의 이름을 나타내고 두번째는 form의 타겟을 나타냅니다. 두번째 매개변수로 초기화됐고 첫번째 매개변수가 나타내는, 구체적인 form 클래스의 포인터를 Form의 포인터로 반환합니다. 이것은 "Intern creates \<form>"을 표준출력에 출력합니다. 양식을 알 수 없는 경우, 오류메세지를 출력하세요.

예를 들어, 이것은 "Bender"을 카겟으로 한 RobotomyRequestForm을 생성할 것입니다:
```
{
    Intern someRandomIntern;
    Form* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
}
```

## Exercise 04: That’s the way I like it, nice and boring

| Exercise : 04 |
| --- |
| 제출 디렉토리: ex04/ |
| 제출할 파일: Same as before + OfficeBlock.cpp OfficeBlock.hpp |
| 금지 함수: 없음 |
| 비고: 없음 |

중앙 관료제는 사무실 블록으로 구성되어 있습니다. 이러한 각 블록은 기능을 수행하기 위해 인턴과 두 명의 관료가 필요하며, 명령만 내리면 양식 작성, 서명, 실행할 수 있습니다.

따라서, OfficeBlock 클래스를 만듭시다. 인턴 하나, 서명 관료 하나, 실행 관료 하나에 대한 포인터(혹은 참조)를 전달하여 생성됩니다. 비어있게 생성할 수도 있습니다. 다른 생성은 가능하지 않아야합니다. (즉 복사나 할당이 불가능합니다.)

새로운 인턴을 설정하거나, 관료가 서명하거나, 관료가 실행하는 기능이 있습니다.

유일한 "유용한" 함수는 `doBureaucracy`이며, form의 이름과 target의 이름을 취합니다. 순서대로, 인턴이 요청된 form을 생성하고, 두 번째 관료가 서명하고, 두 번째 관료가 실행하도록 합니다. 인턴과 관료는 무슨 일이 일어나고 있는지 출력합니다. 에러가 발생하면, 이 함수에서 예외가 발생해야 합니다. 우아하게 만들기 위해 이전의 작업물들을 수정할 수 있습니다.

당연히, 이 세 지점이 모두 채워지지 않으면 관료제를 할 수 없습니다.

늘 그렇듯, 메인문을 잘 작성하세요.

```c++
int main()
{
    Intern idiotOne;
    Bureaucrat hermes = Bureaucrat("Hermes Conrad", 37);
    Bureaucrat bob = Bureaucrat("Bobby Bobson", 123);
    OfficeBlock ob;
    ob.setIntern(idiotOne);
    ob.setSigner(bob);
    ob.setExecutor(hermes);
    try
    {
    ob.doBureaucracy("mutant pig termination", "Pigley");
    }
    catch (Some::SpecificException & e)
    {
    /* specific known error happens, say something */
    }
    catch (std::exception & e)
    {
    /* oh god, unknown error, what to do ?! */
    }
}
```

```
zaz@blackjack ex04 $ ./ex04
Intern creates a Mutant Pig Termination Form (s.grade 130, ex.grade 50) targeted on Pigley (Unsigned)
Bureaucrat Bobby Bobson (Grade 123) signs a Mutant Pig Termination Form (s.grade 130, ex.grade 50)
targeted on Pigley (Unsigned)
Bureaucrat Hermes Conrad (Grade 37) executes a Mutant Pig Termination Form (s.grade 130, ex.grade 50)
targeted on Pigley (Signed)
That'll do, Pigley. That'll do ...
zaz@blackjack ex04 $
```

## Exercise 05: Endless red-tape generator

| Exercise : 05 |
| --- |
| 제출 디렉토리: ex05/ |
| 제출할 파일: Same as before + CentralBureaucracy.cpp CentralBureaucracy.hpp |
| 금지 함수: 없음 |
| 비고: 없음 |

이제 당신은 모든 것을 깔끔한 작은 패키지로 포장하기만 하면 됩니다.

CentralBureaucracy 클래스를 만드세요. 이것은 매개변수 없이 생성되고, 생성시 20개의 비어있는 오피스 블록을 가집니다.

이것은 개체를 대상에 공급할 수 있습니다. 인턴은 자동으로 사용자 개입 없이 자동으로 생성됩니다.

개체에 공급되는 관료는 사무실 블록의 자리를 채우는 데 사용됩니다. 사용 가능한 좌석이 없는 경우, 그들을 거부하거나 대기 장소에 저장할 수 있습니다.

그 후 대기열의 사람 이름을 문자열로 취하는 `queueUp` 함수를 사용해서 대상을 대기열에 넣을 수 있습니다.

...