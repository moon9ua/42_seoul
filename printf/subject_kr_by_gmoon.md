# printf

이 프로젝트는 꽤 명확하다. printf를 구현하는 것이다.<br>(Summary: This project is pretty straight forward. You will recode printf. Hopefully you will be able to reuse it in future project without the fear of being flagged as a cheater. You will mainly learn how to use variadic arguments.)

## Chapter 1. 서론

printf 함수의 다기능성은 우리에게 프로그래밍의 좋은 연습거리이다. 이 프로젝트는 꽤 어렵다. C의 다양한 기능들을 발견할 수 있을 것이다. ft_printf를 성공할 열쇠는 체계적이고 확장성 있는 코드이다.

## Chapter 2. 일반 지침

* norm 규정을 지켜라. bonus 함수 또한 마찬가지.
* 함수가 정의되지 않은 행동을 하거나 예기치 않게 중단(segmentation fault, bus error, double free, etc)되어서는 안된다.
* 힙의 메모리는 꼭 적절히 free되어야 한다. leak은 허용되지 않는다.
* makefile을 요구할 경우, makefile은 -Wall -Wextra -Werror 플래그로 쓰여야 하며 $(NAME), all, clean, fclean, re 규칙을 포함해야 한다.
* bonus 함수를 추가한 경우, makefile에 bonus 룰을 추가해야 한다. 여기엔 메인 파트에서 금지되었었던 다양한 헤더와 라이브러리가 추가될 것이다. bonus 파일들은 _bonus.{c/h}로 만들어져야 한다. 메인 파트와 bonus 파트는 분리되어 평가될 것이다.
* libft 사용이 허락된 경우, source들과 makefile을 libft 폴더 안에 복사해라.<br>
* 평가는 하지 않겠지만 테스트 프로그램을 만들 것을 권장한다. 
* git 저장소의 작업물만 평가된다.

## Chapter 3. Mandatory part

| Program name     | libftprintf.a                                                |
| ---------------- | ------------------------------------------------------------ |
| Turn in files    | \*.c, \*/\*.c, \*.h, \*/\*.h, Makefile                       |
| Makefile         | all, clean, fclean, re, bonus                                |
| External functs. | malloc, free, write, va_start, va_arg, va_copy, va_end       |
| Libft authorized | yes                                                          |
| Description      | Write a library that contains ft_printf, a funcion that will mimic the real printf |

* ft_printf의 프로토타입은 `int ft_printf(const char *, ...);` 여야 한다.
* libc의 printf 함수를 구현해야한다.
* 실제 printf처럼 버퍼를 관리해서는 안된다.
* 다음 변환을 관리한다: cspdiuxX%
* 다음 플래그의 모든 조합을 관리한다: '-0.*'과 모든 변환의 최소 필드 폭.<br>(’-0.\*’ and minimum field width with all conversions.)
* 실제 printf와 비교될 것이다.
* :loudspeaker: man 3 printf / man 3 stdarg

## Chapter 4. Bonus part

* 필수 파트가 완벽하지 않으면 보너스는 꿈도 꾸지 마라.
* 모든 보너스를 할 필요가 없다.
* 다음 변환 중 하나 이상을 관리해라: nfge
* 다음 플래그 중 하나 이상을 관리해라: l ll h hh
* 다음 플래그를 모두 관리해라: '# +' (이 중 하나는 스페이스다)