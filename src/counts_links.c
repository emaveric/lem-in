#include "../includes/lem-in.h"

void 	count_input_output(t_lem_in *lem_in)
{
	int i;
	int j;

	i = 0;
	while (i < lem_in->room_num)
	{
		j = 0;
		while (j < lem_in->room_num)
		{
			if (i < j && lem_in->link_arr[i][j] == 1)
			{
//				ft_printf("link exists\n");
				if (lem_in->rooms[i]->level < lem_in->rooms[j]->level)
				{
					lem_in->rooms[i]->num_output += 1;
					lem_in->rooms[j]->num_input += 1;
				}
				else
				{
					lem_in->rooms[i]->num_input += 1;
					lem_in->rooms[j]->num_output += 1;
				}
			}
			j++;
		}
		i++;
	}
}