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
				== -1 || lem_in->rooms[j]->level == -1))
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

void 	delete_tail(t_lem_in *lem_in, int room)
{
	int i;

	i = 0;
	while (i < lem_in->room_num)
	{
		if (lem_in->link_arr[i][room] == 1)
		{
			lem_in->link_arr[i][room] = 0;
			lem_in->link_arr[room][i] = 0;
			lem_in->rooms[i]->num_output -=1;
			if ((lem_in->rooms[i]->num_output + lem_in->rooms[i]->num_input <= 1) && i != lem_in->room_num - 1 &&
			i != 0)
				delete_tail(lem_in, i);
			break ;
		}
		i++;
	}
}

void	delete_dead_ends(t_lem_in *lem_in)
{
	int i;
	int j;
	int room;

	i = 1;
	while (i < lem_in->room_num)
	{
		if ((lem_in->rooms[i]->num_output + lem_in->rooms[i]->num_input <= 1) && i != lem_in->room_num - 1 &&
			i != 0)
			delete_tail(lem_in, i);
		i++;
	}
}
