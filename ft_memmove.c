/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:46:09 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/23 11:43:31 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!len || d == s)
		return (d);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}
// voidポインタ型だと一度に見るべき容量がわからないため、どの容量にも対応できるよう1バイトでみれるcharポインタ型を利用.
// 変換を行なってからコピーを行う.
// メモリの位置によりコピーの仕方を変更する.

// int main(void)
// {
//     char buf[] = "ABCDDEFG";
//     ft_memmove(buf+3,buf,3); //(dest, src, n)
//     printf("コピー後のbuf文字列→%s\n",buf);
//     return 0;
// }

// どちらかがNULLの場合、segfaが起きる