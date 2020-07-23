/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:21:10 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/23 14:47:04 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int 	get_end_or_start_room(t_lem_in *l_i, char **str, int i)
{
	int 	j;

	if (ft_strcmp(l_i->line[i - 1], "##start") == 0)
		j = 0;
	else
		j = l_i->room_num - 1;
	ft_strcpy(l_i->rooms[j]->name, str[0]);
	if (l_i->rooms[j]->name[0] == 'L' || l_i->rooms[j]->name[0] == '#')
		return (ERROR);
	if (coord_valid(l_i, str, j) == ERROR)
		return (ERROR);
	l_i->rooms[j]->num = l_i->i;
	l_i->i++;
	return (0);
}

int		get_room(t_lem_in *l_i, char *line, int i)
{
	int 	j;
	char 	**str;

	j = 0;
	str = ft_strsplit(line, ' ');
	while (str[j])
		j++;
	if (j != 2)
		return (ERROR);
	if (ft_strcmp(l_i->line[i - 1], "##start") == 0 ||
		ft_strcmp(l_i->line[i - 1], "##end") == 0)
	{
		if (get_end_or_start_room(l_i, str, i) == ERROR)
			return (ERROR);
		return (0);
	}
	ft_strcpy(l_i->rooms[l_i->i]->name, str[0]);
	if (l_i->rooms[l_i->i]->name[0] == 'L' || l_i->rooms[l_i->i]->name[0] == '#')
		return (ERROR);
	if (coord_valid(l_i, str, l_i->i) == ERROR)
		return (ERROR);
	l_i->rooms[l_i->i]->num = l_i->i;
	l_i->i++;
	return (0);
}
