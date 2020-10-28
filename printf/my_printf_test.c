#include "ft_printf.h"
#include <stdio.h>

/*
// va함수 test
int sum(int count, ...)
{
	int res = 0;
	va_list ap;
	int i;

	va_start(ap, count);
	for (i = 0; i < count; i++)
	{
		res += va_arg(ap, int);
		printf("res: %d\n", res);
	}
	va_end(ap);
	return (res);
}
int main()
{
	printf("[%d]\n", sum(10, 0,1,2,3,4,5,6,7,8,9));
	return 0;
}
*/

/*
// make_flags 테스트
int main()
{
	char a[10] = "hello";
	ft_printf("%d\n%u\n%p\n%c\n", 2147483648, -1, a, "Moon"); // 이런 값들 고쳐야.

	printf("%p\n", a);
	// char **test = make_flags("moon%-d\n", 1);
	// printf("%s\n", test[0]);
	// free(test[0]);
	// free(test);	


	// char *a = "hi %s hello%s%s";
	// ft_printf(a, "MOON", "GU", "WHA");

	// ft_printf("hello %d %d %d ", 1, 2, 3);
	// ft_printf("hello%d%d%d", 1, 2, 3);
	// ft_printf("hello %c%c%c%c", 'm', 'o', 'o', 'n');

	// ft_printf("===============\n");
}
*/

/*
// make_flags 테스트
int main()
{
	char **test = make_flags("hi%--dhello%-0dworld%-.s", 3);
	int i;
	i = 0;
	while (i < 3)
	{
		printf("%s\n", test[i]);
		i++;
	}
	while (i > 0)
	{
		free(test[i - 1]);
		i--;
	}
	free(test);
}
*/

/*
// convert_flag 테스트
int main()
{
	// char *a = convert_flag("123", "4.6");
	// printf("[%s]\n", a);
	// printf("[%4.6d]\n", 123);

	// char *b = convert_flag("123", "6.4");
	// printf("[%s]\n", b);
	// printf("[%6.4d]\n", 123);

	// char *c = convert_flag("123", "-6.4");
	// printf("[%s]\n", c);
	// printf("[%-6.4d]\n", 123);

	// char *d = convert_flag("123", "06.4");
	// printf("[%s]\n", d);
	// printf("[%06.4d]\n", 123);

	// char *a = convert_flag("123", "-4");
	
	printf("[%-4d]\n", 123); // [123 ]
	printf("[%04d]\n", 123); // [0123]
	printf("[%4d]\n", 123); // [ 123]
	ft_printf("[%4d]\n", 123);

	// printf("[%-10.6d]\n", 123); // [000123   ]
	// printf("[%10.6d]\n", 123); // [   000123]
}
*/

