#include "libft.h"

char	*convert(int sign, int count, int n_copy, int r_mod);
char	*convert_intmin(int sign, int count, int n_copy);

// 桁数をカウント、負は正に、convert関数へ、INT_MINは操作せずにconvert関数へ渡す
char	*ft_itoa(int n)
{
	int		sign;
	int		n_copy;
	int		count;
	int		mod;

	mod = 0;
	count = 0;
	sign = 1;
	if (n == 0)
		count++;
	else if (n < 0)
	{
		count++;
		sign = -1;
		if (n == INT_MIN)
			return (convert(sign, count, n, mod));
		n *= -1;
	}
	n_copy = n;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (convert(sign, count, n_copy, mod));
}

// intのデータをchar型に変換、INT_MINはconvert_intmin関数へ
char	*convert(int sign, int count, int n_copy, int r_mod)
{
	char	*return_value;
	int		check;
	int		mod;

	if (n_copy == INT_MIN)
		return (convert_intmin(sign, count, n_copy));
	return_value = (char *)malloc(count + 1);
	if (!return_value)
		return (NULL);
	// *(return_value + count) = '\0';
	if (n_copy == 0)
	{
		return_value[0] = 48;
		return_value[1] = '\0';
		return (return_value);
	}
	check = count;
	while (count >= 0)
	{
		if (check == count)
			*(return_value + count) = '\0';
		else if (r_mod != 0 && count == check - 1)
			*(return_value + count) = r_mod + 48;
		else if (n_copy != 0)
		{
			mod = n_copy % 10;
			n_copy /= 10;
			*(return_value + count) = mod + 48;
		}
		count--;
		if (n_copy == 0 && sign == -1)
		{
			*(return_value + count) = '-';
			count--;
		}
	}
	return (return_value);
}

// INT_MINを処理、char型への変換はconvert関数へ
char	*convert_intmin(int sign, int count, int n)
{
	int		mod;
	int		n_copy;

	mod = n % 10;
	n /= 10;
	count++;
	mod *= -1;
	n *= -1;
	n_copy = n;
	// printf("convert_intmin()n_copy : %d\n", n_copy);
	while (n > 0)
	{
		n /= 10;
		// printf("convert_intmin() n: %d, count: %d\n", n, count);
		count++;
	}
	return (convert(sign, count, n_copy, mod));
}

// int	main(void)
// {
// 	int		value;
// 	char	*ptr;
// 	int		strres;

// 	value = INT_MIN;
// 	// value = -0;
// 	// ptr = ft_itoa();
// 	ptr = ft_itoa(value);
// 	printf("入力値：%d\n", value);
// 	printf("返り値：%s\n", ptr);
// 	// printf("%d\n", INT_MAX);
// 	// strres = strcmp(ptr, (char)INT_MAX);
// 	// printf("%d\n", strres);
// }