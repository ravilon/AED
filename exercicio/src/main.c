#include <stdio.h>
#include <stdlib.h>

int main()
{
	void *PVteste;

	PVteste = (char*)malloc(5*(sizeof(char)));
	PVteste = "ravi";
	printf("%s", (char*) PVteste);
	return (0);
}