/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:47:46 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/02 20:06:04 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char	*restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	dst_len;
	size_t	count;
	char	*c_src;

	if (!dst && src && dstsize == 0)
		return (ft_strlen(src));
	dst_len = ft_strlen((const char *)dst);
	if (dstsize < dst_len)
		return (dstsize + ft_strlen(src));
	c_src = (char *)src;
	count = 0;
	dst += dst_len;
	while (dstsize > dst_len + count + 1)
	{
		if (*src == '\0')
		{
			*dst = '\0';	
			return (dst_len + count);
		}
		*dst++ = *src++;
		count++;
	}
	*dst = '\0';
	return (dst_len + ft_strlen(c_src));
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