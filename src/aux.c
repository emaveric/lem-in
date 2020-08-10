#include "../includes/lem_in.h"

void print_links(char **arr,  int len, t_room **rooms)
{
	int i;
	int j;

	ft_printf("PRINT LINKS\n");
	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if ((arr[i][j] == 3 || arr[i][j] == 2) && i < j)
			{
				ft_printf("room %s -- room %s\n", rooms[i]->name, rooms[j]->name);
			}
			j++;
		}
		i++;
	}
}

void print_rooms(t_room **rooms, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("room%d\n\tname: %s\n\tnum_input: %d\n\tnum_output: %d\n\tlevel: %d\n\tant_name: %d\n\tvisited: %d\n\n", i, rooms[i]->name,
				rooms[i]->num_input, rooms[i]->num_output, rooms[i]->level,  rooms[i]->ant_name, rooms[i]->visited);
		if (rooms[i]->next != NULL)
			ft_printf("next room: %d\n", rooms[i]->next->num);
		i++;
	}
}

void print_paths(t_lem_in *lem_in)
{
	int i;
	t_room *temp;

	i = 0;
	while (i < lem_in->path_num)
	{
		ft_printf("path %d, len %d, comp %d\n", i, lem_in->paths[i]->len, lem_in->paths[i]->comp);
		temp = lem_in->paths[i]->head;
		while (temp)
		{
			ft_printf("room%s\n", temp->name);
			temp = temp->next;
		}
		ft_printf("\n");
		i++;
	}
}

void print_link_arr(char **arr, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_printf("x\t");
	while (i < len)
	{
		ft_printf("%d\t", i);
		i++;
	}
	ft_printf("\n");
	i = 0;
	while (i < len)
	{
		ft_printf("%d\t", i);
		j = 0;
		while (j < len)
		{
			ft_printf("%d\t", arr[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void print_queue(t_queue *q)
{
	t_queue *temp;

	temp = q;
	ft_printf("print queue\n");
	while (temp)
	{
		ft_printf("%s\n", temp->room->name);
		temp = temp->next;
	}
}