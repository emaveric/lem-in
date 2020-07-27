#include "../includes/lem-in.h"

t_queue *new_queue_node(t_room *room)
{
    t_queue *node;

    node = (t_queue*)malloc(sizeof(t_queue));
    if (!node)
        return NULL;
    node->room = room;
    node->next = NULL;
    return (node);
}

void    push_node(t_queue **queue, t_queue *node)
{
	t_queue *temp;

	if (!*queue)
		*queue = node;
	else
	{
		temp = *queue;
		while (temp->next)
			temp = temp->next;
		temp->next = node;
	}
}

t_room *pop_node(t_queue **queue)
{
    t_room *room;
    t_queue *to_free;

    if (!*queue)
        return (NULL);
    else
    {
        room = (*queue)->room;
        to_free = *queue;
        *queue = (*queue)->next;
        free(to_free);
        return (room);
    }
}

void    free_queue(t_queue **queue)
{
    t_queue *to_free;

    while (*queue)
    {
        to_free = *queue;
        *queue = (*queue)->next;
        pop_node(&to_free);
    }
    *queue = NULL;
}

