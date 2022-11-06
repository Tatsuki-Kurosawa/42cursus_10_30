/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:51:28 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/06 15:28:32 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
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