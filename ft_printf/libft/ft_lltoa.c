/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 17:41:03 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/19 17:41:03 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		nbr_len(long long int n)
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

static char		ft_str_int(char *s, long long int n, int len, int neg)
{
	while (len--)
	{
		s[len] = (n % 10) + 48;
		n = n / 10;
	}
	if (neg)
		s[0] = '-';
	return ((char)s);
}

char			*ft_lltoa(long long int n)
{
	int		len;
	int		neg;
	char	*res;

	neg = 0;
	if (n >= -9223372036854775807 && n <= 9223372036854775807)
	{
		if (n < 0)
		{
			neg = 1;
			n *= -1;
		}
		len = nbr_len(n) + neg;
		if (!(res = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		ft_str_int(res, n, len, neg);
		return (res);
	}
	return (NULL);
}
