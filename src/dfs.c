/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:15:39 by emaveric          #+#    #+#             */
/*   Updated: 2020/08/02 20:12:20 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		is_room_in_path(t_lem_in *lem_in, int room_id)
{
	int i;
	int from;
	int to;

	i = 0;
	to = 0;
	from = 0;
	while (i < lem_in->room_num)
	{
		if (lem_in->link_arr[i][room_id] == 1 && lem_in->link_arr[room_id][i] == 2)
			from = 1;
		if (lem_in->link_arr[i][room_id] == 2 && lem_in->link_arr[room_id][i] == 1)
			to = 1;
		i++;
	}
	if (from == 1 && to == 1)
		return (1);
	return (0);
}

void 	get_label(t_lem_in *l_i, t_room *room, int i, int j)
{
	if (l_i->link_arr[room->num][i] == 2
			 && (l_i->rooms[room->num]->visited == l_i->rooms[i]->visited)
			 && l_i->rooms[room->num]->level <= l_i->rooms[i]->level)
	{
		while (j < l_i->room_num)
		{
			if (l_i->link_arr[i][j] == 3 &&
				l_i->rooms[i]->level == l_i->rooms[j]->level + 1 &&
				l_i->rooms[i]->visited == l_i->rooms[j]->visited)
				l_i->rooms[j]->label = 1;
			j++;
		}
	}
}

int 	change_links(t_lem_in *l_i, t_room **room, int i)
{
	if (l_i->link_arr[(*room)->num][i] == 1)
	{
		l_i->link_arr[(*room)->num][i] = 0;
		l_i->link_arr[i][(*room)->num] = 0;
	}
	else if (l_i->link_arr[(*room)->num][i] == 3)
	{
		l_i->link_arr[(*room)->num][i] = 2;
		l_i->link_arr[i][(*room)->num] = 1;
	}
	(*room) = l_i->rooms[i];
	return (0);
}

int 	back_path(t_lem_in *l_i, t_room *room, int i, int j)
{
	while (i < l_i->room_num)
	{
		if (((l_i->link_arr[room->num][i] == 1 && room->level ==
		l_i->rooms[i]->level + 1) || (l_i->link_arr[room->num][i] == 3
		&& room->level == l_i->rooms[i]->level - 1)) && room->visited
		== l_i->rooms[i]->visited && l_i->rooms[i]->label == 0)
			i = change_links(l_i, &room, i);
		else if (l_i->rooms[i]->label == 1)
		{
			l_i->rooms[i]->level--;
			l_i->j = i;
			while (++j < l_i->room_num)
				if (l_i->link_arr[l_i->j][j] == 2 && l_i->rooms[j]->flag == 1) // пойдет ли условие??
				{
					l_i->rooms[j]->level--;
					l_i->j = j;
					j = 0;
				}
		}
		if (i == 0)
			return (1);
		i++;
	}
	printf("что-то пошло не так, по идее сюда дойти не должно\n");
	return (1);
}

void 	reset_links(t_lem_in *l_i, int i)
{
	int		j;

	j = 1;
	while (j < l_i->room_num)
	{
		if (l_i->link_arr[i][j] == 2)
		{
			l_i->link_arr[i][j] = 3;
			l_i->link_arr[j][i] = 3;
			i = j;
			j = 0;
		}
		if (i == 0)
			return ;
		j++;
	}
}

int		dfs_p2(t_lem_in *l_i, t_room *room, t_queue **queue, int i)
{
	t_queue	*node;

	if (l_i->link_arr[room->num][i] == 3 && room->flag == 1 &&
		l_i->rooms[i]->level > 0 &&
		l_i->rooms[i]->level > room->level + 1)
	{
		reset_links(l_i, i);
		return (back_path(l_i, room, 0, -1))
	}
	else if (!(node = new_queue_node(l_i->rooms[i])))
	{
		free_queue(&(*queue));
		return (ERROR);
	}
	if (l_i->link_arr[room->num][i] == 3)
		node->room->level = room->level + 1;
	if (l_i->link_arr[room->num][i] == 2 && room->flag == 0)
	{
		node->room->level = room->level - 1;
		room->flag += 1;
	}
	//node->room->level = l_i->bfs_level;
	node->room->flag = room->flag;
	node->room->visited = (*queue)->room->visited;
	push_node(&(*queue), node);
	return (0);
}

int 	dfs(t_lem_in *l_i, int i, int j)
{
/*	int			i;
	//int 		j;
	t_queue		*node;*/
	t_room		*room;
	t_queue		*queue;

	l_i->rooms[0]->visited += 1;
	if (!(queue = new_queue_node(l_i->rooms[0])))
		return (ERROR);
	while (queue)
	{
		i = 0;
		room = pop_node(&queue);
		while (++i < l_i->room_num)
		{
			if (l_i->link_arr[room->num][i] != 1
			&& (l_i->rooms[room->num]->visited != l_i->rooms[i]->visited))
			{
				if ((j = dfs_p2(l_i, room, &queue, i)) == ERROR)
					return (ERROR);
				else if (j == 1)
					break;
			}
			else
				get_label(l_i, room, i, 1);
		}
	}
	return (0);
}