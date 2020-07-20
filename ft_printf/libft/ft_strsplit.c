/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 17:16:59 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/19 17:06:49 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char const *s, char c)
{
	int	count;
	int	k;

	k = 0;
	count = 0;
	while (s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		if (s[k] != '\0' && s[k] != c)
			count++;
		while (s[k] != c && s[k] != '\0')
			k++;
	}
	return (count);
}

static int		ft_splitlen(char const *s, char c, int k)
{
	int	len;

	len = 0;
	while (s[k] != '\0' && s[k] != c)
	{
		len++;
		k++;
	}
	return (len);
}

static void		ft_splitfree(char **str, int i)
{
	while (i > 0)
	{
		i--;
		ft_strdel(&str[i]);
	}
	free(str);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	k;
	char	**str;

	i = 0;
	k = 0;
	if (!s)
		return (0);
	if (!(str = (char **)malloc(sizeof(char*) * (ft_words(s, c) + 1))))
		return (0);
	while (s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		if (s[k] != '\0' && s[k] != c)
			if (!(str[i++] = ft_strsub(s, k, ft_splitlen(s, c, k))))
			{
				ft_splitfree(str, i);
				return (0);
			}
		k += ft_splitlen(s, c, k);
	}
	str[i] = NULL;
	return (str);
}
