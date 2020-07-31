#include "../includes/lem-in.h"

int are_end_inputs_filled(t_lem_in *lem_in)
{
	int i;

	i = 0;
	while (i < lem_in->room_num - 1)
	{
		if (lem_in->link_arr[lem_in->room_num - 1][i] == 3)
			return (ERROR);
		i++;
	}
	return (1);
}

void refresh_levels(t_lem_in *lem_in)
{
	int i;

	i = 1;
	while (i < lem_in->room_num - 1)
	{
		lem_in->rooms[i]->level = -1;
		i++;
	}
}

void set_path_values(t_lem_in *lem_in, int room_id)
{
	int i;
	int prev;

	prev = -1;
	while (room_id != 0)
	{
		i = 0;
		while (i < lem_in->room_num)
		{
			if (lem_in->rooms[i]->level + 1 == lem_in->rooms[room_id]->level &&
			(lem_in->link_arr[i][room_id] == 3 || lem_in->link_arr[i][room_id] == 2)
			&& lem_in->rooms[i]->visited == lem_in->rooms[room_id]->visited)
			{
				if (lem_in->link_arr[i][room_id] == 3)
				{
					lem_in->link_arr[i][room_id] = 1;
					lem_in->link_arr[room_id][i] = 2;
				}
				else if (lem_in->link_arr[i][room_id] == 2)
				{
					lem_in->link_arr[i][room_id] = 3;
					lem_in->link_arr[room_id][i] = 3;
				}
				room_id = i;
				break ;
			}
			i++;
		}
	}
}

int	edmonds_karp(t_lem_in *lem_in)
{
	t_queue *queue;
	t_room *room;
	t_queue *node;
	int i;

	while (are_end_inputs_filled(lem_in) == ERROR)
	{
		refresh_levels(lem_in);
		queue = new_queue_node(lem_in->rooms[0]);
		lem_in->rooms[0]->visited++;
		while (queue)
		{
			room = pop_node(&queue);
			lem_in->bfs_level = room->level + 1;
			i = 0;
//			form queue; if next room is end -- break
			while (i < lem_in->room_num)
			{
				if ((lem_in->link_arr[i][room->num] == 3 || lem_in->link_arr[room->num][i] == 2)
				&& lem_in->rooms[i]->visited != lem_in->rooms[0]->visited)
				{
					if (lem_in->rooms[i]->level == MAX_INT)
					{
						free_queue(&queue);
						break ;
					}
					if (!(node = new_queue_node(lem_in->rooms[i])))
					{
						free_queue(&queue);
						return (ERROR);
					}
					node->room->level = lem_in->bfs_level;
					node->room->visited = lem_in->rooms[0]->visited;
					push_node(&queue, node);
				}
				i++;
			}
		}
		lem_in->link_arr[room->num][lem_in->room_num - 1] = 1;
		lem_in->link_arr[lem_in->room_num - 1][room->num] = 2;
		set_path_values(lem_in, room->num);
//		exit(1);
	}
//	print_link_arr(lem_in->link_arr, lem_in->room_num);
}
