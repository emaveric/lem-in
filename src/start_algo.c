#include "../includes/lem-in.h"

int start_algo(t_lem_in *lem_in)
{
	t_path *temp;
	int k;
	lem_in->rooms[0]->level = 0;
	lem_in->rooms[lem_in->room_num - 1]->level = MAX_INT;

	// if (bfs(lem_in) == ERROR)
	// 	return (ERROR);
	// delete_useless(lem_in);
	// count_input_output(lem_in);
	// delete_dead_ends(lem_in);
	if (edmonds_karp(lem_in) == ERROR)
		return (ERROR);
	// print_rooms(lem_in->rooms, lem_in->room_num);
	lem_in->flag = 3;
	dfs(lem_in, 0, 0);
//	print_link_arr(lem_in->link_arr, lem_in->room_num);
	if (pathfinder(lem_in) == ERROR)
		return (ERROR);
	// temp = lem_in->paths;
	// print_link_arr(lem_in->link_arr, lem_in->room_num);
	sort_paths(lem_in->paths, lem_in->path_num);
	define_comp_num(lem_in->paths, lem_in->path_num);
	
	// print_paths(lem_in);
    // ft_printf("path num: %d\n", lem_in->path_num);
	// ft_printf("paths printed\n");
//	if (form_paths(lem_in) == ERROR)
//		return (ERROR);
	if (lem_in->path_num == 0)
		return (ERROR);
	move_ants(lem_in);
	return (0);
}
