#include "../includes/lem-in.h"


t_room *get_prev_room(t_lem_in *lem_in, t_room *room)
{
	int i;
	t_room *new_head;
	int check;

	i = 0;
	check = -1;
	while (i < lem_in->room_num - 1)
	{
		if (lem_in->link_arr[room->num][i] == 3 && room->level > lem_in->rooms[i]->level)
		{
//			ft_printf("prev room: %s\n", lem_in->rooms[i]->name);
			check = 1;
			new_head = lem_in->rooms[i];
			new_head->next = room;
			lem_in->link_arr[new_head->num][room->num] = 1;
			lem_in->link_arr[room->num][new_head->num] = 2;
		}
		i++;
	}
	if (check == -1)
		return (NULL);
	return (new_head);
}


t_path *create_path(t_room *head, int len)
{
	t_path *path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	path->head = head;
	path->len = len;
	path->comp = 0;
	return (path);
}

int 	does_path_end(t_lem_in *lem_in, int room_id)
{
	int i;
	int len;

	len = 0;
	while (1)
	{
		i = 1;
		while (i < lem_in->room_num)
		{
			if (lem_in->link_arr[room_id][i] == 1)
			{
				len++;
				if (i == lem_in->room_num - 1)
					return (len + 1);
				room_id = i;
				break ;
			}
			i++;
		}
		if (i == lem_in->room_num)
			return (ERROR);
	}
}

void set_next_prev(t_lem_in *lem_in, int room_id)
{
	int i;

	lem_in->rooms[room_id]->prev = NULL;
	while (room_id != lem_in->room_num - 1)
	{
		i = 1;
		while (i < lem_in->room_num)
		{
			if (lem_in->link_arr[room_id][i] == 1)
			{
				lem_in->rooms[room_id]->next = lem_in->rooms[i];
				if (i != lem_in->room_num - 1)
					lem_in->rooms[i]->prev = lem_in->rooms[room_id];
				room_id = i;
				break;
			}
			i++;
		}
	}
}

int	get_num_paths(t_lem_in *lem_in)
{
	int num;
	int i;

	num = 0;
	i = 0;
	while (i < lem_in->room_num)
	{
		if (lem_in->link_arr[0][i] == 1 && (i == lem_in->room_num - 1 || does_path_end(lem_in, i) != ERROR))
			num++;
		i++;
	}
	return(num);
}

int pathfinder(t_lem_in *lem_in)
{
	int i;
	int len;
	t_path *one_path;

	lem_in->path_num = get_num_paths(lem_in);
	lem_in->paths = (t_path**)malloc(sizeof(t_path*) * lem_in->path_num);
	if (!lem_in->paths)
		return (ERROR);
	i = 1;
	lem_in->path_num = 0;
	while (i < lem_in->room_num)
	{
		if (lem_in->link_arr[0][i] == 1 && (len = does_path_end(lem_in, i)) != ERROR)
		{
			one_path = create_path(lem_in->rooms[i], len);
            // ft_printf("path created\n");
			if (!one_path)
				return (ERROR);
			set_next_prev(lem_in, i);
			lem_in->paths[lem_in->path_num] = one_path;
			lem_in->path_num++;
		}
		i++;
	}
	return (0);
}