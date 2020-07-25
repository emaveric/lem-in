/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:52:54 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/25 16:32:04 by emaveric         ###   ########.fr       */
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
	int 	j;
	int 	k;
	char 	**str;

	j = -1;
	k = -1;
	str = ft_strsplit(line, '-');
	while (i < l_i->room_num)
	{
		if (ft_strcmp(l_i->rooms[i]->name, str[0]) == 0 &&
			ft_strcmp(l_i->rooms[i]->name, str[1]) == 0)
			return (ERROR);
		if (ft_strcmp(l_i->rooms[i]->name, str[0]) == 0)
			j = l_i->rooms[i]->num;
		if (ft_strcmp(l_i->rooms[i]->name, str[1]) == 0)
			k = l_i->rooms[i]->num;
		i++;
	}
	if ((k == -1 || j == -1) ||
		l_i->link_arr[j][k] == 1 || l_i->link_arr[k][j] == 1)
	{
		printf("k = %d, j = %d, [j][k] = %d, [k][j] = %d, same link\n", k, j, l_i->link_arr[j][k], l_i->link_arr[k][j]);
		return (ERROR);
	}
	l_i->link_arr[j][k] = 1;
	l_i->link_arr[k][j] = 1;
	l_i->link_num++;
	return (0);
}

int		get_ant(t_lem_in *l_i, char *line)
{
	int 	j;

	j = 0;
	printf("\n%s\n", line);
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
	else
	{
		if (link_or_room(l_i, l_i->line[i]) == ERROR)
		{
			printf("\n??\n");
			return (ERROR);
		}
		else if (link_or_room(l_i, l_i->line[i]) == 0)
		{
			if (l_i->e_flag == 0 || l_i->s_flag == 0 ||
				same_name_and_coord_valid(l_i) == ERROR
				|| get_link(l_i, l_i->line[i], 0) == ERROR)
			{
				printf("%d, %s\n????\n", i, l_i->line[i]);
				return (ERROR);
			}
			l_i->flag = 1;
		}
		else
		{
			if (l_i->flag == 1 || get_room(l_i, l_i->line[i], i, 0) == ERROR)
			{
				printf("\n???\n");
				return (ERROR);
			}
		}
	}
	return (0);
}

int		get_map(t_lem_in *l_i, int i)
{
	while (i < l_i->room_num)
	{
		if (!(l_i->rooms[i] = init_room()))
			return (ERROR);
		i++;
	}
	if (!(l_i->link_arr = init_link_arr(l_i)))
		return (ERROR);
	i = 0;
	while (l_i->line[i][0] == '#')
		i++;
	if (get_ant(l_i, l_i->line[i]) == ERROR)
		return (ERROR);
	i++;
	while (l_i->line[i])
	{
		if (get_map_p2(l_i, i) == ERROR)
			return (ERROR);
		if (l_i->i >= l_i->room_num)
		{
			//printf("%s\n", l_i->line[i]);
			//printf("\n!!\n");
			return (ERROR);
		}
		i++;
	}
	if (is_link(l_i) == ERROR)
	{
		//printf("\nno links\n");
		return (ERROR);
	}
	return (0);
}