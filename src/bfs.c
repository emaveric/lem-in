#include "../includes/lem-in.h"

int	bfs(t_lem_in *lem_in)
{
	t_queue		*queue;
	t_queue		*node;
	t_room		*room;
	int			i;

	queue = new_queue_node(lem_in->rooms[0]);
	if (!queue)
		return (ERROR);
	queue->room->visited = 1;
	while (queue)
	{
		i = 0;
		room = pop_node(&queue);
		lem_in->bfs_level = room->level + 1;
		while (i < lem_in->room_num)
		{
			if (lem_in->link_arr[room->num][i] == 3 && lem_in->rooms[i]->visited
			== 0 && lem_in->rooms[i]->level != MAX_INT)
			{
				if (!(node = new_queue_node(lem_in->rooms[i])))
				{
					free_queue(&queue);
					return (ERROR);
				}
				node->room->level = lem_in->bfs_level;
				node->room->visited = 1;
				push_node(&queue, node);
			}
			i++;
		}
	}
	lem_in->bfs_level--;
	return (0);
}
