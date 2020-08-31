/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfromcpy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 17:51:33 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/26 17:55:34 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfromcpy(char *dst, const char *str, size_t len)
{
	size_t	i;

	i = 0;
	while (str[len] != '\0')
	{
		dst[i] = str[len];
		i++;
		len++;
	}
	dst[i] = '\0';
	return (dst);
}
