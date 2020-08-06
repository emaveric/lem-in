/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:52:54 by emaveric          #+#    #+#             */
/*   Updated: 2020/08/06 14:38:39 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int 	get_command(t_lem_in *l_i, char **line, int i)
{
	if (ft_strcmp(line[i], "##end") == 0 && ft_strcmp(line[i - 1], "##start") == 0)
		return (ERROR);
	if (ft_strcmp(line[i], "##end") == 0)
	{
		if (l_i->e_r_flag == 1)
			return (ERROR);
		l_i->e_r_flag = 1;
	}
	else if (ft_strcmp(line[i], "##start") == 0)
	{
		if (l_i->s_r_flag == 1)
			return (ERROR);
		l_i->s_r_flag = 1;
	}
	return (0);
}

int 	get_link(t_lem_in *l_i, char *line, int i, int j)
{
	int 	k;
	char 	**str;

	k = -1;
	str = ft_strsplit(line, '-');
	if (str[2] || !str[0] || !str[1])
	{
		if (many_dashes_link(l_i, line, 0) == ERROR)
			return (ERROR);
		return (0);
	}
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
	str_free(str, 0);
	if (is_link(l_i, j, k) == ERROR)
		return (ERROR);
	return (0);
}

int		get_ant(t_lem_in *l_i, char *line)
{
	int 	j;

	j = 0;
//	printf("\n%s\n", line);
	while (line[j] != '\0')
	{
		if (ft_isdigit(line[j]) == 0)
		{
			printf("error ant\n");
			return (ERROR);
		}
		j++;
	}
	if (ft_atoi_max_int(&l_i->ant_num, line) == -1)
		return (ERROR);
	if (l_i->ant_num <= 0)
	{
		printf("zero or less ant\n");
		return (ERROR);
	}
	l_i->ant_start = l_i->ant_num;
	return (0);
}

int 	get_map_p2(t_lem_in *l_i, int i)
{
	/*if (l_i->line[i][0] == '#')
	{
		if (get_command(l_i, l_i->line, i) == ERROR)
		{
			printf("double flag\n");
			return (ERROR);
		}
	}*/
	/*else
	{*/
		//printf("%s\n", l_i->line[i]);
	//printf("%s\n", l_i->line[i]);
	if (l_i->line[i][0] != '#')
	{
		if (link_or_room(l_i, l_i->line[i], 0) == ERROR)
		{
			printf("\n??\n");
			return (ERROR);
		}
		else if (link_or_room(l_i, l_i->line[i], 1) == 0)
		{
			if (l_i->e_r_flag == 0 || l_i->s_r_flag == 0 ||
				get_link(l_i, l_i->line[i], 0, -1) == ERROR)
			{
				printf("%d, %s\n????\n", i + 1, l_i->line[i]);
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
	if (!(l_i->rooms = (t_room **)malloc(sizeof(t_room*) * l_i->room_num)))
		return (ERROR);
	while (++i < l_i->room_num)
		if (!(l_i->rooms[i] = init_room()))
			return (ERROR);
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
			ft_printf("l_i->i = %d, room_num = %d, %s\n", l_i->i, l_i->room_num, l_i->line[i]);
			ft_printf("\n!!\n");
			return (ERROR);
		}
		i++;
	}
	if (l_i->s_l_flag == 0 || l_i->e_l_flag == 0)
	{
		ft_printf("\nno links\n");
		return (ERROR);
	}
	return (0);
}