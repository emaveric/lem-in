/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:00:48 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/30 11:54:23 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi_base(const char *str)
{
	int		res;

	res = 0;
	if (!str)
		return (16777215);
	while (*str == '0' || *str == 'x')
		str++;
	while ((*str >= '0' && *str <= '9') ||
		(*str >= 'a' && *str <= 'f') || (*str >= 'A' && *str <= 'F'))
	{
		res = res * 16 + (*str - 48);
		str++;
	}
	return (res);
}
