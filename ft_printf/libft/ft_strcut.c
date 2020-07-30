/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:33:56 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/30 11:54:23 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (s[i] != (char)c)
	{
		if (!s[--i])
			return ((char *)s);
	}
	return ((char *)&s[i + 1]);
}
