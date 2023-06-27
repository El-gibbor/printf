#include "../main.h"

int main(void)
{
	int len = 0, len10 = 0, len20 = 0, len2 = 0, len3 = 0, len4 = 0;

	len10 = _printf("it's NULL here %s\n", NULL);
	len20 = printf("it's NULL here %s\n", NULL);

	_printf("%d\n", len10);
	printf("%d\n", len20);

	len = _printf("A %c%c%s sentence\n", 's', 'i', "mple");
	len2 = printf("A %c%c%s sentence\n", 's', 'i', "mple");

	printf("Len:[%d]\n", len);
	printf("Len1:[%d]\n\n", len2);

	len3 = _printf("A simple sentence%");
	len4 = printf("\nA simple sentence%");
	printf("\n");

	_printf("%d\n", len3);
	printf("%d\n", len4);
	return (0);
}
