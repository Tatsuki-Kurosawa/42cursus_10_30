/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 05:18:55 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/23 02:49:06 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*divide(int n, int sign, size_t count);
char	*convert(int n, int sign, size_t count, char *re_ptr);
char	*min_case(int n, int sign, size_t count);

char	*ft_itoa(int n)
{
	int		sign;
	size_t	count;

	count = 0;
	sign = 1;
	if (n == 0)
		count++;
	else if (n == INT_MIN)
		sign = -1;
	else if (n < 0 && n != INT_MIN)
	{
		sign = -1;
		n *= -1;
		count++;
	}
	return (divide(n, sign, count));
}
// ↑の関数では、受け取った整数型の値を0, -2147483648, ←以外の負の値, 正の値の4つに分けている.
// 正の値はそのまま通るようになっている. 負の値はマイナスをかけてプラスに変換している. 符号の判別はsignでつける
// 処理が異なるため、必要なバイト数を別々で求めている.

char	*divide(int n, int sign, size_t count)
{
	int		sho;
	char	*re_ptr;

	if (n == INT_MIN)
		return (min_case(n, sign, count));
	else if (n == 0)
	{
		re_ptr = malloc(count + 1);
		if (!re_ptr)
			return (NULL);
		*(re_ptr + 0) = '0';
		*(re_ptr + 1) = '\0';
		return (re_ptr);
	}
	sho = n;
	while (sho > 0)
	{
		sho /= 10;
		count++;
	}
	re_ptr = malloc(count + 1);
	if (!re_ptr)
		return (NULL);
	return (convert(n, sign, count, re_ptr));
}
// ↑の関数では、ft_itoa関数から受け取った値ごとに処理を行なって値を返している.
// -2147483648の場合はmin_case関数へ、0の場合はここで処理して値を返し、正の値は必要量を計算しconvert関数へ渡す.

char	*convert(int n, int sign, size_t count, char *re_ptr)
{
	if (n > 0)
	{
		*(re_ptr + count) = '\0';
		count--;
	}
	else if (n < 0)
		n *= -1;
	while (n > 0)
	{
		*(re_ptr + count) = n % 10 + '0';
		n /= 10;
		count--;
	}
	if (sign == -1)
		*(re_ptr + count) = '-';
	return (re_ptr);
}
// ↑の関数では、与えられた配列の後ろから代入を行い、呼び出し元に返している.

char	*min_case(int n, int sign, size_t count)
{
	int		number;
	char	*re_ptr;

	number = n;
	count++;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	re_ptr = malloc(count + 1);
	if (!re_ptr)
		return (NULL);
	*(re_ptr + count) = '\0';
	count--;
	*(re_ptr + count) = (n % 10) * (-1) + '0';
	count--;
	return (convert(n / 10, sign, count, re_ptr));
}
// ↑の関数では、n=INT_MIN, sign=-1, count=0で入ってきて、まず必要容量を計算＆容量確保.
// その次に後ろから代入を行う. この時負の値を正の値で割った余りは負になるため、-1をかける
// 一つだけ代入を行なっているのは、INT_MINを-1倍してint型の最大値を超えるのを防ぐため.
// 一つだけ代入したらconvert関数へ処理を引き継がせる.

// int	main(void)
// {
// 	int		number;
// 	char	*re_ptr;

// 	number = INT_MIN;
// 	re_ptr = ft_itoa(number);
// 	printf("%s\n", re_ptr);
// }
