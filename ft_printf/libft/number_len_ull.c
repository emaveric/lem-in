/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_len_ull.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:32:10 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/19 17:32:10 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		number_len_ull(unsigned long long n)
{
	int len;

	len = 1;
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
