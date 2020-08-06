/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:56:06 by emaveric          #+#    #+#             */
/*   Updated: 2020/08/06 17:49:22 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

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
			{
				printf("error coord\n");
				return (ERROR);
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (ft_atoi_max_int(&l_i->rooms[n]->x, str[1]) == -1)
		return (ERROR);
	if (ft_atoi_max_int(&l_i->rooms[n]->y, str[2]) == -1)
		return (ERROR);
	return (0);
}

int 	is_link_error(t_lem_in *l_i, int j, int k)
{
	if (k == -1 || j == -1)
		return (ERROR);
	if (k == 0 || j == 0)
	{
		if (l_i->link_arr[j][k] == 3 || l_i->link_arr[k][j] == 3)
			return (ERROR);
	}
    if (k == l_i->room_num - 1 || j == l_i->room_num - 1)
    {
        if (k == l_i->room_num - 1)
            if (l_i->link_arr[j + 1][k] == 3)
                return (ERROR);
        if (j == l_i->room_num - 1)
            if (l_i->link_arr[k + 1][j] == 3)
                return (ERROR);
    }
    else
        if 	(l_i->link_arr[j][k + 1] == 4 || l_i->link_arr[k][j + 1] == 4)
            return (ERROR);
	return (0);
}

int 	is_link(t_lem_in *l_i, int j, int k)
{
//	printf("num = %d	", l_i->room_num);
//	printf("k = %d, j = %d, %d %d	", k, j, l_i->link_arr[j][k + 1], l_i->link_arr[k][j + 1]);
	/*if (k == -1 || j == -1 || l_i->link_arr[j][k + 1] != 0 ||
		l_i->link_arr[j + 1][k] != 0 || l_i->link_arr[k][j] != 0)
		return (ERROR);*/
	if (is_link_error(l_i, j, k) == ERROR)
		return (ERROR);
	if (k != 0 && j != 0 && k != l_i->room_num - 1 && j != l_i->room_num - 1)
	{
		l_i->link_arr[j][k + 1] = 4;
		l_i->link_arr[k + 1][j] = 3;
		l_i->link_arr[j + 1][k] = 3;
		l_i->link_arr[k][j + 1] = 4;
	}
	else
	{
		if (k == 0 || j == 0)
		{
			l_i->link_arr[j][k] = 3;
			l_i->link_arr[k][j] = 3;
			l_i->s_l_flag = 1;
		}
		if (k == l_i->room_num - 1)
		{
			l_i->link_arr[j + 1][k] = 3;
			l_i->e_l_flag = 1;
		}
		if (j == l_i->room_num - 1)
		{
			l_i->link_arr[k + 1][j] = 3;
			l_i->e_l_flag = 1;
		}
	}
	//printf("k = %d, j = %d, %d %d\n", k, j, l_i->link_arr[j][k + 1], l_i->link_arr[k][j + 1]);
	return (0);
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
			{
				if (ft_strcmp(l_i->rooms[i]->name, l_i->rooms[j]->name) == 0 ||
				(l_i->rooms[i]->x == l_i->rooms[j]->x &&
				l_i->rooms[i]->y == l_i->rooms[j]->y))
					if (l_i->rooms[i]->d_flag != l_i->rooms[j]->num)
					{
						printf("same\n");
						return (ERROR);
					}
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int 	link_or_room(t_lem_in *l_i, const char *line, int flag)
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
	i = 0;
	if (flag == 1 && l_i->flag == 0)
		if (same_name_and_coord_valid(l_i) == ERROR)
			return (ERROR);
	//printf("%s flag %d\n", line, flag);
	while (line[i] != '\0')
	{
		if (line[i] == '-' || line[0] == '#')
			return (0);
		i++;
	}
	return (ERROR);
}
