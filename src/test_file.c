#include "../includes/lem-in.h"

void print_all(t_lem_in *lem_in)
{
	t_room *room;

	int i;
	ft_printf("NUMBER OF ANTS: %d\n", lem_in->ant_num);
	print_rooms(lem_in->rooms, lem_in->room_num);
	print_links(lem_in->link_arr, lem_in->room_num, lem_in->rooms);
//	print_link_arr(lem_in->link_arr, lem_in->room_num);
	lem_in->rooms[0]->level = 0;
	lem_in->rooms[lem_in->room_num - 1]->level = MAX_INT;


	bfs(lem_in);

	i = 0;
	delete_useless(lem_in);
	count_input_output(lem_in);
	print_rooms(lem_in->rooms, lem_in->room_num);
	delete_dead_ends(lem_in);
	delete_input_forks(lem_in);
	define_next(lem_in);
	delete_output_forks(lem_in);
	print_rooms(lem_in->rooms, lem_in->room_num);
	print_links(lem_in->link_arr, lem_in->room_num, lem_in->rooms);
	delete_dead_ends(lem_in);
	i = form_paths(lem_in);

	sort_paths(lem_in->paths, lem_in->path_num);
	define_comp_num(lem_in->paths, lem_in->path_num);
	print_paths(lem_in);
//	room = find_last_room(lem_in->paths[1]->head);
//	ft_printf("%s\n", room->name);
	move_ants(lem_in);
}
