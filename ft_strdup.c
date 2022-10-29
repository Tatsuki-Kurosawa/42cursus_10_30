/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 20:21:36 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/10/24 20:21:37 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	number_of_byte;
	char	*ptr;

	number_of_byte = ft_strlen(s1);
	ptr = (char *)malloc(number_of_byte + 1);
	if (ptr)
	{
		ft_strlcpy(ptr, s1, number_of_byte + 1);
		*(ptr + number_of_byte + 1) = '\0';
		return (ptr);
	}
	else
		return (NULL);
}

// int	main(void)
// {
// 	char	str[10] = "";
// 	char	*str_ptr;

// 	// str_ptr = strdup(str);
// 	str_ptr = ft_strdup(str);
// 	printf("%p\n", str);
// 	printf("%s\n", str);
// 	printf("%p\n", str_ptr);
// 	printf("%s\n", str_ptr);
// }