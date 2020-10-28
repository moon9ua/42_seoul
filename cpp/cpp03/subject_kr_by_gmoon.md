# C++ - Module 03

Inheritance

## 일반 지침

cpp00과 동일.

## Exercise 00: Aaaaand... OPEN!

| Exercise : 00 |
| --- |
| 제출 디렉토리: ex00/ |
| 제출할 파일: FragTrap.cpp FragTrap.hpp main.cpp |
| 금지 함수: 없음 |

여기에서 당신은 FR4G-TP 돌격 로봇/신발상자를 모델링하는 클래스를 만들어야 합니다.

클래스는 FragTrap으로 불리며, 다음의 속성들을 지니며, 이 특정 값들로 초기화됩니다:

* Hit Points (100)
* Max hit points (100)
* Energy points (100)
* Max energy points (100)
* Level (1)
* Name (Parameter of constructor)
* Melee attack damage (30)
* Ranged attack damage (20)
* Armor damage reduction (5)

당신은 또한 이것을 더 생명체처럼 만들기 위해 몇 가지 함수들을 추가할 것입니다:

* rangedAttack(std::string const & target)
* meleeAttack(std::string const & target)
* takeDamage(unsigned int amount)
* beRapaired(unsigned int amount)

모든 함수들에서 당신은 무슨 일이 일어났는 지를 묘사하도록 무엇인가를 표시해야 합니다. 예를 들어, rangedAttack 함수는 아마 이런 것을 표시할 수 있겠죠:

`FR4G-TP <name> attacks <target> at range, causing <damage> points of damage!`

생성자와 소멸자 또한 사람들이 이것이 적절히 호출되었는지를 볼 수 있도록 무엇인가를 표시해야 합니다. 이러한 문구가 재밌는 참조일 경우, 보너스 포인트를 받을 것입니다. (만약 FR4G-TP를 모르신다면, 최소한 구글링 해보시고, 적절한 인용을 사용하세요.)

몇 가지 제약이 있습니다:

* hit points의 숫자는 max hit points 숫자를 초과할 수 없습니다. energy points 또한 마찬가지입니다. 예를 들어, 만약 너무 많은 HP를 회복하였다면 max HP number로 설정해야 할 것입니다. 마찬가지로, 이것들은 0 이하로 떨어질 수 없습니다.
* 데미지를 입을 경우, 당신은 armor damage reduction을 고려해야 합니다. (When you take damage, you have to take your armor damage reduction into account.)

타겟에게 세미-랜덤한 공격의 효과를 주는 vaulthunter_dot_exe(std::string const & target) 함수를 추가함으로서 마치세요. 이 함수가 호출될 때마다 최소 다섯 개의 가능한 공격들 중에서 랜덤하게 선택된 재미있는 공격을 실행합니다. 어떤 방법도 상관없지만, 더 방법이 우아할수록 좋습니다. 이 기능을 실행하려면 25 energy points가 필요합니다. 충분한 energy points가 없다면 에너지가 부족하다는 것을 표시하는 것 외에는 아무 것도 하지 않습니다.

당신은 코드가 잘 작동한다는 것을 증명할 충분한 테스트들과 함께 메인 문을 제출해야 합니다.

## Exercise 01: Serena, my love!

| Exercise : 01 |
| --- |
| 제출 디렉토리: ex01/ |
| 제출할 파일: 앞의 exercise 파일 + ScavTrap.cpp ScavTrap.hpp |
| 금지 함수: 없음 |

충분한 클랩트랩이 더 없기 때문에, 이제 우리는 약간 다른 목적을 제공하는 또 다른 클랩트랩을 만들 것입니다: 악의 은신처가 될 문을 관리하고, 들어오려는 사람들에게 도전할 것입니다. (Manning the door of your soon-to-be evil lair, and challenging people who want to come in.)

클래스의 이름은 ScavTrap이고 다음의 속성을 가집니다:

* Hit points (100)
* Max hit points (100)
* Energy points (50)
* Max energy points (50)
* Level
* Name (생성자의 매개변수)
* Melee attack damage (20)
* Ranged attack damage (15)
* Armor damage reduction (3)

FragTrap과 같은 함수를 추가하세요. 하지만 생성자, 소멸자, 공격들은 다른 결과를 출력해야 합니다. 결국, 클랩트랩은 어느 정도의 개인적 특성을 가져야만 합니다. ( After all, a Claptrap has to have some measure of individuality.)

