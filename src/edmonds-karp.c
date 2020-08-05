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
		rooms[i]->level = -1;
		rooms[i]->temp_prev = NULL;
		i++;
	}
	rooms[num - 1]->visited = 0;
}

void	find_path_backwards(t_lem_in *lem_in, int room_id, int flag)
{
	int prev;

	while (room_id != 0)
	{
//		if (flag == 1)
//			ft_printf("now room %s\n", lem_in->rooms[room_id]->name);
		prev = lem_in->rooms[room_id]->temp_prev->num;
//		if (prev == 0)
//			ft_printf("start\n");
//		 ft_printf("prev room %s\n", lem_in->rooms[prev]->name);
		if (lem_in->link_arr[prev][room_id] == 3)
		{
			lem_in->link_arr[prev][room_id] = 1;
			lem_in->link_arr[room_id][prev] = 2;
		}
		else if (lem_in->link_arr[prev][room_id] == 2)
		{
			lem_in->link_arr[prev][room_id] = 4;
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

void    set_true_prev(t_lem_in *lem_in)
{
    int i;

    i = 0;
    // ft_printf("SET TRUE PREV\n");
    while (i < lem_in->room_num)
    {
        lem_in->rooms[i]->prev = lem_in->rooms[i]->temp_prev;
        lem_in->rooms[i]->next = lem_in->rooms[i]->temp_next;
        i++;
    }
}

int	edmonds_karp(t_lem_in *lem_in)
{
	t_queue *q;
	t_room *room;
	t_queue *new;
	int i;
    int n_turns;
    int n_new;
    t_path **paths;
    int num;

    n_turns = MAX_INT;
	while (1)
	{
		refresh_visited_and_lvl(lem_in->rooms, lem_in->room_num);
		q = new_queue_node(lem_in->rooms[0]);
		lem_in->rooms[0]->visited = 1;
		while (q)
		{
			room = pop_node(&q);
			i = 0;
			while (i < lem_in->room_num)
			{
				if (i == lem_in->room_num - 1 && lem_in->link_arr[room->num][i] == 3)
				{
					lem_in->link_arr[room->num][i] = 1;
					lem_in->link_arr[i][room->num] = 2;
					lem_in->rooms[i]->visited = 1;
                    find_path_backwards(lem_in, room->num, 0);
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
					new->room->temp_prev = room;
					new->room->visited = 1;
					new->room->level = find_level(lem_in, room->num, new->room->num);
					push_node(&q, new);
				}
				i++;
			}
		}
        if ((lem_in->paths = pathfinder(lem_in, &num)) == NULL)
        {
            // ft_printf("error in pathfinder\n");
            return (ERROR);
        }
        
		n_new = count_turns(lem_in);
        // ft_printf("old: %d\n new: %d\n", n_turns, n_new);
        if (n_new < n_turns)
        {
            paths = lem_in->paths;
            lem_in->paths = NULL;
            num = lem_in->path_num;
            lem_in->path_num = 0;
            n_turns = n_new;
            set_true_prev(lem_in);
        }
        else
            break;
        
	}
    // ft_printf("reassigning paths\n");
    lem_in->paths = paths;
    
    lem_in->path_num = num;
    // sort_paths(lem_in->paths, lem_in->path_num);
    // define_comp_num(lem_in->paths, lem_in->path_num);
	return (0);
}