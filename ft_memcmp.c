/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 19:30:08 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/06 19:30:26 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_char;
	unsigned char	*s2_char;

	s1_char = (unsigned char *)s1;
	s2_char = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (*s1_char != *s2_char)
		{
			if (*s1_char < *s2_char)
				return (*s1_char - *s2_char);
			else if (*s1_char > *s2_char)
				return (*s1_char - *s2_char);
		}
		i++;
		s1_char++;
		s2_char++;
	}
	return (0);
}

// int main(void)
// {
//     char buf[] = "ABCD5EFGH";
//     char buf2[] = "ABC123456";

//     if(ft_memcmp(buf,buf2,4)==0){
//         puts("先頭から3バイトは一致しています。");
// 		printf("%d\n", ft_memcmp(buf,buf2,4));
//     }else{
//         puts("一致していません。");
//     }
//     return 0;
// }