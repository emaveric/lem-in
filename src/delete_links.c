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
	return (0);
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
		if (room->num_input > 1 && room->level != MAX_INT)
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
					ft_printf("input fork room%d--room%d deleted\n", room->num, j);
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
	int best_path;
	t_room *temp;

	best_path = 0;
	temp = lem_in->rooms[room_id];
	if (lem_in->rooms[room_id]->level == MAX_INT)
		return (0);
	while (temp)
	{
		best_path++;
		temp = temp->next;
	}
	return (best_path - 1);
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
	curr_path = MAX_INT;
	while (queue) {
		room = pop_node(&queue);
		j = 1;
//		add rooms to queue
//		ft_printf("current room: %d\n", room->num);
		while (j < lem_in->room_num)
		{
//			ft_printf("j: %d\n", j);
//			ft_printf("room->level: %d\n", room->level);
//			ft_printf("j->level: %d\n", lem_in->rooms[j]->level);
			if ((room->level == MAX_INT && lem_in->link_arr[room->num][j] == 1 && lem_in->rooms[j]->visited != 3
			&& lem_in->rooms[j]->level == lem_in->bfs_level) ||
			(room->level != MAX_INT && lem_in->rooms[j]->level == room->level - 1 && lem_in->rooms[j]->visited != 3 && j != 0))
			{

				node = new_queue_node(lem_in->rooms[j]);
				node->room->visited = 3;
				push_node(&queue, node);
//				ft_printf("room added to queue: %d\n", node->room->num);
			}
			j++;
		}
		if (room->num_output > 1)
		{
			j = 0;
//			ft_printf("room num: %d\n", lem_in->room_num);
			while (j < lem_in->room_num)
			{
//				ft_printf("%d\n", j);
				if (lem_in->link_arr[j][room->num] == 1 && room->level < lem_in->rooms[j]->level)
				{
//					ft_printf("room%d\n", j);
					curr_path = find_shortest(lem_in, j);
					if (curr_path < best_path)
					{
						best_room = j;
						best_path = curr_path;
					}
				}

				j++;
			}
			j = 1;
//			ft_printf("curr room: %d\n", room->num);
//			ft_printf("best room: %d\n", best_room);
			room->next = lem_in->rooms[best_room];
			while (j < lem_in->room_num)
			{
				if (lem_in->link_arr[j][room->num] == 1 && room->level < lem_in->rooms[j]->level && j != best_room)
				{
					lem_in->link_arr[j][room->num] = 0;
					lem_in->link_arr[room->num][j] = 0;
					room->num_output -=1;
					lem_in->rooms[j]->num_input -= 1;
				}
				j++;
			}
		}


	}
}

