/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 01:35:00 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/23 03:00:59 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && del)
	{
		tmp = lst;
		del(tmp->content);
		free(tmp);
	}
}
// 与えられたノードを削除したいだけなので↓でも良い.
// 削除するのはノードのコンテンツとノードを指すポインタ. 次のノードを指すポインタは削除してはならない
// free(tmp)はノードを指すポインタを解放するだけであり、次のノードを指すポインタ自体を削除することにはならない.

// if (lst && del)
// {
// 	del(lst->content);
// 	free(lst);
// }
