/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:51:28 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/23 14:59:33 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (i + 1 < dstsize)
	{
		if (*(src + i) == '\0')
		{
			*(dst + i) = '\0';
			return (src_len);
		}
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i) = '\0';
	return (src_len);
}
// srcの長さが返ってくることによって、全てコピーされたかどうかがわかる.
// 引数として送ったdstsizeよりも返り値の方が大きかったら全てコピーできていない.
// 反対に引数として送ったdstsizeよりも返り値の方が小さかったら全てコピーできている.

// int main(void)
// {
// 	char src[] = "hello";
// 	char dest[] = "eh";
// 	// char	*str = STRING_1;
// 	// char	buff1[0xF00];

// 	// strlcpy(buff1, str, sizeof(buff1));
// 	// strlcpy(dest, src, 3);
// 	// ft_strlcpy(dest, src, 5); 
// 	printf("%lu\n", ft_strlcpy(dest, src, 4));
// 	printf("%s\n", src);
// 	printf("%s\n", dest);
// }