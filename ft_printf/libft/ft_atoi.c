/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 23:18:41 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/31 16:06:01 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_res_search(const char *str, int i, int sign)
{
	long long res;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((res > 922337203685477580 || (res == 922337203685477580
			&& (str[i] - '0') > 7)) && sign == 1)
			return (-1);
		else if ((res > 922337203685477580 || (res == 922337203685477580
			&& (str[i] - '0') > 8)) && sign == -1)
			return (0);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	sign = 1;
	i = 0;
	res = 0;
	while ((str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			&& str[i] != '\0')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if (str[i] == '+' && sign == 1)
		i++;
	res = ft_res_search(str, i, sign);
	if (sign == -1)
		return (res * sign);
	return (res);
}
