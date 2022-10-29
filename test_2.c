#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char msg[] = "Hello World\n";

	write(1, '6', 1);
	return 0;
}