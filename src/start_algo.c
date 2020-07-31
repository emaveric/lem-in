#include "../includes/lem-in.h"

int start_algo(t_lem_in *lem_in)
{
	t_path *temp;
	int k;
	lem_in->rooms[0]->level = 0;
	lem_in->rooms[lem_in->room_num - 1]->level = MAX_INT;

	if (bfs(lem_in) == ERROR)
		return (ERROR);
	delete_useless(lem_in);
	count_input_output(lem_in);
	delete_dead_ends(lem_in);
	lem_in->paths = find_shortest(lem_in);
	if (!lem_in->paths)
		return (ERROR);
	print_paths(lem_in);
	if (edmonds_karp(lem_in) == ERROR)
		return (ERROR);
//	print_link_arr(lem_in->link_arr, lem_in->room_num);
	if (pathfinder(lem_in) == ERROR)
		return (ERROR);
	temp = lem_in->paths;
	print_paths(lem_in);
//	if (form_paths(lem_in) == ERROR)
//		return (ERROR);
//	if (lem_in->path_num == 0)
//		return (ERROR);
//	move_ants(lem_in);
//	ft_printf("ld inputs filled? %d\n", are_end_inputs_filled(lem_in));
	return (0);
}
