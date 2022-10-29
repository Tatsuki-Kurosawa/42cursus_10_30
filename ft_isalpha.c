#include "libft.h"
#include <ctype.h>

int	ft_isalpha(int c)
{
	if ((65 <= c && c <= 90) || (97 <= c && c <= 122))
		return (1);
	return (0);
}

// int	main(void)
// {
// 	for (int i = 0; i < 255; i++)
// 		// printf("%c  %d\n", i, ft_isalpha(i));
// 		printf("%c  %d\n", i, isalpha(i));
// 	return (0);
// }