#include <stdio.h>

void extn_func(void);
void stat_func(void);

int main()
{
	extn_func(); /* 외부 함수 호출*/
	stat_func(); /*정적 함수를 호출하나 사용 불가*/
}