/*
int main()
{
	// // d 테스트 - 누수 체크함
	ft_printf("1. [%d]\n", 13); // [13]
	printf("1. [%d]\n", 13); // [13]
	ft_printf("2. [%5d]\n", 13); // [   13]
	printf("2. [%5d]\n", 13); // [   13]
	ft_printf("3. [%05d]\n", 13); // [00013]
	printf("3. [%05d]\n", 13); // [00013]
	ft_printf("4. [%-5d]\n", 13); // [13   ]
	printf("4. [%-5d]\n", 13); // [13   ]
	ft_printf("5. [%5.3d]\n", 13); // [  013]
	printf("5. [%5.3d]\n", 13); // [  013]
	ft_printf("6. [%05.3d]\n", 13); // [  013]
	printf("6. [%05.3d]\n", 13); // [  013]
	ft_printf("7. [%-5.3d]\n", 13); // [013  ]
	printf("7. [%-5.3d]\n", 13); // [013  ]
	ft_printf("8. [%-5.3d]\n", 2147483648); // 오버플로우되고, 중단은 안되니 ok
	// printf("8. [%-5.3d]\n", 2147483648); // 에러
	
	// c 테스트 - 누수 체크함
	// 에러가 떠도, 중단만 안되면 되는듯? 결과 안보는거같기도..
	// ft_printf("1. [%c]\n", 'a');
	// printf("1. [%c]\n", 'a');
	// ft_printf("2. [%5c]\n", 'a');
	// printf("2. [%5c]\n", 'a');
	// ft_printf("3. [%05c]\n", 'a');
	// // printf("3. [%05c]\n", 'a'); // 에러: c에서는 0 안쓰임.
	// ft_printf("4. [%-5c]\n", 'a');
	// printf("4. [%-5c]\n", 'a');
	// ft_printf("5. [%5.3c]\n", 'a');
	// // printf("5. [%5.3c]\n", 'a'); // 에러: c에서는 정밀도 안쓰임.
	// ft_printf("6. [%05.3c]\n", 'a');
	// // printf("6. [%05.3c]\n", 'a'); // 에러: c에서는 정밀도 안쓰임.

	// s 테스트 - 대충 완료
	ft_printf("1. [%s]\n", "hello");
	printf("1. [%s]\n", "hello");
	ft_printf("2. [%10s]\n", "hello");
	printf("2. [%10s]\n", "hello");
	ft_printf("3. [%010s]\n", "hello");
	// printf("3. [%010s]\n", "hello"); // 에러: s에서는 0 안쓰임.
	ft_printf("4. [%-10s]\n", "hello");
	printf("4. [%-10s]\n", "hello");
	ft_printf("5. [%10.7s]\n", "hello"); // 수정 필요 -> 완료
	printf("5. [%10.7s]\n", "hello"); // s에서는 정밀도 에러 안뜨는 대신, 0 출력 안함.
	ft_printf("6. [%7.10s]\n", "hello"); // 수정 필요 -> 완료
	printf("6. [%7.10s]\n", "hello"); // s에서는 정밀도 에러 안뜨는 대신, 아예 고려 안하는듯.
	ft_printf("7. [%.10s]\n", "hello"); // 수정 필요 -> 완료
	printf("7. [%.10s]\n", "hello"); // s에서는 정밀도 에러 안뜨는 대신, 아예 고려 안하는듯.

	// // u 테스트 - 대충 완료
	// ft_printf("1. [%u]\n", 13);
	// printf("1. [%u]\n", 13);
	// ft_printf("2. [%5u]\n", 13);
	// printf("2. [%5u]\n", 13);
	// ft_printf("3. [%05u]\n", 13);
	// printf("3. [%05u]\n", 13);
	// ft_printf("4. [%-5u]\n", 13);
	// printf("4. [%-5u]\n", 13);
	// ft_printf("5. [%5.3u]\n", 13);
	// printf("5. [%5.3u]\n", 13);
	// ft_printf("6. [%05.3u]\n", 13);
	// printf("6. [%05.3u]\n", 13);
	// ft_printf("7. [%-5.3u]\n", 13);
	// printf("7. [%-5.3u]\n", 13);
	// ft_printf("8. [%-5.3u]\n", -1);
	// printf("8. [%-5.3u]\n", -1); // 오버플로우되고 에러 안뜸. 결과 일치.
	// ft_printf("9. [%-5.3u]\n", 4294967295);
	// // printf("9. [%-5.3u]\n", 4294967295); // 에러가 뜨네..? u의 용도는 뭐냐..
	
	// // x 테스트 - 대충 완료
	// printf("%d\n", ft_printf("1. [%x]\n", 1358));
	// printf("%d\n", printf("1. [%x]\n", 1358));
	// printf("%d\n", ft_printf("2. [%5x]\n", 1358));
	// printf("%d\n", printf("2. [%5x]\n", 1358));
	// printf("%d\n", ft_printf("3. [%05x]\n", 1358));
	// printf("%d\n", printf("3. [%05x]\n", 1358));
	// printf("%d\n", ft_printf("4. [%-5x]\n", 1358));
	// printf("%d\n", printf("4. [%-5x]\n", 1358));
	// printf("%d\n", ft_printf("5. [%5.3x]\n", 1358));
	// printf("%d\n", printf("5. [%5.3x]\n", 1358));
	// printf("%d\n", ft_printf("6. [%05.3x]\n", 1358));
	// printf("%d\n", printf("6. [%05.3x]\n", 1358));
	// printf("%d\n", ft_printf("7. [%-5.3x]\n", 1358));
	// printf("%d\n", printf("7. [%-5.3x]\n", 1358));
	// printf("%d\n", ft_printf("8. [%-5.3x]\n", -1));
	// printf("%d\n", printf("8. [%-5.3x]\n", -1)); // 오버플로우되고 에러 안뜸. 결과 일치.

	// p 테스트 - 대충 완료
	// char *a = "hello";
	// ft_printf("1. [%p]\n", a);
	// printf("1. [%p]\n", a);
	// ft_printf("2. [%15p]\n", a);
	// printf("2. [%15p]\n", a);
	// ft_printf("3. [%15.10p]\n", a);
	// // printf("3. [%15.10p]\n", a); // p에선 정밀도 에러
	// ft_printf("4. [%015p]\n", a);
	// // printf("4. [%015p]\n", a); // p에선 0 에러
	// ft_printf("5. [%-15p]\n", a);
	// printf("5. [%-15p]\n", a);

	// * 테스트 - 있는지 모르고 구현 안했다가 나중에 엄청 지저분하게 추가함. ㅠㅠ
	// printf("r:[%0*d]\n", 10, 123);
	// ft_printf("m:[%0*d]\n", 10, 123);
	// printf("r:[%10.*d]\n", 5, 123);
	// ft_printf("m:[%10.*d]\n", 5, 123);
	// ft_printf("%%\n");
	// printf("%5.06d\n", 123);
}
*/

