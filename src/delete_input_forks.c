#include "../includes/lem-in.h"

int		has_output_forks(t_lem_in *lem_in, int room_id)
{
	int i;

	i = 0;
	if (room_id == 0)
		return (0);
	if (lem_in->rooms[room_id]->num_output > 1)
		return (1);
	else
	{
		while (i < lem_in->room_num)
		{
			if (lem_in->link_arr[room_id][i] == 1 &&
			lem_in->rooms[i]->level < lem_in->rooms[room_id]->level)
				return (has_output_forks(lem_in, i));
			i++;
		}
	}
	return (0);
}

t_room	*add_allnext_to_queue(t_lem_in *lem_in, t_queue **queue)
{
	t_room	*room;
	int		j;
	t_queue	*node;

	room = pop_node(queue);
	j = 1;
	while (j < lem_in->room_num)
	{
		if (lem_in->link_arr[room->num][j] == 1 &&
		lem_in->rooms[room->num]->level < lem_in->rooms[j]->level
		&& lem_in->rooms[j]->visited != 2 && j != lem_in->room_num - 1)
		{
			if (!(node = new_queue_node(lem_in->rooms[j])))
				return (NULL);
			node->room->visited = 2;
			push_node(queue, node);
		}
		j++;
	}
	return (room);
}

void	delete_extra_links(t_lem_in *lem_in, int best_room_id, t_room *room)
{
	int j;

	j = 0;
	while (j < lem_in->room_num)
	{
		if (lem_in->link_arr[room->num][j] == 1 && lem_in->rooms[j]->level
		< room->level && j != best_room_id)
		{
			lem_in->link_arr[room->num][j] = 0;
			lem_in->link_arr[j][room->num] = 0;
			room->num_input--;
			lem_in->rooms[j]->num_output--;
		}
		j++;
	}
}

void	find_best(t_lem_in *lem_in, int *best, int *last_of_worst, t_room *room)
{
	int j;

	j = 0;
	while (j < lem_in->room_num)
	{
		if (lem_in->link_arr[room->num][j] == 1 &&
			lem_in->rooms[j]->level < room->level)
		{
			*last_of_worst = j;
			if (has_output_forks(lem_in, j) == 0)
				*best = j;
		}
		j++;
	}
}

/*
** iterate over all rooms except start and end
*/
int		delete_input_forks(t_lem_in *lem_in)
{
	int		best_room_id;
	int		last_of_worst;
	t_queue	*queue;
	t_room	*room;

	if (!(queue = new_queue_node(lem_in->rooms[0])))
		return (ERROR);
	while (queue)
	{
		if (!(room = add_allnext_to_queue(lem_in, &queue)))
			return (ERROR);
		if (room->num_input > 1 && room->level != MAX_INT)
		{
			best_room_id = -1;
			last_of_worst = -1;
			find_best(lem_in, &best_room_id, &last_of_worst, room);
			best_room_id = (best_room_id == -1) ? last_of_worst : best_room_id;
			delete_extra_links(lem_in, best_room_id, room);
		}
	}
	return (0);
}
