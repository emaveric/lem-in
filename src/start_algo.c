#include "../includes/lem-in.h"

void	flag_correction(t_lem_in *l_i)
{
	int 	i;

	i = 0;
	while (i < l_i->room_num)
	{
		l_i->rooms[i]->flag = 0;
		l_i->rooms[i]->label = 0;
		l_i->rooms[i]->prev = NULL;
		i++;
	}
}

void 	level_correction(t_lem_in *l_i, int flag, int k, int i)
{
	int 	j;

	flag_correction(l_i);
	while (k != 0)
	{
		k = 0;
		flag = 0;
		j = i;
		while (j < l_i->room_num - 1)
		{
			if (l_i->link_arr[k][j] == 1)
			{
				if (flag == 0)
				{
					i = j + 1;
					flag = 1;
				}
				l_i->rooms[j]->level = l_i->rooms[k]->level + 1;
				k = j;
				j = 1;
			}
			j++;
		}
	}
}

int start_algo(t_lem_in *lem_in)
{
	int i;

	t_path *temp;
	int k;
	lem_in->rooms[0]->level = 0;
	lem_in->rooms[lem_in->room_num - 1]->level = MAX_INT;
	if (edmonds_karp(lem_in) == ERROR)
	{
		return (ERROR);
	}
	if (lem_in->path_num == 0)
	{
		return (ERROR);
	}
	i = 0;
	move_ants(lem_in);
	return (0);
}
