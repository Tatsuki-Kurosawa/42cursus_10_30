/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:17:52 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/06 20:29:07 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	while (i)
	{
		if (*((char *)s + i) == (char)c)
			return ((char *)(s + i));
		i--;
	}
	if (*((char *)s + i) == (char)c)
	{
		return ((char *)(s + i));
	}
	return (NULL);
}

// int main(void)
// {
//     char test[20] = "yuyguy";
// 	// char test[20];
//     char *p;
//     p = ft_strrchr(test,'0');
//     printf("検索文字が見つかった場所から表示→%s\n",p);
//     return 0;
// }
