#include "../includes/lem-in.h"


int is_room_in_path(t_lem_in *lem_in, int room_id)
{
	int i;
	int from;
	int to;

	i = 0;
	to = 0;
	from = 0;
	while (i < lem_in->room_num)
	{
		if (lem_in->link_arr[i][room_id] == 1 && lem_in->link_arr[room_id][i] == 2)
			from = 1;
		if (lem_in->link_arr[i][room_id] == 2 && lem_in->link_arr[room_id][i] == 1)
			to = 1;
		i++;
	}
	if (from == 1 && to == 1)
		return (1);
	return (0);
}

