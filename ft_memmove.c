/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 12:46:09 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/10/24 12:39:15 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	*ft_memmove(void *dst, const void *src, size_t len)
// {
// 	size_t	i;
// 	char	*dst_ptr;
// 	char	*src_ptr;

// 	dst_ptr = (char *)dst;
// 	src_ptr = (char *)src;
// 	if (src < dst)
// 	{
// 		while (len)
// 		{
// 			dst_ptr[len - 1] = src_ptr[len - 1];
// 			len--;
// 		}
// 	}
// 	else
// 	{
// 		i = 0;
// 		while (i < len)
// 			{
// 				dst_ptr[i] = src_ptr[i];
// 				i++;
// 			}
// 	}
// 	return (dst);
// }

// int main(void)
// {
//     char buf[] = "ABCDDEFG";
//     ft_memmove(buf+3,buf,3); //(dest, src, n)
//     printf("コピー後のbuf文字列→%s\n",buf);
//     return 0;
// }

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (!len || d == s)
		return (d);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
	}
	else
	{
		while (len--)
			*d++ = *s++;
	}
	return (dst);
}