/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:30:33 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/06 21:21:29 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*return_value(char *return_ptr, size_t count);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*return_ptr;
	size_t	count;

	count = 0;
	return_ptr = (char *)malloc(len + 1);
	if (s == NULL || !return_ptr)
		return (NULL);
	else if (start >= ft_strlen(s) || len == 0)
		return (return_value(return_ptr, count));
	else
	{
		while (count < len)
		{
			if (*(s + start + count) == '\0')
				return (return_value(return_ptr, count));
			*(return_ptr + count) = *(s + start + count);
			count++;
		}
		*(return_ptr + count) = '\0';
		return (return_ptr);
	}
}

char	*return_value(char *return_ptr, size_t count)
{
	*(return_ptr + count) = '\0';
	return (return_ptr);
}

// int	main(void)
// {
// 	char	str[40] = "i just want this part #############";
// 	size_t	size;
// 	char	*ret;

// 	size = 20;
// 	ret = ft_substr(NULL, 0, 12);
// 	if (ret == NULL)
// 		printf("%s\n", "NULLポインタカエテキテル");
// 	else
// 		// printf("ft_substr：%s, %zu\n", ret, strlen(ret));
// 		printf("%s\n", "NULLポインタカエテキテナイ");
// 	// printf("検証：%s, %zu\n", str + 5, strlen(str + 5));
// 	// if (!strncmp(ret, str + 5, size))
// 	// 	free(ret);
// }