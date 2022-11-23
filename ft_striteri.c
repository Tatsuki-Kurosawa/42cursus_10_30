/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:19:32 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/23 12:21:53 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (*(s + i))
		{
			f(i, (s + i));
			i++;
		}	
	}
}
// 関数ポインタが指す関数の第一引数がunsigned int型なので変換する.
// size_t型よりもunsigned int型の方が最大値大きい.