#include "../includes/lem-in.h"

int find_smallest_lvl_id(t_lem_in *lem_in, int *smallest_level)
{
	int i;
	int smallest_id;

	i = 0;
	smallest_id = -1;
	while (i < lem_in->room_num)
	{
		if (lem_in->link_arr[lem_in->room_num - 1][i] == 3 /*&& lem_in->rooms[i]->level != -1*/
			&& *smallest_level > lem_in->rooms[i]->level)
		{
			*smallest_level = lem_in->rooms[i]->level;
			smallest_id = i;
		}
		i++;
	}
	if (*smallest_level == MAX_INT)
		return (-1);
	return (smallest_id);
}

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

t_path *find_shortest(t_lem_in *lem_in)
{
	int smallest_level;
	int smallest_id;
	t_path *path;
	t_room *head;

	smallest_level = MAX_INT;
	smallest_id = find_smallest_lvl_id(lem_in, &smallest_level);
	if (smallest_id == -1)
		return (NULL);
	lem_in->rooms[smallest_id]->next = lem_in->rooms[lem_in->room_num - 1];
	head = lem_in->rooms[smallest_id];
	lem_in->link_arr[head->num][lem_in->room_num - 1] = 1;
	lem_in->link_arr[lem_in->room_num - 1][head->num] = 2;
	while (head->level != 1)
	{
		head = get_prev_room(lem_in, head);
		if (!head)
			return (NULL);
	}
	path = create_path(head, smallest_level + 1);
	lem_in->link_arr[head->num][0] = 2;
	lem_in->link_arr[0][head->num] = 1;

	return (path);
}

t_path *create_path(t_room *head, int len)
{
	t_path *path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	path->head = head;
	path->len = len;
	path->next = NULL;
	path->comp = 0;
	return (path);
}

void add_path(t_path **paths, t_path *new)
{
	if (!*paths)
		*paths = new;
	else
	{
		new->next = *paths;
		*paths = new;
	}
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
			return (-1);
	}
}

void set_next_prev(t_lem_in *lem_in, int room_id)
{
	int i;


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

int pathfinder(t_lem_in *lem_in)
{
	int i;
	int len;
	t_path *one_path;

	free_paths(&(lem_in->paths));
	lem_in->paths = NULL;
	i = 0;
	while (i < lem_in->room_num)
	{
		if (lem_in->link_arr[0][i] == 1 && (len = does_path_end(lem_in, i)) != ERROR)
		{
			one_path = create_path(lem_in->rooms[i], len);
			ft_printf("path created\n");
			if (!one_path)
				return (ERROR);
			set_next_prev(lem_in, i);
			add_path(&(lem_in->paths), one_path);
		}
		i++;
	}
	return (0);
}