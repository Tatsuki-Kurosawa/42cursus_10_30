/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:28:19 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/10/15 18:00:29 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;

	str = s;
	if (n <= 0)
		return (s);
	else
	{
		while (n)
		{
			*str = c;
			str++;
			n--;
		}
		return (s);
	}
}

// #include<string.h>
// int main(void)
// {
//     char buf[] = "ABCDEFGHIJK";
	
//     // memset(NULL, 1, 5);
//     ft_memset(NULL, 1, 5);
//     printf("buf文字列→%s\n",buf);
//     return 0;
// }
