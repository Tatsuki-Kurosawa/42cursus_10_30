/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:58:27 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/23 02:51:35 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **list, t_list *new)
{
	t_list	*ptr;

	if (!*list)
		*list = new;
	else
	{
		ptr = ft_lstlast(*list);
		if (ptr != NULL)
			ptr->next = new;
	}
}

// **listが指しているノードのポインタがあるかないかで処理が分かれる.
// ない時はnewが**listの参照先になり、ある時は**listの指すノードの最後のやつに加える