#include "../main.h"

int main(void)
{
	int len = 0, len2 = 0;

	len = _printf("hello %% %s", NULL);
	len2 = printf("hello %% %s", NULL);
	_printf("\n%d\n", len);
	_printf("\n%d\n", len2);
	return (0);
}
