/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 20:22:20 by emaveric          #+#    #+#             */
/*   Updated: 2020/01/16 20:22:20 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_num_to_str(int num)
{
	int		i;
	int		len;
	char	*str;

	len = ft_numlen(num);
	if (num < 0)
		len++;
	if (!(str = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
		len--;
	}
	i = len - 1;
	while (num > 9)
	{
		str[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	str[i] = num + '0';
	return (str);
}
