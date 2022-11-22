/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:09:53 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/23 02:20:08 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n)
	{
		*str = '\0';
		str++;
		n--;
	}
}

// ゼロ埋めすると言うことは、asciicodeで言う0をメモリに埋めていくということ.
// asciicodeは1バイトで1文字を表現する1バイトコードなので、1バイト単位で埋められるよう汎用ポインタをchar型のポインタに変換する.

// int	main(void)
// {
// 	char buf[] = "ABCDEFGHIJK";
// 	int	*num;
// 	int	num_1;

// 	// ft_bzero(buf + 3, 1);
// 	num_1 = 512;
// 	num = &num_1;
// 	printf("before: %d\n", *num);
// 	bzero(num, 1);
// 	printf("after: %d\n", *num);
// 	// for (int i = 0; i < 11; i++)
// 	// {
// 	// 	printf("buf文字列→%c\n",buf[i]);
// 	// }
// 	return (0);
// }

// 本家ではヌルポインタが引数に渡された場合を定義していないため定義不要
// nが与えられたポインタのバイト数より大きい場合、最後まで0埋めしてabort
// 本家では警告となり、無理やり実行するとabort