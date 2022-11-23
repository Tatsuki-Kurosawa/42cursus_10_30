/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:38:34 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/23 11:40:12 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	char	*str_dest;
	char	*str_src;

	if (!dest && !src)
		return (NULL);
	str_dest = (char *)dest;
	str_src = (char *)src;
	while (n != 0)
	{
		*str_dest = *str_src;
		str_dest++;
		str_src++;
		n--;
	}
	return ((void *)dest);
}
// voidポインタ型だと一度に見るべき容量がわからないため、どの容量にも対応できるよう1バイトでみれるcharポインタ型を利用.
// 変換を行なってからコピーを行う.
// メモリが被った時の動作は未定義なので、引数にrestrictの修飾子あり.

// int	main(void)
// {
// 	// char	src[] = "test basic du memcpy !";
// 	char	*src = NULL;
// 	char	dst[22] = "abcdjefk";

// 	memcpy(dst, src, 22);
// 	printf("コピー後のbuf文字列→%s\n",dst);
// 	// ft_memcpy(dst, src, 22);
// 	// printf("コピー後のbuf文字列→%s\n",dst);
// }

// srcとdstの容量は同じでなくてはならないのか
// どちらかがNULLの時はsegfaが起きる