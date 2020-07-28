#include "../includes/lem-in.h"

/*
 * returns the length of the shortest path from room_id to end
 * and
 */
int		find_shortest(t_lem_in *lem_in, int room_id)
{
	int best_path;
	t_room *temp;

	best_path = 0;
	temp = lem_in->rooms[room_id];
	if (lem_in->rooms[room_id]->level == MAX_INT)
		return (0);
	while (temp->next)
	{
		best_path++;
		temp = temp->next;
	}
//	ft_printf("room %s\n", lem_in->rooms[room_id]->name);
//	ft_printf("best candidate %s, end path level: %d\n", temp->name, temp->level);
	if (temp->level != MAX_INT)
		return (MAX_INT);
//	ft_printf("best path: %d\n", best_path);
	return (best_path - 1);
}

void	delete_output_forks(t_lem_in *lem_in)
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
	best_path = MAX_INT;
	while (queue) {
		room = pop_node(&queue);
		j = 1;
//		add rooms to queue
//		ft_printf("current room: %s\n", room->name);
		while (j < lem_in->room_num)
		{
//			ft_printf("j: %d\n", j);
//			ft_printf("room->level: %d\n", room->level);
//			ft_printf("j->level: %d\n", lem_in->rooms[j]->level);
			if ((room->level == MAX_INT && lem_in->link_arr[room->num][j] == 1 && lem_in->rooms[j]->visited != 3
			/*&& lem_in->rooms[j]->level == lem_in->bfs_level*/) ||
			(room->level != MAX_INT && lem_in->rooms[j]->level == room->level - 1 && lem_in->rooms[j]->visited != 3 && j != 0
			&& lem_in->link_arr[room->num][j] == 1))
			{

				node = new_queue_node(lem_in->rooms[j]);
				node->room->visited = 3;
				push_node(&queue, node);
				ft_printf("room added to queue: %s\n", node->room->name);
			}
			j++;
		}
		if (room->num_output > 1)
		{
			best_path = MAX_INT;
//			ft_printf("output fork in room %s\n", room->name);
			j = 0;
//			ft_printf("room num: %d\n", lem_in->room_num);
			if (lem_in->link_arr[lem_in->room_num - 1][room->num] == 1)
				best_room = lem_in->room_num - 1;
			else
			{
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
			}

			j = 1;
//			ft_printf("curr room: %d\n", room->num);
//			ft_printf("best room: %s\n", lem_in->rooms[best_room]->name);
			room->next = lem_in->rooms[best_room];
			while (j < lem_in->room_num)
			{
				if (lem_in->link_arr[j][room->num] == 1 && room->level < lem_in->rooms[j]->level && j != best_room)
				{
					lem_in->link_arr[j][room->num] = 0;
					lem_in->link_arr[room->num][j] = 0;
					room->num_output -= 1;
					lem_in->rooms[j]->num_input -= 1;
				}
				j++;
			}
		}
	}
}
