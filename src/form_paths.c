#include "../includes/lem-in.h"

void 	sort_paths(t_path **paths, int num)
{
	int i;
	int j;
	t_path *temp;

	i = 0;
	while (i < num - 1)
	{
		j = i + 1;
		while (j < num)
		{
			if (paths[i]->len > paths[j]->len)
			{
				temp = paths[i];
				paths[i] = paths[j];
				paths[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void 	define_comp_num(t_path **paths, int num)
{
	int i;
	int j;

	i = 0;
	while (i < num)
	{
		paths[i]->comp = 0;
		j = 0;
		while (j < i)
		{
			paths[i]->comp += paths[i]->len - paths[j]->len;
			j++;
		}
		i++;
	}
}

int does_path_end(t_room *head)
{
	t_room *temp;
	t_room *prev;

	temp = head;
	prev = NULL;
	while (temp->next)
	{
		temp->prev = prev;
		prev = temp;
		temp = temp->next;
	}
	if (temp->level == MAX_INT)
		return (1);
	else
	{
		ft_printf("path can't reach the end\n");
		return(ERROR);
	}

}

int 	form_paths(t_lem_in *lem_in)
{
	int i;
	int path_counter;
	int len;
	t_room *temp;

	i =  1;
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
	lem_in->paths = (t_path**)malloc(sizeof(t_path*) * lem_in->path_num);
	if (!lem_in->paths)
		return (-1);
	path_counter = 0;
	i = 1;
	while (i < lem_in->room_num)
	{
		if (lem_in->link_arr[0][i] == 1)
		{
			len = 0;
			lem_in->paths[path_counter] = (t_path*)malloc(sizeof(t_path));
			if (!lem_in->paths[path_counter])
				return (-1);
			lem_in->paths[path_counter]->head = lem_in->rooms[i];
			temp = lem_in->rooms[i];
			while (temp)
			{
				len++;
				temp = temp->next;
			}
			lem_in->paths[path_counter]->len = len;
			path_counter++;
		}
		i++;
	}
	return(0);
}
