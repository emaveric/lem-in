/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 22:30:36 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/19 17:06:49 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	k;
	size_t	j;
	char	*str;

	i = 0;
	j = -1;
	if (s == NULL)
		return (0);
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
		i++;
	k = i - 1;
	while (s[i + 1] != '\0')
		i++;
	while (s[i] == 32 || s[i] == '\n' || s[i] == '\t')
		i--;
	if (i == 0)
		k = 0;
	str = (char *)malloc(sizeof(char) * (i - k + 1));
	if (str == NULL)
		return (0);
	while (++k <= i)
		str[++j] = s[k];
	str[++j] = '\0';
	return (str);
}
