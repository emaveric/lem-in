/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:43:38 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/25 13:21:19 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncut(char *s, int start, int end)
{
	int		i;
	int		j;

	i = end;
	j = 0;
	while (s[i] != '\0')
	{
		s[i] = '\0';
		i++;
	}
	while (s[start + j] != '\0')
	{
		s[j] = s[start + j];
		s[start + j] = '\0';
		j++;
	}
	return (s);
}
