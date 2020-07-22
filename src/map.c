/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:52:54 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/22 21:33:15 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int 	get_command(t_lem_in *l_i, char **line, int i)
{
	if (ft_strcmp(line[i], "##end") == 0)
	{
		if (l_i->e_flag == 1)
			return (ERROR);
		l_i->e_flag = 1;
	}
	else if (ft_strcmp(line[i], "##start") == 0)
	{
		if (l_i->s_flag == 1)
			return (ERROR);
		l_i->s_flag = 1;
	}
	return (0);
}

int 	get_link(t_lem_in *l_i, char *line, int i)
{
	l_i->link_num++;
	return (0);
}


int		get_ant(t_lem_in *l_i, char *line)
{
	int 	j;

	j = 0;
	while (line[j] != '\0')
	{
		if (ft_isdigit(line[j]) == 0)
			return (ERROR);
		j++;
	}
	if (ft_atoi_max_int(&l_i->ant_num, line) == -1)
		return (ERROR);
	l_i->ant_start = l_i->ant_num;
	return (0);
}

int 	get_map_p2(t_lem_in *l_i, int i)
{
	if (l_i->line[i][0] == '#')
		get_command(l_i, l_i->line, i);
	if (link_valid(l_i, l_i->line[i]) == ERROR)
		return (ERROR);
	else if (link_valid(l_i, l_i->line[i]) == 0)
	{
		get_link(l_i, l_i->line[i], i);
		l_i->flag = 1;
	}
	else
	{
		if (l_i->flag == 0)
			get_room(l_i, l_i->line[i]);
		else
			return (ERROR);
	}
	return (0);
}

int		get_map(t_lem_in *l_i)
{
	int 	i;

	i = 1;
	if (get_ant(l_i, l_i->line[0]) == ERROR)
		return (ERROR);
	while (l_i->line[i])
	{
		if (get_map_p2(l_i, i) == ERROR)
			return (ERROR);
		i++;
	}
	return (0);
}