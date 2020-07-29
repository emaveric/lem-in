#include "../includes/lem-in.h"

/*
 * returns the length of the shortest path from room_id to end
 * and
 */
int		find_shortest(t_lem_in *lem_in, int room_id)
{
	int		best_path;
	t_room	*temp;

	best_path = 0;
	temp = lem_in->rooms[room_id];
	if (lem_in->rooms[room_id]->level == MAX_INT)
		return (0);
	while (temp->next)
	{
		best_path++;
		temp = temp->next;
	}
	if (temp->level != MAX_INT)
		return (MAX_INT);
	return (best_path - 1);
}

t_room	*add_allprev_to_queue(t_lem_in *lem_in, t_queue **queue)
{
	int		j;
	t_room	*room;
	t_queue	*node;

	room = pop_node(queue);
	j = 1;
	while (j < lem_in->room_num)
	{
		if ((room->level == MAX_INT && lem_in->link_arr[room->num][j] == 1
		&& lem_in->rooms[j]->visited != 3) ||
		(room->level != MAX_INT && lem_in->rooms[j]->level == room->level - 1
		&& lem_in->rooms[j]->visited != 3 && j != 0
		&& lem_in->link_arr[room->num][j] == 1))
		{
			if (!(node = new_queue_node(lem_in->rooms[j])))
				return (NULL);
			node->room->visited = 3;
			push_node(queue, node);
		}
		j++;
	}
	return (room);
}

int		find_best_room(t_lem_in *lem_in, t_room *room, int j)
{
	int best_path;
	int curr_path;
	int best_room;

	best_path = MAX_INT;
	if (lem_in->link_arr[lem_in->room_num - 1][room->num] == 1)
		best_room = lem_in->room_num - 1;
	else
	{
		while (j < lem_in->room_num)
		{
			if (lem_in->link_arr[j][room->num] == 1 &&
			room->level < lem_in->rooms[j]->level)
			{
				curr_path = find_shortest(lem_in, j);
				best_room = (curr_path < best_path) ? j : best_room;
				best_path = (curr_path < best_path) ? curr_path : best_path;
			}
			j++;
		}
	}
	return (best_room);
}

void	delete_extra(t_lem_in *lem_in, t_room *room, int best_room)
{
	int j;

	j = 1;
	room->next = lem_in->rooms[best_room];
	while (j < lem_in->room_num)
	{
		if (lem_in->link_arr[j][room->num] == 1 &&
			room->level < lem_in->rooms[j]->level && j != best_room)
		{
			lem_in->link_arr[j][room->num] = 0;
			lem_in->link_arr[room->num][j] = 0;
			room->num_output -= 1;
			lem_in->rooms[j]->num_input -= 1;
		}
		j++;
	}
}

int		delete_output_forks(t_lem_in *lem_in)
{
	int		best_room;
	t_queue	*queue;
	t_room	*room;

	queue = new_queue_node(lem_in->rooms[lem_in->room_num - 1]);
	while (queue)
	{
		if (!(room = add_allprev_to_queue(lem_in, &queue)))
			return (ERROR);
		if (room->num_output > 1)
		{
			best_room = find_best_room(lem_in, room, 0);
			delete_extra(lem_in, room, best_room);
		}
	}
	return (0);
}
