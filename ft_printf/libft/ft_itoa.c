/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 22:52:45 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/19 17:06:49 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_num_len(int n)
{
	int len;

	len = 0;
	if (n == 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char		ft_int_to_ch(char *str, int n, int len)
{
	while (--len >= 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (*str);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*str;
	int		sign;

	sign = 0;
	len = 0;
	if (n < 0)
	{
		sign = 1;
		len++;
		n *= -1;
	}
	len += ft_num_len(n);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	str[len] = '\0';
	ft_int_to_ch(str, n, len);
	if (n * sign == -2147483648)
	{
		ft_int_to_ch(str, n - 8, len);
		str[len - 1] = '8';
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}
