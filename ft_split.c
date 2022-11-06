/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 00:20:05 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/07 00:26:52 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**allocate(char *nc_s, size_t number_s, char **return_value);
char	*makeptr(char *s);
void	*free_memory(char **return_value, int i);
size_t	counter(char const *s, char c);

char	**ft_split(char const *s, char c)
{
	char	**return_value;
	char	*nc_s;
	int		i;
	size_t	number_s;

	if (!s)
		return (NULL);
	number_s = ft_strlen(s);
	return_value = malloc(sizeof(char *) * (counter(s, c) + 1));
	if (!return_value)
		return (NULL);
	nc_s = makeptr((char *)s);
	i = 0;
	while (*(nc_s + i))
	{
		if (*(nc_s + i) == c)
			*(nc_s + i) = '\0';
		i++;
	}
	return (allocate(nc_s, number_s, return_value));
}

char	**allocate(char *nc_s, size_t number_s, char **return_value)
{
	int	position_s;
	int	i;
	int	flag;

	position_s = 0;
	i = 0;
	flag = 0;
	while (number_s--)
	{
		if (*(nc_s + position_s) == '\0')
			flag = 0;
		else if (*(nc_s + position_s) != '\0' && flag == 0)
		{
			return_value[i] = ft_strdup((const char *)(nc_s + position_s));
			if (!return_value[i])
				return (free_memory(return_value, i));
			i++;
			flag = 1;
		}
		position_s++;
	}
	return_value[i] = NULL;
	return (return_value);
}

char	*makeptr(char *s)
{
	char	*return_ptr;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	return_ptr = malloc(len + 1);
	while (i < len)
	{
		return_ptr[i] = s[i];
		i++;
	}
	return_ptr[i] = '\0';
	return (return_ptr);
}

// 単語がいくつあるかをカウント
// 単語の先頭にきたらflagを1にし単語数をカウント、flagの1の時は区切り文字でなくても条件を満たさない. 区切り文字にきたらflagを0にする
// size_tをintのどっちを使った方がいいのか
size_t	counter(char const *s, char c)
{
	size_t	word_count;
	int		position_s;
	int		flag;

	flag = 0;
	position_s = 0;
	word_count = 0;
	while (*(s + position_s))
	{
		if (*(s + position_s) == c)
			flag = 0;
		else if (*(s + position_s) != c && flag == 0)
		{
			word_count++;
			flag = 1;
		}
		position_s++;
	}
	return (word_count);
}

// メモリ解放
void	*free_memory(char **return_value, int i)
{
	while (i > 0)
		free(return_value[i--]);
	free(return_value);
	return (NULL);
}
