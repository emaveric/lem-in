/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulltoa_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 17:31:35 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/30 11:54:23 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned long long int		conv_ex(unsigned long long int nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char								*ulltoa_base(unsigned long long int value,
												int base)
{
	int						i;
	char					*str;
	unsigned long long int	tmp;

	str = NULL;
	i = 1;
	tmp = value;
	while (tmp >= (unsigned long long)base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = ft_memalloc(i + 1)))
		return (NULL);
	while (i > 0)
	{
		--i;
		tmp = value % base;
		str[i] = conv_ex(tmp);
		value /= base;
	}
	return (str);
}
