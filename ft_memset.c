/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:28:19 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/23 11:52:40 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char)s;
	if (len == 0)
		return (s);
	else
	{
		while (len)
		{
			*str = (unsigned char)c;
			str++;
			len--;
		}
		return (s);
	}
}
// sに書き込む際は第二引数をunsigned char型に変換するとあるので変換する.
// 第一引数sにはunsigned char型の値が書き込まれるためこちらも変換する.

// #include<string.h>
// int main(void)
// {
//     char buf[] = "ABCDEFGHIJK";
//     // memset(NULL, 1, 5);
//     ft_memset(NULL, 1, 5);
//     printf("buf文字列→%s\n",buf);
//     return 0;
// }

// 第一引数にNULLが入った場合はsegfaが起きる