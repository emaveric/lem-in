#include "../includes/lem-in.h"

int start_algo(t_lem_in *lem_in)
{
	lem_in->rooms[0]->level = 0;
	lem_in->rooms[lem_in->room_num - 1]->level = MAX_INT;
	if (bfs(lem_in) == ERROR)
		return (ERROR);
	delete_useless(lem_in);
	count_input_output(lem_in);
	delete_dead_ends(lem_in);
	delete_input_forks(lem_in);
	define_next(lem_in);
	delete_output_forks(lem_in);
	if (form_paths(lem_in) == ERROR)
		return (ERROR);
	if (lem_in->path_num == 0)
		return (ERROR);
	sort_paths(lem_in->paths, lem_in->path_num);
	define_comp_num(lem_in->paths, lem_in->path_num);
	move_ants(lem_in);
	return (0);
}
