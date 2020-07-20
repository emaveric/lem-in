/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_max.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:42:57 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/19 17:42:57 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_max(long long int nb)
{
	if (nb == LONG_MIN)
		ft_putstr("-9223372036854775808");
	if (nb < 0 && nb != LONG_MIN)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10 && nb != LONG_MIN)
	{
		ft_putnbr_max(nb / 10);
		ft_putnbr_max(nb % 10);
	}
	else if (nb != LONG_MIN)
	{
		ft_putchar(nb + '0');
	}
}
