/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:31:03 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/23 03:24:36 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (count);
	while (lst->next != NULL)
	{
		count++;
		lst = lst->next;
	}
	count++;
	return (count);
}
// ノードの数をカウント
// whileで条件を満たさなくなった場合、lstは最後のノードにいるがこの分をカウントしていないため、
// 抜けた後にインクリメントすることに注意