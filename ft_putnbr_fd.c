/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 20:05:19 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/23 11:55:57 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	chara;

	if (n < 0)
	{
		if (n == INT_MIN)
		{
			write(fd, "-2147483648", ft_strlen("-2147483648"));
			return ;
		}
		ft_putchar_fd('-', fd);
		n *= -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 0)
	{
		if (n < 10)
			ft_putchar_fd(n + 48, fd);
		else
		{
			chara = n % 10 + 48;
			ft_putnbr_fd(n / 10, fd);
			ft_putchar_fd(chara, fd);
		}
		return ;
	}
}
// 余りを求めた順に並べると数字の並びが逆になってしまうため、再帰関数を使って前から並べるようにする.

// int	main(void)
// {
// 	ft_putnbr_fd(100, 1);
// 	// ft_putnbr_fd(-48, 1);
// 	// printf("\n");
// 	// printf("%d\n", 46/(-10));
// }
