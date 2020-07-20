/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 17:49:48 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/19 17:49:48 by emaveric         ###   ########.fr       */
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

static char		ft_str_int(char *s, unsigned long long int n, int len)
{
	while (len--)
	{
		s[len] = (n % 10) + 48;
		n = n / 10;
	}
	return ((char)s);
}

char			*ft_ulltoa(unsigned long long int n)
{
	int		len;
	char	*res;

	if (n <= 18446744073709551615ull)
	{
		len = nbr_len(n);
		if (!(res = ft_memalloc(len + 1)))
			return (NULL);
		ft_str_int(res, n, len);
		return (res);
	}
	return (NULL);
}
