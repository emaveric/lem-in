/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 16:15:39 by emaveric          #+#    #+#             */
/*   Updated: 2020/08/04 22:02:11 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

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
//	ft_printf("room %s\n", (*room)->name);
	if (l_i->link_arr[(*room)->num][i] == 1)
	{
		l_i->link_arr[(*room)->num][i] = 3;
		l_i->link_arr[i][(*room)->num] = 3;
	}
	else if (l_i->link_arr[(*room)->num][i] == 3)
	{
		l_i->link_arr[(*room)->num][i] = 2;
		l_i->link_arr[i][(*room)->num] = 1;
	}
	(*room) = l_i->rooms[i];
	if (i == 0)
		return (0);
	return (-1);
}

int 	back_path(t_lem_in *l_i, t_room *room, int i, int j)
{
	l_i->flag = 3;
//	printf("%s\n", room->name);
	while (i < l_i->room_num)
	{
	/*	if (((l_i->link_arr[room->num][i] == 1) ||
		(l_i->link_arr[room->num][i] == 3
		&& room->level == l_i->rooms[i]->level + 1)) && room->visited
		== l_i->rooms[i]->visited && l_i->rooms[i]->label == 0)
		{
			if ((i = change_links(l_i, &room, i)) == 0)
				return (1);
		}
		else */if (l_i->rooms[i]->label == 1)
		{
			 //printf("!!!!!\n");
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
		i++;
	}
	//printf("%s\n", room->name);
//	printf("что-то пошло не так, по идее сюда дойти не должно\n");
	return (ERROR);
}

void 	reset_links(t_lem_in *l_i, int i, t_room *room)
{
	int		j;
	int 	k;

	j = 0;
	k = i;
	l_i->flag = 3;
	while (j < l_i->room_num)
	{
		if (l_i->link_arr[i][j] == 2)
		{
			l_i->link_arr[i][j] = 3;
			l_i->link_arr[j][i] = 3;
			i = j;
			j = -1;
		}
		if (i == 0)
		{
			l_i->rooms[k]->level = room->level + 1;
			l_i->link_arr[room->num][k] = 1;
			l_i->link_arr[k][room->num] = 2;
			return ;
		}
		j++;
	}
}

int		dfs_p2(t_lem_in *l_i, t_room *room, t_queue **queue, int i)
{
	t_queue	*node;

	if (room->num != 0 && l_i->link_arr[room->prev->num][room->num] == 3 &&
		l_i->link_arr[room->num][i] == 3 && is_room_in_path(l_i, room->num) == 1)
	{
		ft_printf("condition true from room %s to room %s\n", room->name, l_i->rooms[i]->name);
		return (0);
	}


	ft_printf("no bad path\n");
	if (l_i->link_arr[room->num][i] == 3 && room->flag == 1 &&
		/*l_i->rooms[i]->level > 0 &&*/
		l_i->rooms[i]->level > room->level + 1 && is_room_in_path(l_i, i) == 1)
	{
		ft_printf("reset\n");
		reset_links(l_i, i, room);
		//back_path(l_i, room, 1, -1);
		find_path_backwards(l_i, room->num, 1);
		return (1);
//		return (back_path(l_i, room, 1, -1));
	}
	else if (!(node = new_queue_node(l_i->rooms[i])))
	{
		free_queue(&(*queue));
		return (ERROR);
	}
	if (l_i->link_arr[room->num][i] == 3 && i != l_i->room_num - 1)
		node->room->level = room->level + 1;
	if (l_i->link_arr[room->num][i] == 2 && room->flag == 0)
	{
		node->room->level = room->level - 1;
		room->flag = 1;
	}
	ft_printf("flag = %d\n", room->flag);
	//node->room->level = l_i->bfs_level;
	node->room->flag = room->flag;
	node->room->visited = room->visited;
	room->next = node->room;
	node->room->prev = room;
	push_node(queue, node);
	return (0);
}

int 	dfs(t_lem_in *l_i, int i, int j)
{
/*	int			i;
	//int 		j;
	t_queue		*node;*/
	t_room		*room;
	t_queue		*queue;

	/*l_i->rooms[0]->visited += 1;
	if (!(queue = new_queue_node(l_i->rooms[0])))
		return (ERROR);*/
	while (l_i->flag == 3)
	{
		l_i->rooms[0]->visited += 1;
		if (!(queue = new_queue_node(l_i->rooms[0])))
			return (ERROR);
		level_correction(l_i, 0, 1, 1);

		//print_rooms(l_i->rooms, l_i->room_num);
		l_i->flag = 0;
		while (queue)
		{
			i = 0;
			room = pop_node(&queue);
//			ft_printf("shto-to\n");
			while (++i < l_i->room_num)
			{
//				ft_printf("room %s\n", l_i->rooms[i]->name);
				if (l_i->link_arr[room->num][i] != 1 && l_i->link_arr[room->num][i] != 0
				&& (room->visited != l_i->rooms[i]->visited))
				{
					ft_printf("in if\n");
					if ((j = dfs_p2(l_i, room, &queue, i)) == ERROR)
						return (ERROR);
					else if (j == 1)
						break;
				}
				else
					get_label(l_i, room, i, 1);
			}
		}
		free_queue(&queue);
	}
	return (0);
}