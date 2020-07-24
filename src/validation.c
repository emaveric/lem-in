/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:56:06 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/24 14:25:06 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		empty_line_check(const char *line)
{
	int 	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '\n')
		{
			if (line[i +1] && line[i + 1] == '\n')
				return (ERROR); // написать общую функцию для ошибок
		}
		i++;
	}
	return (0);
}

int 	coord_valid(t_lem_in *l_i, char **str, int n)
{
	int 	i;
	int 	j;

	i = 0;
	j = 1;
	while (j < 3)
	{
		while (str[j][i] != '\0')
		{
			if (ft_isdigit(str[j][i]) == 0)
				return (ERROR);
			i++;
		}
		j++;
	}
	if (ft_atoi_max_int(&l_i->rooms[n]->x, str[1]) == -1)
		return (ERROR);
	if (ft_atoi_max_int(&l_i->rooms[n]->y, str[2]) == -1)
		return (ERROR);
	return (0);
}

int 	is_link(t_lem_in *l_i)
{
	int 	i;
	int 	j;

	i = 0;
	j = 0;
	while (i < l_i->room_num)
	{
		while (j < l_i->room_num)
		{
			if (l_i->link_arr[i][j] == 1 && l_i->link_arr[j][i] == 1)
				return (0);
			j++;
		}
		i++;
		j = 0;
	}
	//printf("\nno links\n");
	return (ERROR);
}

int 	same_name_and_coord_valid(t_lem_in *l_i)
{
	int		i;
	int 	j;

	i = 0;
	j = 1;
	while (i < l_i->room_num)
	{
		while (j < l_i->room_num)
		{
			if (i != j)
				if (ft_strcmp(l_i->rooms[i]->name, l_i->rooms[j]->name) == 0 ||
					(l_i->rooms[i]->x == l_i->rooms[j]->x &&
					l_i->rooms[i]->y == l_i->rooms[j]->y))
					return (ERROR);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int 	link_or_room(t_lem_in *l_i, const char *line)
{
	int 	i;

	i = 0;
	while (line[i] != '\0' && line[i] != ' ')
		i++;
	if (line[i] == ' ')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
			return (ERROR);
		else
			return (1);
	}
	return (0);
}
