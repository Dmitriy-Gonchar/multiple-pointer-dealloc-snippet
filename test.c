#include "multi_free.h"

int main()
{
	void *array0 = malloc(1024);
	void *array1 = malloc(2048);
	char *string = strdup("test string");
	int *intArray = (int *)malloc(sizeof(int) * 4096);

	free(array0, array1, string);
	free(intArray);
	return 0;
}