// count_spec 테스트
// int main()
// {
// 	printf("%d\n", count_spec("assd%% %-0.*d %d d%-.-d"));
// }

// 연결리스트 테스트
// int main()
// {
// 	printf("%d\n", ft_lstsize(count_spec("assd%0.8d% %-0.*d %d d%-.-d")));

// 	printf("%s\n", count_spec("assd%0.8d% %-0.*d %d d%-.-d")[1].content);
// }

// 연결리스트 테스트
// int main()
// {
// 	t_list *ret;
// 	ret = count_spec("assd%0.8d% %-0.*d %d d%-.-d");
// 	printf("[%d]\n", ft_lstsize(ret));
	
	
// 	printf("%s\n", ret->content);
// 	ret = ret->next; // 아 이렇게 쓰는거구나!!!
// 	printf("%s\n", ret->content);
// }

// make_specs 테스트
// int main()
// {
// 	t_list *ret;
// 	ret = count_spec("assd%0.8d% %-0.*d %d d%-.-d");
// 	printf("[%d]\n", ft_lstsize(ret));

// 	printf("%s\n", make_specs("assd%0.8d% %-0.*d %d d%-.-d", ret, 3));
// }

// make_flags 테스트
// int main()
// {
// 	t_list *ret;
// 	ret = count_spec("assd%0.8d% %-0.*d %d d%-.-d");
// 	printf("[%d]\n", ft_lstsize(ret));

// 	char **test;
// 	test = make_flags("assd%0.8d% %-0.*d %d d%-.-d", ret, ft_lstsize(ret));
// 	int i;
// 	i = 0;
// 	while (i < 5)
// 	{
// 		printf("%s\n", test[i]);
// 		i++;
// 	}
// }

