/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:51:28 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/10/15 21:51:29 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #define		STRING_1	"the cake is a lie !\0I'm hidden lol\r\n"
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i + 1 < dstsize)
	{
		if (*src == '\0')
		{
			*dst = '\0';
			return (len);
		}
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (len);
}

// int main(void)
// {
// 	// char src[] = "hello";
// 	// char dest[] = "eh";
// 	char	*str = STRING_1;
// 	char	buff1[0xF00];

// 	strlcpy(buff1, str, sizeof(buff1));
// 	// strlcpy(dest, "", 0);
// 	// ft_strlcpy(dest, "", 0);
// 	printf("%s\n", buff1);
// 	printf("%s\n", str);
// }