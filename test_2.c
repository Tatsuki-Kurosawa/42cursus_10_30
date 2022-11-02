#include <stdio.h>

int	main(void)
{
	typedef struct person
	{
		char	name;
		int		age;
	}	t_person;

	printf("%lu", sizeof(t_person));
}