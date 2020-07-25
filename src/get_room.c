/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 21:21:10 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/25 20:16:10 by emaveric         ###   ########.fr       */
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
	if (!(l_i->rooms[j]->name = ft_memalloc(ft_strlen(str[0]) + 1)))//(char*)malloc(sizeof(char) * ft_strlen(str[0]))))
		return (ERROR);
	ft_strcpy(l_i->rooms[j]->name, str[0]);
	if (l_i->rooms[j]->name[0] == 'L' || l_i->rooms[j]->name[0] == '#')
		return (ERROR);
	if (coord_valid(l_i, str, j) == ERROR)
		return (ERROR);
	l_i->rooms[j]->num = j;
	return (0);
}

int		get_room(t_lem_in *l_i, char *line, int i, int j)
{
	char 	**str;

	//printf("%s\n", line);
	if (ft_check_space(line) == ERROR)
		return (ERROR);
	str = ft_strsplit(line, ' ');
	while (str[j])
		j++;
	if (j != 3)
	{
		printf ("j = %d\n", j);
		return (ERROR);
	}
	j = start_end_room_check(l_i, i - 1, str);
	if (j == ERROR)
		return (ERROR);
	else if (j == 0)
		return (0);
	if (!(l_i->rooms[l_i->i]->name = ft_memalloc(ft_strlen(str[0]) + 1)))
		return (ERROR);
	ft_strcpy(l_i->rooms[l_i->i]->name, str[0]);
	if (l_i->rooms[l_i->i]->name[0] == 'L' || l_i->rooms[l_i->i]->name[0] == '#')
		return (ERROR);
	if (coord_valid(l_i, str, l_i->i) == ERROR)
		return (ERROR);
	l_i->rooms[l_i->i]->num = l_i->i;
	l_i->i++;
	return (0);
}
