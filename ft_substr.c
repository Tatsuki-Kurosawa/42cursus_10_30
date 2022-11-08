/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:30:33 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/08 18:23:13 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*set_null(char *return_ptr, size_t count);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*return_ptr;
	size_t	count;

	count = 0;
	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - (size_t)start)
		return_ptr = (char *)malloc(strlen(s) - (size_t)start + 1);
	else
		return_ptr = (char *)malloc(len + 1);
	if (!return_ptr)
		return (NULL);
	else
	{
		while (count < len)
		{
			if (*(s + start + count) == '\0')
				return (set_null(return_ptr, count));
			*(return_ptr + count) = *(s + start + count);
			count++;
		}
		*(return_ptr + count) = '\0';
		return (return_ptr);
	}
}

char	*set_null(char *return_ptr, size_t count)
{
	*(return_ptr + count) = '\0';
	return (return_ptr);
}

// 指定した場所から文字列を複製する