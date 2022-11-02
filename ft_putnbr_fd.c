#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*ptr;

	ptr = ft_itoa(n);
	if (ptr != NULL)
		write(fd, ptr, ft_strlen(ptr) + 1);
}

// int	main(void)
// {
// 	ft_putnbr_fd(INT_MIN, 1);
// }
