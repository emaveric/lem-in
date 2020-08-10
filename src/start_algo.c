/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 12:53:56 by eshor             #+#    #+#             */
/*   Updated: 2020/08/10 18:10:19 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	flag_correction(t_lem_in *l_i)
{
	int	i;

	i = 0;
	while (i < l_i->room_num)
	{
		l_i->rooms[i]->flag = 0;
		l_i->rooms[i]->label = 0;
		l_i->rooms[i]->prev = NULL;
		i++;
	}
}

void	level_correction(t_lem_in *l_i, int flag, int k, int i)
{
	int	j;

	flag_correction(l_i);
	while (k != 0)
	{
		k = 0;
		flag = 0;
		j = i;
		while (j < l_i->room_num - 1)
		{
			if (l_i->link_arr[k][j] == 1)
			{
				if (flag == 0)
				{
					i = j + 1;
					flag = 1;
				}
				l_i->rooms[j]->level = l_i->rooms[k]->level + 1;
				k = j;
				j = 1;
			}
			j++;
		}
	}
}

void	move_directly(t_lem_in *lem_in)
{
	int		i;
	t_room	*room;

	i = 0;
	room = lem_in->paths[0]->head;
	while (i < lem_in->ant_num)
	{
		ft_printf("L%d-%s", i + 1, room->name);
		if (i != lem_in->ant_num - 1)
			ft_printf(" ");
		i++;
	}
	ft_printf("\n");
}

int		start_algo(t_lem_in *lem_in)
{
	int i;

	lem_in->rooms[0]->level = 0;
	lem_in->rooms[lem_in->room_num - 1]->level = MAX_INT;
	if (edmonds_karp(lem_in) == ERROR)
	{
		ft_printf("Path from start to end does not exist.\n");
		return (ERROR);
	}
	if (lem_in->path_num == 0)
		return (ERROR);
	i = 0;
	// while (lem_in->line[i])
	// {
	// 	ft_printf("%s\n", lem_in->line[i]);
	// 	i++;
	// }
	// ft_printf("\n");
	if (lem_in->paths[0]->len == 1)
		move_directly(lem_in);
	else
		move_ants(lem_in);
	return (0);
}
