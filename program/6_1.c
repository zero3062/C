#include <stdio.h>
#include <string.h>	/* strcpy 함수가 정의된 헤더 파일 */

main()
{
	/* struct car 데이터형 정의. 이 구조체의 멤버는 name, year, fuel 3개다. */
	struct car {
		char name[10];
		int year;
		double fuel;
	};
	struct car sonata;	/* struct car 데이터형 변수 선언 */

	/* strcpy를 사용해 구조체형 변수 sonata의 멤버에 값을 저장한다. */
	strcpy(sonata.name, "SONATA");
	sonata.year = 2003;
	sonata.fuel = 77.7;

	printf("%s: %dyear %gfuel\n", sonata.name, sonata.year, sonata.fuel);
}
