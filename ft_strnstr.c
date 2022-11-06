/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 21:03:12 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/06 20:23:29 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*r_haystack;
	int		check;

	r_haystack = (char *)haystack;
	if (haystack == NULL && len == 0)
		return (0);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	while (r_haystack)
	{
		if (len < ft_strlen(needle))
			return (NULL);
		check = ft_strncmp(r_haystack, needle, ft_strlen(needle));
		if (check == 0)
			return ((char *)r_haystack);
		len--;
		r_haystack++;
	}
	return (NULL);
}

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
