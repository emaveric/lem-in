#include "../includes/lem-in.h"

int start_algo(t_lem_in *lem_in)
{
	t_room *temp;
	lem_in->rooms[0]->level = 0;
	lem_in->rooms[lem_in->room_num - 1]->level = MAX_INT;

	if (bfs(lem_in) == ERROR)
		return (ERROR);
	print_rooms(lem_in->rooms, lem_in->room_num);
	print_links(lem_in->link_arr, lem_in->room_num, lem_in->rooms);
	delete_useless(lem_in);
	count_input_output(lem_in);
	delete_dead_ends(lem_in);
	print_rooms(lem_in->rooms, lem_in->room_num);
	print_links(lem_in->link_arr, lem_in->room_num, lem_in->rooms);
	ft_printf("%d\n", lem_in->bfs_level);
	lem_in->paths = find_shortest(lem_in);
	if (!lem_in->paths)
		return (ERROR);
	print_paths(lem_in);
	print_link_arr(lem_in->link_arr, lem_in->room_num);
//	delete_input_forks(lem_in);
//	define_next(lem_in);
//	delete_output_forks(lem_in);
//	if (form_paths(lem_in) == ERROR)
//		return (ERROR);
//	if (lem_in->path_num == 0)
//		return (ERROR);
//	sort_paths(lem_in->paths, lem_in->path_num);
//	define_comp_num(lem_in->paths, lem_in->path_num);
//	move_ants(lem_in);
	return (0);
}
