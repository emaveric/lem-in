/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:24:14 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/25 20:12:38 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		empty_line_check(const char *line)
{
	int 	i;

	i = 0;
	if (line[0] == '\n')
		return (ERROR);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			if (line[i +1] && line[i + 1] == '\n')
				return (ERROR); // написать общую функцию для ошибок
		}
		i++;
	}
	/*if (line[i - 1] == '\n') // нужно ли?
		return (ERROR);*/
	return (0);
}

int 	start_end_room_check(t_lem_in *l_i, int i, char **str)
{
	//printf("%s\n", l_i->line[i + 1]);
	while (l_i->line[i][0] == '#')
	{
		if (ft_strcmp(l_i->line[i], "##start") == 0 ||
			ft_strcmp(l_i->line[i], "##end") == 0)
		{
			/*if (((ft_strcmp(l_i->line[i], "##start") == 0) && l_i->s_flag == 1)
				|| ((ft_strcmp(l_i->line[i], "##end") == 0) && l_i->e_flag == 1))
			{
				printf("double flag\n");
				return (ERROR);
			}*/
			if (get_end_or_start_room(l_i, str, i + 1) == ERROR)
				return (ERROR);
			return (0);
		}
		i--;
	}
	return (1);
}

int 	room_num_check(t_lem_in *l_i)
{
	int 	i;

	i = 0;
	while (l_i->line[i][0] == '#')
		i++;
	i++;
	while (l_i->line[i])
	{
		if (link_or_room(l_i, l_i->line[i]) == ERROR)
			return (ERROR);
		if (l_i->line[i][0] != '#' && link_or_room(l_i, l_i->line[i]) != 1)
			break;
		if (l_i->line[i][0] != '#')
		{
			if (l_i->room_num == MAX_INT)
				return (ERROR);
			l_i->room_num++;
		}
		i++;
	}
	if (l_i->room_num < 2)
		return (ERROR);
	return (0);
}