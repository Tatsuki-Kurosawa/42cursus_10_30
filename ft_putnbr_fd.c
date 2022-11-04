#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		sho;
	int		mod;
	char	chara;

	if (n == 0)
	{
		chara = 48;
		write(fd, &chara, 1);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		if (n == INT_MIN)
		{
			mod = n % 10;
			mod *= -1;
			chara = mod + 48;
			write(fd, &chara, 1);
			n /= 10;
		}
		n *= -1;
	}
	if (n > 0)
	{
		sho = n;
		mod = sho % 10;
		chara = mod + 48;
		ft_putnbr_fd(sho / 10, fd);
		write(fd, &chara, 1);
	}
}

int	main(void)
{
	ft_putnbr_fd(-2147483648, 1);
	// printf("\n");
	// printf("%d\n", 46/(-10));
}
