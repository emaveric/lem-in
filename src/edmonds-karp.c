#include "../includes/lem-in.h"

int is_room_in_path(t_lem_in *lem_in, int room_id)
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

void	refresh_visited_and_lvl(t_room **rooms, int num)
{
	int i;

	i = 1;
	while (i < num - 1)
	{
		rooms[i]->visited = 0;
		// rooms[i]->level = -1;
		rooms[i]->prev = NULL;
		i++;
	}
	rooms[num - 1]->visited = 0;
}

void	find_path_backwards(t_lem_in *lem_in, int room_id)
{
	int prev;

	while (room_id != 0)
	{
		// ft_printf("now room %s\n", lem_in->rooms[room_id]->name);
		prev = lem_in->rooms[room_id]->prev->num;
		// ft_printf("prev room %s\n", lem_in->rooms[prev]->name);
		if (lem_in->link_arr[prev][room_id] == 3)
		{
			lem_in->link_arr[prev][room_id] = 1;
			lem_in->link_arr[room_id][prev] = 2;
		}
		else if (lem_in->link_arr[prev][room_id] == 2)
		{
			lem_in->link_arr[prev][room_id] = 3;
			lem_in->link_arr[room_id][prev] = 3;
		}
		room_id = prev;
	}
}

int	find_level(t_lem_in *lem_in, int prev, int curr)
{
	if (lem_in->link_arr[prev][curr] == 3)
		return (lem_in->rooms[prev]->level + 1);
	else
		return (lem_in->rooms[prev]->level - 1);
}

int	edmonds_karp(t_lem_in *lem_in)
{
	t_queue *q;
	t_room *room;
	t_queue *new;
	int i;

	while (1)
	{
		refresh_visited_and_lvl(lem_in->rooms, lem_in->room_num);
		q = new_queue_node(lem_in->rooms[0]);
		lem_in->rooms[0]->visited = 1;
		// print_rooms(lem_in->rooms, lem_in->room_num);
		while (q)
		{
			room = pop_node(&q);
			i = 0;
			while (i < lem_in->room_num)
			{
				if (room->num != 0 && lem_in->link_arr[room->prev->num][room->num] == 3 &&
				lem_in->link_arr[room->num][i] == 3 && is_room_in_path(lem_in, room->num) == 1)
				{
					i++;
                    // ft_printf("room %s is already in path\n", room->name);
					continue;
				}
				else if (i == lem_in->room_num - 1 && lem_in->link_arr[room->num][i] == 3)
				{
					lem_in->link_arr[room->num][i] = 1;
					lem_in->link_arr[i][room->num] = 2;
					lem_in->rooms[i]->visited = 1;
					free_queue(&q);
					break;
				}
				else if (i != lem_in->room_num - 1 && lem_in->rooms[i]->visited == 0 &&
				(lem_in->link_arr[room->num][i] == 3 || lem_in->link_arr[room->num][i] == 2))
				{
					new = new_queue_node(lem_in->rooms[i]);
					if (!new)
					{
						free_queue(&q);
						return (ERROR);
					}
					new->room->prev = room;
					new->room->visited = 1;
					new->room->level = find_level(lem_in, room->num, new->room->num);
					push_node(&q, new);
				}
				i++;
			}
		}
		if (lem_in->rooms[lem_in->room_num - 1]->visited == 0)
			break;
		// ft_printf("finding path backward\n");
		find_path_backwards(lem_in, room->num);
        // ft_printf("one path found\n");
		// print_link_arr(lem_in->link_arr, lem_in->room_num);
		
	}
	// print_rooms(lem_in->rooms, lem_in->room_num);
    // print_link_arr(lem_in->link_arr, lem_in->room_num);
	return (0);
}