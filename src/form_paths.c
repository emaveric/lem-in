#include "../includes/lem-in.h"

int		does_path_end(t_room *head)
{
	t_room	*temp;
	t_room	*prev;

	temp = head;
	prev = NULL;
	while (temp->next)
	{
		temp->prev = prev;
		prev = temp;
		temp = temp->next;
	}
	ft_printf("\n");
	if (temp->level == MAX_INT)
		return (1);
	else
		return (ERROR);
}

void	get_path_num(t_lem_in *lem_in)
{
	int i;

	i = 1;
	while (i < lem_in->room_num)
	{
		if (lem_in->link_arr[0][i] == 1)
		{
			if (does_path_end(lem_in->rooms[i]) == 1)
				lem_in->path_num++;
			else
			{
				lem_in->link_arr[0][i] = 0;
				lem_in->link_arr[i][0] = 0;
			}
		}
		i++;
	}
}

int		form_one(t_lem_in *lem_in, int i, int path_counter)
{
	t_room	*temp;
	int		len;

	len = 0;
	lem_in->paths[path_counter] = (t_path*)malloc(sizeof(t_path));
	if (!lem_in->paths[path_counter])
		return (ERROR);
	lem_in->paths[path_counter]->head = lem_in->rooms[i];
	temp = lem_in->rooms[i];
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	lem_in->paths[path_counter]->len = len;
	return (0);
}

int		form_paths(t_lem_in *lem_in)
{
	int		i;
	int		path_counter;

	get_path_num(lem_in);
	lem_in->paths = (t_path**)malloc(sizeof(t_path*) * lem_in->path_num);
	if (!lem_in->paths)
		return (ERROR);
	path_counter = 0;
	i = 1;
	while (i < lem_in->room_num)
	{
		if (lem_in->link_arr[0][i] == 1)
		{
			form_one(lem_in, i, path_counter);
			path_counter++;
		}
		i++;
	}
	return (0);
}
