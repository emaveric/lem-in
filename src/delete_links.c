#include "../includes/lem-in.h"

void 	delete_useless(t_lem_in *lem_in)
{
	int i;
	int j;

	i = 0;
	while (i < lem_in->room_num)
	{
		j = 0;
		while (j < lem_in->room_num)
		{
			if (i < j)
			{
				if ( lem_in->link_arr[i][j] == 1 && (lem_in->rooms[i]->level == -1
				|| lem_in->rooms[j]->level == -1
				|| lem_in->rooms[i]->level == lem_in->rooms[j]->level))
				{
					lem_in->link_arr[i][j] = 0;
					lem_in->link_arr[j][i] = 0;
					ft_printf("useless link room%d--room%d deleted\n", i, j);
				}
			}
			j++;
		}
		i++;
	}
}

void 	delete_dead_ends(t_lem_in *lem_in)
{
	int i;
	int j;

	i = 0;
	while (i < lem_in->room_num)
	{
		if ((lem_in->rooms[i]->num_output == 0 && lem_in->rooms[i]->num_input != 0 && i != lem_in->room_num - 1)
		|| (lem_in->rooms[i]->num_output != 0 && lem_in->rooms[i]->num_input == 0 && i != 0))
		{
			j = 0;
			while (j < lem_in->room_num)
			{
				if (lem_in->link_arr[i][j] == 1)
				{
					lem_in->link_arr[i][j] = 0;
					lem_in->link_arr[j][i] = 0;
					if (lem_in->rooms[j]->level > lem_in->rooms[i]->level)
						lem_in->rooms[j]->num_input -= 1;
					else
						lem_in->rooms[j]->num_output -= 1;
					ft_printf("useless link room%d--room%d deleted\n", i, j);
				}
				j++;
			}
		}
		i++;
	}
}

/*
 * 1 - there are output forks
 * 0 - there are no output forks
 */
int has_output_forks(t_lem_in *lem_in, int room_id)
{
	int i;
	int res;

	i = 0;
	res = 0;
	if (room_id == 0)
		return (0);
	if (lem_in->rooms[room_id]->num_output > 1)
		return (1);
	else
	{
		while (i < lem_in->room_num)
		{
			if (lem_in->link_arr[room_id][i] == 1 && lem_in->rooms[i]->level < lem_in->rooms[room_id]->level)
				return (has_output_forks(lem_in, i));
			i++;
		}
	}
}

/*
 * iterate over all rooms except start and end
 */
void delete_input_forks(t_lem_in *lem_in)
{
	int j;
	int best_room_id;
	int last_of_worst;
	t_queue *queue;
	t_queue *node;
	t_room *room;


	queue = new_queue_node(lem_in->rooms[0]);

	while (queue)
	{
		room = pop_node(&queue);
		j = 1;
//		add rooms to queue
		while(j < lem_in->room_num)
		{
			if (lem_in->link_arr[room->num][j] == 1 && lem_in->rooms[room->num]->level < lem_in->rooms[j]->level
			&& lem_in->rooms[j]->visited != 2 && j != lem_in->room_num-1)
			{
				node = new_queue_node(lem_in->rooms[j]);
				node->room->visited = 2;
				push_node(&queue, node);
			}
			j++;
		}
		if (room->num_input > 1)
		{
			j = 0;
			best_room_id = -1;
			while (j < lem_in->room_num)
			{
				if (lem_in->link_arr[room->num][j] == 1 && lem_in->rooms[j]->level < room->level)
				{
					last_of_worst = j;
					if (has_output_forks(lem_in, j) == 0)
						best_room_id = j;
				}
				j++;
			}
			if (best_room_id == -1)
				best_room_id = last_of_worst;
			j = 0;
			ft_printf("current room: %d\n", room->num);
			while (j < lem_in->room_num)
			{
				if (lem_in->link_arr[room->num][j] == 1 && lem_in->rooms[j]->level < room->level
				&& j != best_room_id)
				{
					lem_in->link_arr[room->num][j] = 0;
					lem_in->link_arr[j][room->num] = 0;
					room->num_input--;
					lem_in->rooms[j]->num_output--;
					ft_printf("useless link room%d--room%d deleted\n", room->num, j);
				}
				j++;
			}
		}
	}
}

/*
 * returns the length of the shortest path from room_id to end
 * and
 */
int find_shortest(t_lem_in *lem_in, int room_id)
{
	int i;
	int best_path;
	int best_room;
	int curr_path;

	i = 1;
	best_path = MAX_INT;
	best_room = -1;
	if (lem_in->link_arr[room_id][lem_in->room_num - 1] == 1)
		return(1);
	while (i < lem_in->room_num - 1)
	{
		if (lem_in->link_arr[room_id][i] == 1 && lem_in->rooms[i]->level > lem_in->rooms[room_id]->level)
		{
			curr_path = find_shortest(lem_in, i);
		}
		i++;
	}
}

void delete_output_forks(t_lem_in *lem_in)
{
	int i;
	int j;
	int best_path;
	int best_room;
	int curr_path;
	t_queue *queue;
	t_queue *node;
	t_room *room;


	queue = new_queue_node(lem_in->rooms[lem_in->room_num - 1]);
	while (queue) {
		room = pop_node(&queue);
		j = 1;
//		add rooms to queue
		while (j < lem_in->room_num) {
			if (lem_in->link_arr[room->num][j] == 1 && lem_in->rooms[room->num]->level > lem_in->rooms[j]->level
				&& lem_in->rooms[j]->visited != 3 && j != 0) {

				node = new_queue_node(lem_in->rooms[j]);
				node->room->visited = 3;
				push_node(&queue, node);
				ft_printf("room added to queue: %d\n", node->room->num);
			}
			j++;
		}
	}
}

