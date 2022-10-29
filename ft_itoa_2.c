#include "libft.h"

char	*under(int n);

char	*ft_itoa(int n)
{
	char	*return_value;
	int		sign;
	int		r_n;
	int		count;
	int		check;
	int		amari;

	count = 0;
	sign = 1;
	if (n == INT_MIN)
		return (under(n));
	if (n == 0)
		count++;
	else if (n < 0)
	{
		sign = -1;
		n *= -1;
		count++;
	}
	r_n = n;
	// printf("%d\n", n);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return_value = (char *)malloc(count + 1);
	if (!return_value)
		return (NULL);
	check = count;
	printf("count: %d, check: %d, r_n: %d\n", count, check, r_n);
	while (count >= 0)
	{
		if (check == count)
			*(return_value + count) = '\0';
		else
		{
			amari = r_n % 10;
			r_n /= 10;
			*(return_value + count) = amari + 48;
		}
		count--;
		if (r_n == 0 && sign == -1)
			*(return_value + count) = '-';
	}
	return (return_value);
}

char	*under(int n)
{
	char	*return_value;
	int		sho;
	int		amari;
	int		count;
	int		r_n;
	int		check;

	r_n = n;
	count = 0;
	amari = n % 10;
	sho = n / 10;
	count++;
	amari *= -1;
	sho *= -1;
	while (sho > 0)
	{
		sho /= 10;
		count++;
	}
	return_value = (char *)malloc(count + 1);
	check = count;
	if (!return_value)
		return (NULL);
	while (count >= 0)
	{
		if (check == count)
			*(return_value + count) = '\0';
		else
		{
			amari = r_n % 10;
			r_n /= 10;
			*(return_value + count) = amari + 48;
		}
		count--;
		if (r_n == 0)
			*(return_value + count) = '-';
	}
	return (return_value);
}

int	main(void)
{
	int		value;
	char	*ptr;
	int		strres;

	// value = -0;
	value = INT_MIN;
	// ptr = ft_itoa();
	ptr = ft_itoa(value);
	printf("入力値：%d\n", value);
	printf("返り値：%s\n", ptr);
	// printf("%d\n", INT_MAX);
	// strres = strcmp(ptr, (char)INT_MAX);
	// printf("%d\n", strres);
}
