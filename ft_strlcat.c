/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:47:46 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/10/17 22:54:58 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char	*restrict_dst, const char *restrict_src, size_t dstsize)
{
	size_t	dst_len;
	size_t	count;
	char	*src;

	if (!restrict_dst && restrict_src && dstsize == 0)
		return (ft_strlen(restrict_src));
	dst_len = ft_strlen((const char *)restrict_dst);
	if (dstsize < dst_len)
		return (dstsize + ft_strlen(restrict_src));
	src = (char *)restrict_src;
	count = 0;
	restrict_dst += dst_len;
	while (dstsize > dst_len + count + 1)
	{
		if (*src == '\0')
		{
			*restrict_dst = '\0';	
			return (dst_len + count);
		}
		*restrict_dst++ = *src++;
		count++;
	}
	*restrict_dst = '\0';
	return (dst_len + ft_strlen(restrict_src));
}

// int main(void)
// {
// 	size_t i;
// 	char src[] = "hello";
// 	char dest[] = "world";
// 	i = strlcat(dest, src, 5);
// 	printf("%zu\n", i);
// 	printf("%s\n", src);   // hello
// 	printf("%s\n", dest);   // world
// }

// ↓ここから↓

// #include<libc.h>
// int main()
// {
// // char *dst2 = calloc(100, sizeof(char));
// // for (int i = 0; i < 5; i++)
// // {
// // 	dst2[i] = i + '0';
// // }

// char *dst2;
// dst2 = NULL;

// //printf("%zu¥n",strlcat(dst2, "mybad",5));
// // printf("%s\n", dst2);
// //strlcat("\0AAAAAAAAAAAAAAAA", "\0AAAAAAAAAAAAAAAA", 10);
// // ft_strlcat("\0AAAAAAAAAAAAAAAA", "\0AAAAAAAAAAAAAAAA", 10);
// // strlcat(dst2, "42tokyo", 0);
// printf("%zu¥n", ft_strlcat(dst2, "42tokyo",0));
// //ft_strlcat(dst2, "42tokyo", 0);
// // ft_strlcat(dst2, "42tokyo", 9);
// printf("%s\n", dst2);
// }