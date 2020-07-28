#include "../includes/lem-in.h"

void	delete_useless(t_lem_in *lem_in)
{
	int i;
	int j;

	i = 0;
	while (i < lem_in->room_num)
	{
		j = 0;
		while (j < lem_in->room_num)
		{
			if (i < j)
			{
				if (lem_in->link_arr[i][j] == 1 && (lem_in->rooms[i]->level
				== -1 || lem_in->rooms[j]->level == -1
				|| lem_in->rooms[i]->level == lem_in->rooms[j]->level))
				{
					lem_in->link_arr[i][j] = 0;
					lem_in->link_arr[j][i] = 0;
				}
			}
			j++;
		}
		i++;
	}
}

void	delete_dead_ends(t_lem_in *lem_in)
{
	int i;
	int j;

	i = 1;
	while (i < lem_in->room_num)
	{
		if ((lem_in->rooms[i]->num_output == 0 && lem_in->rooms[i]->num_input
		!= 0 && i != lem_in->room_num - 1) || (lem_in->rooms[i]->num_output
		!= 0 && lem_in->rooms[i]->num_input == 0))
		{
			j = 0;
			while (j < lem_in->room_num)
			{
				if (lem_in->link_arr[i][j] == 1)
				{
					lem_in->link_arr[i][j] = 0;
					lem_in->link_arr[j][i] = 0;
				}
				j++;
			}
		}
		i++;
	}
}