하나의 예외는 ScavTrap은 vaulthunter_dot_exe 함수를 가지지 않는다는 것입니다. 대신에 challengeNewcomer 함수를 가지고, 이 함수는 여러 개의 (재밌는) 도전 중 하나를 랜덤하게 선택하고 표준 출력에 내보냅니다.

main 함수를 두 클래스를 테스트하기 위해 확장하세요.

## Exercise 02: Repetitive work

| Exercise : 02 |
| --- |
| 제출 디렉토리: ex02/ |
| 제출할 파일: 앞의 exercise 파일 + ClapTrap.cpp ClapTrap.hpp |
| 금지 함수: 없음 |

클랩트랩들을 만드는 것이 아마 신경 쓰이기 시작했을 것입니다. 그렇죠?

Well, before you can work less, you have to work more.

이제 당신은 ClapTrap 클래스를 만들 것입니다. FragTrap과 ScavTrap은 이것으로부터 상속된 것이죠.

모든 공통 함수를 ClapTrap 클래스에 배치해야하지만, 특정 함수들은 그대로 유지해야 합니다. 즉, FragTrap과 ScavTrap 클래스에는 두 클래스 모두에 공유되지 않는 것들만 있어야하고, 두 클래스 모두에 공유되는 것들은 부모 클래스에 있어야합니다.

ClapTrap 클래스에는 자체 생성자와 소멸자 메세지를 가집니다. 또한 적절한 생성자/소멸자 연결이 나타나야 합니다. (FragTrap을 만들 때, ClapTrap을 만드는 것부터 시작해야 합니다. 소멸자는 반대의 순서입니다.) 테스트들은 이것을 보여주어야 합니다.

## Exercise 03: Now it's easier!

| Exercise : 03 |
| --- |
| 제출 디렉토리: ex03/ |
| 제출할 파일: 앞의 exercise 파일 + NinjaTrap.cpp NinjaTrap.hpp |
| 금지 함수: 없음 |

지금까지 만든 모든 것을 이용해서, 다음의 속성을 가지는 NunjaTrap 클래스를 만드세요:

* Hit Points (60)
* Max hit points (60)
* Energy points (120)
* Max energy points (120)
* Level (1)
* Name (생성자의 매개변수)
* Melee attack damage (60)
* Ranged attack damage (5)
* Armor damage reduction (0)

이것의 특별한 공격은 ninjaShoebox 함수가 될 것입니다. 동일한 시그니처를 가진 여러 함수로, 각각 다른 Claptrap(NinjaTrap도 포함)을 매개변수로 참조하여 다른 행동을 합니다. 안타깝게도 아직은 어떠한 Claptrap도 사용할 방법이 없지만, 특정 방법으로 반응합니다. 오, 아마... 내일 보게 되겠네요. 어떻게 하고 있는진 모르겠지만, 어쨌거나 재미있게 만들어보세요.

## Exercise 04: Ultimate assault showbox

| Exercise : 04 |
| --- |
| 제출 디렉토리: ex04/ |
| 제출할 파일: 앞의 exercise 파일 + SuperTrap.cpp SuperTrap.hpp |
| 금지 함수: 없음 |

자, 이제 절반은 Fragtrap이고 절반은 Ninjatrap인 Claptrap을 만들어서 두 세계의 장점을 결합해봅시다.

이것의 이름은 SuperTrap이고, 이것은 FragTrap과 NinjaTrap을 상속받을 것입니다.

이것의 속성은 다음과 같습니다:

* Hit points (Fragtrap)
* Max hit points (Fragtrap)
* Energy points (Ninjatrap)
* Max energy points (Ninjatrap)
* Level (1)
* Name (Parameter of constructor)
* Melee attack damage (Ninjatrap)
* Ranged attack damage (Fragtrap)
* Armor damage reduction (Fragtrap)
* rangedAttack (Fragtrap)
* meleeAttack (Ninjatrap)

이것은 두 스페셜 공격을 다 가질 것입니다.

메인문은 새로운 클래스를 테스트하게끔 확장되어야겠죠.

당연히, Supertrap의 Claptrap 부분은 한 번만 만들어야겠죠, 단 한번만... 네. 여기에 함정이 있습니다. 찾아보세요.