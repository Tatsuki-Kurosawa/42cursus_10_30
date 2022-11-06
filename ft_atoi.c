/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kurosawaitsuki <kurosawaitsuki@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 06:42:11 by kurosawaits       #+#    #+#             */
/*   Updated: 2022/11/06 19:19:11 by kurosawaits      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_ovunflow(int sign, unsigned long sum, char c)
{
	unsigned long	tmp;

	if (sign == 1)
		c++;
	tmp = LONG_MAX / 10;
	if (tmp < sum || (sum == tmp && LONG_MAX % 10 + 1 < c - '0'))
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	char	*rp_str;
	int		sign;
	long	sum;

	rp_str = (char *)str;
	sign = 1;
	sum = 0;
	while ((9 <= *rp_str && *rp_str <= 13) || *rp_str == 32)
		rp_str++;
	if (*rp_str == '+' || *rp_str == '-')
	{
		if (*rp_str == '-')
			sign = -1;
		rp_str++;
	}
	while (ft_isdigit(*rp_str))
	{
		if (sign == 1 && check_ovunflow(sign, (unsigned long)sum, *rp_str))
			return ((int) LONG_MAX);
		if (sign == -1 && check_ovunflow(sign, (unsigned long)sum, *rp_str))
			return ((int) LONG_MIN);
		sum = (*rp_str - '0') + sum * 10;
		rp_str++;
	}
	return (sum * sign);
}

// int	main(void) {
//     int n;
// 	n = ft_atoi("   +2147483649");
//     printf("%d\n", n);
//     return 0;
// }