/*
int main()
{
	// 문자열 테스트
	// ft_printf("[%.s]\n", "hello");
	// printf("[%.s]\n", "hello");
	// ft_printf("my:[%2.0s]\n", "hello"); // precision과 width 입력하는 부분을 수정해야 할듯.
	// printf("real:[%2.0s]\n", "hello"); // 바로 spec 나오면 0으로 처리하는 식으로?

	// char *a = "010";
	// printf("precision test: %d\n", make_precision(a));
	// printf("width test: %d\n", make_width(a));

	// ft_printf("[%3.1s]\n", NULL);
	// printf("[%3.1s]\n", NULL);

	// ft_printf("[%-3.1s]\n", NULL);
	// printf("[%-3.1s]\n", NULL);

	// ft_printf("[%00s]", "hello");
	// printf("[%00s]", "hello"); // 오류뜨는데? 뭐 컴파일러가 다른가..? 이런거 테스트를 하나?
	// ft_printf("[%00d]\n", 123);
	// printf("[%00d]\n", 123);

	// ft_printf("%8.3d\n", 8375); // s는 짤려서 나와야하는데, 숫자는 보존되어야 하는듯.
	// printf("%8.3d", 8375);

	// ft_printf("[%08.5i]\n", -34);
	// printf("[%08.5i]\n", -34);

	// ft_printf("[%06i]\n", -3);
	// printf("[%06i]\n", -3);
	// ft_printf("[%.6i]\n", -3);
	// printf("[%.6i]\n", -3); // 와 이 두개가 달라... 진짜 문제 지옥이다

	int a01 = 123;
	int a02 = 23;
	int a03 = 1;
	int a04 = 13543;
	int a05 = 11254;
	int a06 = 2345;
	int a07 = 765;
	int a08 = 786;
	int a09 = 78;
	int a10 = 134;
	int a11 = 534;
	int a12 = 1232;

	// char *str = "hi \0 asdfasdf";
	// printf("")
	// ft_printf("%p\n", NULL);
	// printf("%p\n", NULL);
	// ft_printf("%d%0d%d%d%d%d\n",a01,a02,a03,a04,a05,a06);
	// ft_printf("%d%d%d", a01,a02,a03);
	// printf("%d\n", ft_printf("%3.6s", "\0aa"));
	// printf("%d\n",printf("%3.6s", "\0aa"));

	// ft_printf("hello, %s.", NULL);
	// printf("hello, %s.", NULL);

	// printf("%d\n", ft_printf("%-5c", '\0'));
	// printf("%d\n", printf("%-5c", '\0'));
	
	// ft_printf("%p%p%p%p%p%p%p%p%p%p%p%p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	// printf("%p%p%p%p%p%p%p%p%p%p%p%p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

	// 113
	// printf("%d", ft_printf("%3.6s", "\0aaaa"));
	// printf("%d", printf("%3.6s", "\0aaaa"));

	// 722
	// ft_printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");
	// printf("%%-*.3s LYDI == |%-*.3s|\n", 5, "LYDI");

	// 32 코드 구조 수정해서 처음부터 오류잡는다.. ㅠㅠ
	// ft_printf("[%.s]", "hello");
	// printf("(%.s)", "hello");

	// 30
	// ft_printf("%.7s", "hello");
	// printf("%.7s\n", "hello");

	// 31
	// ft_printf("%.3s", "hello");
	// printf("%.3s\n", "hello");

	// 33
	// ft_printf("%.0s", "hello");
	// printf("%.0s\n", "hello");

	// 39
	// ft_printf("[%7.5s]\n", "bombastic");
	// printf("[%7.5s]\n", "bombastic");

	// 79
	// ft_printf("%.03s", NULL);
	// printf("%.03s", NULL);
	
	// 85
	// ft_printf("[%3.s]", "hi low");
	// printf("[%3.s]", "hi low");

	// 208
	// ft_printf("[%.0i]", 0);
	// printf("[%.0i]", 0);

	// 739
	// ft_printf("[%.*s]", -3, "hello");
	// printf("[%.*s]", -3, "hello");

	// 코드 고치고 오류
	//ft_printf("%0*i", -7, -54);
	
	ft_printf("[%*s]", -32, "abc");
	printf("[%*s]", -32, "abc");
}
*/


int main()
{
	// ft_printf("[%7d]", 33);
	// printf("[%7d]", 33);

	// ft_printf("[%.7d]", 0); // 285
	// printf("[%.7d]", 0);

	// ft_printf("[%3d%d%d%d]", -2464, 123, 12, 45);
	// ft_printf("[%-*.*s]", -7, -3, "yolo");
	// printf("[%-*.*s]", -7, -3, "yolo");

	// ft_printf("[%-32s]", "abc");
	// printf("[%-32s]", "abc");

	// ft_printf("%.6i", -3);
	// printf("%.6i", -3);

	ft_printf("[%-10.5i]", -216);
	printf("[%-10.5i]", -216);
}
