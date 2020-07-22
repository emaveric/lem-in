#include "../includes/lem-in.h"

void 	delete_useless(t_lem_in *lem_in)
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
				if ( lem_in->link_arr[i][j] == 1 && (lem_in->rooms[i]->level == -1
				|| lem_in->rooms[j]->level == -1
				|| lem_in->rooms[i]->level == lem_in->rooms[j]->level))
				{
					lem_in->link_arr[i][j] = 0;
					lem_in->link_arr[j][i] = 0;
					ft_printf("useless link room%d--room%d deleted\n", i, j);
				}
			}
			j++;
		}
		i++;
	}
}

