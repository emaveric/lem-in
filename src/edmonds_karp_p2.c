/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edmonds_karp_p2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:53:11 by eshor             #+#    #+#             */
/*   Updated: 2020/08/10 14:11:33 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	refresh_visited_and_lvl(t_room **rooms, int num)
{
	int i;

	i = 1;
	while (i < num - 1)
	{
		rooms[i]->visited = 0;
		rooms[i]->level = -1;
		rooms[i]->temp_prev = NULL;
		i++;
	}
	rooms[num - 1]->visited = 0;
}

void	find_path_backwards(t_lem_in *lem_in, int room_id, int flag)
{
	int prev;

	while (room_id != 0)
	{
		prev = lem_in->rooms[room_id]->temp_prev->num;
		if (lem_in->link_arr[prev][room_id] == 3)
		{
			lem_in->link_arr[prev][room_id] = 1;
			lem_in->link_arr[room_id][prev] = 2;
		}
		else if (lem_in->link_arr[prev][room_id] == 2)
		{
			lem_in->link_arr[prev][room_id] = 4;
			lem_in->link_arr[room_id][prev] = 3;
		}
		room_id = prev;
	}
}

int		find_level(t_lem_in *lem_in, int prev, int curr)
{
	if (lem_in->link_arr[prev][curr] == 3)
		return (lem_in->rooms[prev]->level + 1);
	else
		return (lem_in->rooms[prev]->level - 1);
}

void	set_true_prev(t_lem_in *lem_in)
{
	int i;

	i = 0;
	while (i < lem_in->room_num)
	{
		lem_in->rooms[i]->prev = lem_in->rooms[i]->temp_prev;
		lem_in->rooms[i]->next = lem_in->rooms[i]->temp_next;
		i++;
	}
}

void	set_optimal_path(t_lem_in *lem_in, int n_new)
{
	if (lem_in->paths_temp != NULL)
		free_paths(lem_in->paths_temp, lem_in->path_num_temp);
	lem_in->paths_temp = lem_in->paths;
	lem_in->paths = NULL;
	lem_in->path_num_temp = lem_in->path_num;
	lem_in->path_num = 0;
	lem_in->n_turns = n_new;
	set_true_prev(lem_in);
}
