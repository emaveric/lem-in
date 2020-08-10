/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 16:24:14 by emaveric          #+#    #+#             */
/*   Updated: 2020/08/10 15:33:49 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		empty_line_check(const char *line)
{
	int		i;

	i = 0;
	if (line[0] == '\n')
		return (ERROR);
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			if (line[i + 1] && line[i + 1] == '\n')
				return (error(3, NULL));
		}
		i++;
	}
	return (0);
}

int		start_end_room_check(t_lem_in *l_i, int i, char **str)
{
	while (l_i->line[i][0] == '#')
	{
		if (ft_strcmp(l_i->line[i], "##start") == 0 ||
			ft_strcmp(l_i->line[i], "##end") == 0)
		{
			if (get_end_or_start_room(l_i, str, i + 1) == ERROR)
				return (error(7, str));
			str_free(str, 0);
			return (0);
		}
		i--;
	}
	return (1);
}

int		room_num_check(t_lem_in *l_i, int i)
{
	while (l_i->line[i][0] == '#')
		i++;
	i++;
	while (l_i->line[i])
	{
		if (l_i->line[i][0] == '#')
			if (get_command(l_i, l_i->line, i) == ERROR)
				return (error(5, NULL));
		if (link_or_room(l_i, l_i->line[i], 0) == ERROR)
			return (ERROR);
		if (l_i->line[i][0] != '#' && link_or_room(l_i, l_i->line[i], 0) != 1)
			break ;
		if (l_i->line[i][0] != '#')
		{
			if ((l_i->room_num - 1) * 2 == MAX_INT)
				return (error(9, NULL));
			l_i->room_num++;
		}
		i++;
	}
	l_i->room_num = (l_i->room_num - 1) * 2;
	if (l_i->room_num < 2 || l_i->e_r_flag == 0 || l_i->s_r_flag == 0)
		return (error(1, NULL));
	return (0);
}
