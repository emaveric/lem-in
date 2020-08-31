/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:10:32 by eshor             #+#    #+#             */
/*   Updated: 2020/08/10 16:51:29 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	in_end_room(t_lem_in *l, t_room *room, t_queue **q, int i)
{
	l->link_arr[room->num][i] = 1;
	l->link_arr[i][room->num] = 2;
	l->rooms[i]->visited = 1;
	find_path_backwards(l, room->num);
	free_queue(q);
}

int		add_node(t_lem_in *l, t_queue **q, t_room *room, int i)
{
	t_queue		*new;

	if (!(new = new_queue_node(l->rooms[i])))
	{
		free_queue(q);
		return (ERROR);
	}
	new->room->temp_prev = room;
	new->room->visited = 1;
	new->room->level = find_level(l, room->num, new->room->num);
	push_node(q, new);
	return (0);
}

int		traverse_queue(t_lem_in *l, t_queue **q)
{
	t_room		*room;
	int			i;

	room = pop_node(q);
	i = 0;
	while (i < l->room_num)
	{
		if (i == l->room_num - 1 && l->link_arr[room->num][i] == 3)
		{
			in_end_room(l, room, q, i);
			break ;
		}
		else if (i != l->room_num - 1 && l->rooms[i]->visited == 0 &&
		(l->link_arr[room->num][i] == 3 || l->link_arr[room->num][i] == 2))
			if (add_node(l, q, room, i) == ERROR)
				return (ERROR);
		i++;
	}
	return (0);
}

int		end_ed_karp(t_lem_in *l)
{
	l->paths = l->paths_temp;
	l->path_num = l->path_num_temp;
	return (0);
}

int		edmonds_karp(t_lem_in *l)
{
	t_queue		*q;
	int			n_new;

	while (1)
	{
		refresh_visited_and_lvl(l->rooms, l->room_num);
		q = new_queue_node(l->rooms[0]);
		while (q)
		{
			if (traverse_queue(l, &q) == ERROR)
				return (ERROR);
		}
		if ((l->paths = pathfinder(l)) == NULL
		|| (!(l->paths_temp) && l->path_num == 0))
			return (ERROR);
		n_new = count_turns(l);
		if (n_new < l->n_turns)
			set_optimal_path(l, n_new);
		else
		{
			free_paths(l->paths, l->path_num);
			break ;
		}
	}
	return (end_ed_karp(l));
}
