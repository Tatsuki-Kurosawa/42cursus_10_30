/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:51:42 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/07 02:33:31 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_char;

	i = 0;
	s_char = (unsigned char *)s;
	while (i < n)
	{
		if (*(s_char + i) == (unsigned char)c)
			return (s_char + i);
		i++;
	}
	return (NULL);
}

// int main(void)
// {
//     char buf[] = "ABCD5EFGH";
//     char *ch;
// 	// printf("%lu\n", sizeof(buf));
//     ch = (char*)ft_memchr(buf,'5',3);
//     if(ch!=NULL){
//         printf("検索文字から表示→%s\n",ch);
//     }else{
//         puts("検索文字が見つかりませんでした。");
//     }
//     return 0;
// }