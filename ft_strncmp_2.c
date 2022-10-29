/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:43:51 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/10/16 07:27:20 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;

	while (i < n)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (0);
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	main(void)
{
	char	*s1 = "atoms\0\0\0\0";
	char	*s2 = "atoms\0abc";

	printf("%d\n", strncmp(s1, s2, 8));
	printf("%d\n", ft_strncmp(s1, s2, 8));
}

// int main(int argc, char const *argv[])
// {
// 	printf("%d¥n", CHAR_MIN);
// 	return 0;
// }
// #include<string.h>
// #
// // int main()
// {
// 	printf("%d",strncmp("asafr",NULL,2));
// 	// printf("%d",ft_strncmp("asafr",NULL,2));
// 	return 0;

// }