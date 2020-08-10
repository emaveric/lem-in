/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_dashes_link.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:33:42 by emaveric          #+#    #+#             */
/*   Updated: 2020/08/10 16:49:16 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		second_name(t_lem_in *l_i, char *str1, int i)
{
	while (i < l_i->room_num)
	{
		if (ft_strcmp(l_i->rooms[i]->name, str1) == 0 && l_i->j != i)
			break ;
		i++;
	}
	free(str1);
	if (i < l_i->room_num)
	{
		if (is_link(l_i, l_i->j, i) == ERROR)
			return (ERROR);
		l_i->j = 0;
		return (0);
	}
	return (ERROR);
}

int		first_name(t_lem_in *l_i, const char *line, int k, const int *len)
{
	char	*str1;
	int		i;

	i = 0;
	while (l_i->j < k)
	{
		if (!(str1 = ft_memalloc(len[l_i->j] + 1)))
			return (ERROR);
		str1 = ft_strncpy(str1, line, len[l_i->j]);
		str1[len[l_i->j] + 1] = '\0';
		while (i < l_i->room_num)
		{
			if (ft_strcmp(l_i->rooms[i]->name, str1) == 0)
				break ;
			i++;
		}
		free(str1);
		if (i < l_i->room_num)
			break ;
		l_i->j++;
		i = 0;
	}
	if (l_i->j == k)
		return (ERROR);
	return (i);
}

void	len_search(const char *line, t_lem_in *l_i, int k, int *len)
{
	int		i;

	i = 1;
	if (k != (int)ft_strlen(line) && l_i->j == 0)
		i = 0;
	l_i->j = 0;
	if (i == 1)
		len[0] = 1;
	else
		while (line[i] == '-')
		{
			len[0] += 1;
			i++;
		}
	while (line[i] != '\0')
	{
		if (line[i] == '-')
		{
			l_i->j++;
			len[l_i->j] = len[l_i->j - 1];
		}
		len[l_i->j] += 1;
		i++;
	}
}

int		only_dashes(t_lem_in *l_i, const char *line, int i, int k)
{
	while (line[i] == '-')
		i++;
	l_i->j = i;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			k++;
		i++;
	}
	if (k == 0 && line[l_i->j] != '\0')
		k = l_i->j;
	if (k == 0)
		k = ft_strlen(line);
	return (k);
}

int		many_dashes_link(t_lem_in *l_i, const char *line, int i)
{
	int		k;
	int		flag;
	int		*len;
	char	*str1;

	k = only_dashes(l_i, line, i, 0);
	flag = l_i->j;
	if (!(len = (int *)malloc(sizeof(int) * k + 1)))
		return (ERROR);
	len_search(line, l_i, k, len);
	len[l_i->j + 1] = -1;
	l_i->j = 0;
	if ((i = first_name(l_i, line, k, len)) == ERROR)
		return (free_len(len));
	if (k == (int)ft_strlen(line) || flag != 0)
		k--;
	if (!(str1 = ft_memalloc(len[k] - len[l_i->j])))
		return (free_len(len));
	str1 = ft_strfromcpy(str1, line, len[l_i->j] + 1);
	l_i->j = i;
	if (second_name(l_i, str1, 0) == ERROR)
		return (free_len(len));
	free(len);
	return (0);
}
