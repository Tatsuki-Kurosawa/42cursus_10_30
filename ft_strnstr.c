/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:03:12 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/23 15:15:10 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	cont;

	if (!haystack && needle && len == 0)
		return (NULL);
	if (ft_strlen(haystack) < ft_strlen(needle) || len < ft_strlen(needle))
		return (NULL);
	i = 0;
	cont = len - ft_strlen(needle);
	while (i <= cont)
	{
		if (ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
// haystack内にneedleがあるかどうかを判断.
// あったら合ったところのポインタを返す.
// memcmpで処理を行うが、lenで指定した範囲を超えて探してしまう場合がある.
// haystackのバイト数からneedleのバイト数を引いたバイト数分だけ、needleの先頭要素として見ていく

// int	main(void)
// {

// 			// size_t	size = 60000 * 4;
			// char	*s2 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB";
// 			// char	*s1 = malloc(size + 1);

// 			// memset(s1, 'A', size);
// 			// s1[size] = 0;
// 			// printf("%s\n", ft_strnstr(s1, s2, size));
// 			// printf("%s\n", strnstr(s1, s2, size));

// 			// ft_strnstr(s1, s2, size);
// }
