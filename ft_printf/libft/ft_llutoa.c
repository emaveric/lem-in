/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llutoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:45:23 by emaveric          #+#    #+#             */
/*   Updated: 2020/01/28 14:37:51 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_len(unsigned long long int n)
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

char			*ft_llutoa(unsigned long long int n)
{
	int		len;
	char	*res;

	if (n <= 18446744073709551615U)
	{
		len = nbr_len(n);
		if (!(res = ft_memalloc(len + 1)))
			return (NULL);
		while (--len > -1)
		{
			res[len] = (n % 10) + 48;
			n = n / 10;
		}
		return (res);
	}
	return (NULL);
}
