#include "libft.h"

int	ft_isdigit(int c)
{
	if (47 < c && c < 58)
		return (1);
	return (0);
}

// int	main(void)
// {
// 	for (int i = 0; i < 255; i++)
// 		printf("%c  %d\n", i, ft_isdigit(i));
// 	return (0);
// }