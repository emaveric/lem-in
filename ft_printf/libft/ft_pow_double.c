/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow_double.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:56:36 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/19 17:56:36 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double		ft_pow_double(long double n, unsigned long long pow)
{
	return (pow ? n * ft_pow_double(n, pow - 1) : 1);
}
