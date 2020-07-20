/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 22:10:53 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/19 17:06:49 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*str;

	i = 0;
	if (s != NULL && f != NULL)
	{
		str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (str == NULL)
			return (0);
		while (s[i] != '\0')
		{
			str[i] = f((unsigned int)i, s[i]);
			i++;
		}
		str[i] = '\0';
	}
	else
		return (0);
	return (str);
}
