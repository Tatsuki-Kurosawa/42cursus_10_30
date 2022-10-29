#include <stdlib.h>
#include <stdio.h>

// strtolの返り値はlong
int	main(void)
{
	long	return_value;
	char	word[11] = "11111111";
	int		sho;
	int		amari;

	return_value = strtol(word, NULL, 10);
	printf("%ld\n", return_value);

	sho = -119 / 10;
	amari = 5 % 10;
	printf("sho:%d, amari:%d\n", sho, amari);
}