#include "../includes/lem-in.h"

void 	define_next(t_lem_in *lem_in)
{
	int i;
	int j;

	i = 1;
	while (i < lem_in->room_num - 1)
	{
		if (lem_in->rooms[i]->num_output == 1)
		{
			j = 1;
			ft_printf("room%s has 1 output\n", lem_in->rooms[i]->name);
			while (j < lem_in->room_num)
			{
				if (lem_in->link_arr[i][j] == 1 && lem_in->rooms[i]->level < lem_in->rooms[j]->level)
				{
					ft_printf("this is where it goes: room%s\n", lem_in->rooms[j]->name);
					lem_in->rooms[i]->next = lem_in->rooms[j];
					if (lem_in->rooms[j]->level != MAX_INT)
						lem_in->rooms[j]->prev = lem_in->rooms[i];
				}
				j++;
			}

		}
		i++;
	}
}