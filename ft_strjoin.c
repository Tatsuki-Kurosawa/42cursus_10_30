/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:20:11 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/06 20:20:12 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s1_joined;
	size_t	number_of_byte;
	size_t	count_1;
	size_t	count_2;

	if (!s1 || !s2)
		return (NULL);
	number_of_byte = ft_strlen(s1) + ft_strlen(s2);
	s1_joined = (char *)malloc(number_of_byte);
	if (!s1_joined)
		return (NULL);
	count_1 = 0;
	count_2 = 0;
	while (*(s1 + count_1) != '\0')
	{
		*(s1_joined + count_1) = *(s1 + count_1);
		count_1++;
	}
	while (*(s2 + count_2) != '\0')
	{
		*(s1_joined + count_1) = *(s2 + count_2);
		count_1++;
		count_2++;
	}
	*(s1_joined + count_1) = '\0';
	return (s1_joined);
}

// int	main(void)
// {
// 	char	*s1 = "my favorite animal is";
// 	char	*s2 = " ";
// 	char	*s3 = "the nyancat";
// 	size_t	number;

// 	char	*res = ft_strjoin(s1, s2);
// 	// char	*res = ft_strjoin(ft_strjoin(s1, s2), s3);
// 	printf("%s\n", res);
// 	number = strlen(res);
// 	printf("%zu\n", number);
// }


// ヌルポインタ送った場合の処理ができてない？