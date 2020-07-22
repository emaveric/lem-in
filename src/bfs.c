#include "../includes/lem-in.h"
/*
 * returns -1 if could not allocate memory
 * 0 if OK
 */
int    bfs(t_lem_in *lem_in)
{
	t_queue *queue;
	t_queue *node;
	t_room *room;
	int i;
	int level;

	queue = new_queue_node(lem_in->start_room);
	if (!queue)
		return (-1);
	queue->room->visited = 1;
	while (queue)
	{
		i = 0;
		room = pop_node(&queue);
		level = room->level + 1;
		while (i < lem_in->room_num)
		{
			if (lem_in->link_arr[room->num][i] == 1 &&
			lem_in->rooms[i]->visited == 0 && lem_in->rooms[i]->level != MAX_INT)
			{
				if (!(node = new_queue_node(lem_in->rooms[i])))
				{
					free_queue(&queue);
					return (-1);
				}
				ft_printf("level changed\n");
				node->room->level = level;
				node->room->visited = 1;
				push_node(&queue, node);
			}
			i++;
		}
	}
}
