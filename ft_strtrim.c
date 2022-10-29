/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:55:14 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/10/20 21:14:46 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*back_check(char *malloc_ptr, char const *set);

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char		*malloc_ptr;
// 	const char	*r_s1;
// 	int			count_set;
// 	int			flag;

// 	r_s1 = s1;
// 	malloc_ptr = (char *)malloc(ft_strlen(r_s1) + 1);
// 	if (!malloc_ptr)
// 		return (NULL);
// 	count_set = 0;
// 	flag = 1;
// 	while (flag == 1)
// 	{
// 		flag = 0;
// 		while (*(set + count_set) != '\0' || flag != 1)
// 		{
// 			if (ft_strchr(r_s1, *(set + count_set)) != NULL)
// 				flag = 1;
// 			count_set++;
// 		}
// 		count_set = 0;
// 		r_s1++;
// 	}
// 	// printf("%s\n", "通過");
// 	r_s1--;
// 	printf("%p\n", r_s1);
// 	// malloc_ptr = (char *)s1;
// 	// return (malloc_ptr);
// 	return (r_s1);
// 	// return (back_check(malloc_ptr, set));
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	char const	*head;
	char const	*tail;
	char		*str;

	if (!s1)
		return (NULL);
	head = s1;
	tail = s1 + ft_strlen(s1) - 1;
	while (*head)
	{
		if (!ft_strchr(set, *head))
			break ;
		head++;
	}
	while (head < tail)
	{
		if (!ft_strchr(set, *tail))
			break ;
		tail--;
	}
	tail++;
	str = ft_substr(head, 0, tail - head);
	return (str);
}

// long code
// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	char const	*head;
// 	char const	*tail;
// 	char 		*str;
// 	size_t 		i;

// 	if (!s1)
// 		return (NULL);
// 	head = s1;
// 	tail = s1 + ft_strlen(s1) - 1;
// 	while (*head)
// 	{
// 		i = 0;
// 		while (*(set + i))
// 		{
// 			if (*head == *(set + i))
// 				break ;
// 			i++;
// 		}
// 		if (!*(set + i))
// 			break ;
// 		head++;
// 	}
// 	while (head < tail)
// 	{
// 		i = 0;
// 		while (*(set + i))
// 		{
// 			if (*tail == *(set + i))
// 				break ;
// 			i++;
// 		}
// 		if (!*(set + i))
// 		{
// 			tail++;
// 			break ;
// 		}
// 		tail--;
// 	}
// 	str = malloc(tail - head + 1);
// 	i = 0;
// 	while (head + i < tail)
// 	{
// 		*(str + i) = *(head + i);
// 		i++;
// 	}
// 	*(str + i) = '\0';
// 	return (str);
// }






// char	*back_check(char *malloc_ptr, char const *set)
// {
// 	size_t	number_of_byte;
// 	int		count_set;
// 	int		flag;

// 	number_of_byte = ft_strlen(malloc_ptr);
// 	count_set = 0;
// 	flag = 1;
// 	while (flag == 1 || number_of_byte >= 0)
// 	{
// 		flag = 0;
// 		while (*(set + count_set) != '\0' || flag != 1)
// 		{
// 			if (*(malloc_ptr + number_of_byte - 1) == *(set + count_set))
// 				flag = 1;
// 			count_set++;
// 		}
// 		count_set = 0;
// 		number_of_byte--;
// 	}
// 	*(malloc_ptr + number_of_byte + 2) = '\0';
// 	return (malloc_ptr);
// }

// int	main(void)
// {
// 	char	s1[12] = "1234AAA1212";
// 	char	set[5] = "1234";
// 	char	*return_value;

// 	// return_value = ft_strtrim(s1, set);
// 	return_value = ft_strtrim("hello world", "abcdefghijklmnopqrstuvwxyz");
// 	printf("%s\n", return_value);
// }