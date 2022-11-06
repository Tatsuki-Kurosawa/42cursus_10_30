#include "libft.h"

char	*convert_1(int sign, int count, int r_n, int amari);
char	*convert_2(int count, int r_n, int r_amari, char *re_value);
char	*min(int sign, int count, int r_n);
int		check_sign();

char	*ft_itoa(int n)
{
	int		sign;
	int		r_n;
	int		count;
	int		amari;

	amari = 0;
	count = 0;
	sign = 1;
	if (n == 0)
		count++;
	else if (n < 0)
	{
		count++;
		sign = -1;
		if (n == INT_MIN)
			return (convert_1(sign, count, n, amari));
		n *= -1;
	}
	r_n = n;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (convert_1(sign, count, r_n, amari));
}

char	*convert_1(int sign, int count, int r_n, int r_amari)
{
	char	*return_value;
	int		check;

	if (r_n == INT_MIN)
		return (min(sign, count, r_n));
	return_value = (char *)malloc(count + 1);
	if (!return_value)
		return (NULL);
	if (r_n == 0)
	{
		return_value[0] = 48;
		return_value[1] = '\0';
		return (return_value);
	}
	if (sign == -1)
		r_amari *= -1;
	return (convert_2(count, r_n, r_amari, return_value));
}

char	*convert_2(int count, int r_n, int r_amari, char *re_value)
{
	int	check;
	int	amari;
	int	sign;

	check = count;
	sign = 1;
	if (r_amari < 0)
	{
		r_amari *= -1;
		sign = -1;
	}
	while (count >= 0)
	{
		if (check == count)
			*(re_value + count) = '\0';
		else if (r_amari != 0 && count == check - 1)
			*(re_value + count) = r_amari + 48;
		else if (r_n != 0)
		{
			amari = r_n % 10;
			r_n /= 10;
			*(re_value + count) = amari + 48;
		}
		count--;
		if (r_n == 0 && sign == -1)
			*(re_value + count) = '-';
	}
	return (re_value);
}

int	check_sign(int r_amari)
{
	if (r_amari < 0)
	{
		r_amari *= -1;
		sign = -1;
	}
}

char	*min(int sign, int count, int n)
{
	int		amari;
	int		r_n;

	amari = n % 10;
	n /= 10;
	count++;
	amari *= -1;
	n *= -1;
	r_n = n;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (convert_1(sign, count, r_n, amari));
}

int	main(void)
{
	int		value;
	char	*ptr;
	int		strres;

	value = INT_MIN;
	// value = -0;
	// ptr = ft_itoa();
	ptr = ft_itoa(value);
	printf("入力値：%d\n", value);
	printf("返り値：%s\n", ptr);
	// printf("%d\n", INT_MAX);
	// strres = strcmp(ptr, (char)INT_MAX);
	// printf("%d\n", strres);
}