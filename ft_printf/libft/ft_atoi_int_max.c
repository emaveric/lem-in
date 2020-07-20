/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_int_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:48:02 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 18:54:10 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_if_neg(const char *str, int i)
{
	int neg;

	neg = 0;
	if (str[i] == '-')
		neg = 1;
	return (neg);
}

int				ft_atoi_max_int(int *n, const char *str)
{
	int			i;
	int			neg;
	long long	res;

	i = 0;
	res = 0;
	if (str == NULL || str[i] == '\0')
		return (-1);
	while ((str[i] == 32) || (str[i] >= 9 && str[i] <= 13 && str[i] != '\0'))
		i++;
	if ((neg = ft_if_neg(str, i)) && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	if (str[i] == '+' && str[i + 1] >= '0' && str[i + 1] <= '9')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if ((!neg && (res * 10 + (str[i] - '0') > 2147483647))
			|| (neg && (res * 10 + (str[i] - '0') > 2147483648)))
			return (-1);
		res = res * 10 + (str[i++] - '0');
	}
	if (neg)
		res = -(res);
	*n = (int)res;
	return (1);
}
