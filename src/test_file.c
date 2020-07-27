#include "../includes/lem-in.h"

void print_all(t_lem_in *lem_in)
{
	t_room *room;

	int i;
	ft_printf("NUMBER OF ANTS: %d\n", lem_in->ant_num);
//	print_rooms(lem_in->rooms, lem_in->room_num);
//	print_links(lem_in->link_arr, lem_in->room_num, lem_in->rooms);
//	print_link_arr(lem_in->link_arr, lem_in->room_num);
	lem_in->rooms[0]->level = 0;
	lem_in->rooms[lem_in->room_num - 1]->level = MAX_INT;


	bfs(lem_in);

	i = 0;
	delete_useless(lem_in);
	count_input_output(lem_in);
//	print_rooms(lem_in->rooms, lem_in->room_num);
	delete_dead_ends(lem_in);
	ft_printf("dead end deleted\n");
	delete_input_forks(lem_in);
	ft_printf("input forks deleted\n");
	define_next(lem_in);
//	print_rooms(lem_in->rooms, lem_in->room_num);
	delete_output_forks(lem_in);
	ft_printf("output forks deleted\n");
//	print_rooms(lem_in->rooms, lem_in->room_num);
//	print_links(lem_in->link_arr, lem_in->room_num, lem_in->rooms);
	form_paths(lem_in);
//	print_links(lem_in->link_arr, lem_in->room_num, lem_in->rooms);
	if (lem_in->path_num == 0)
	{
		ft_printf("can't reach end from start\n");
		return ;
	}
	sort_paths(lem_in->paths, lem_in->path_num);
	define_comp_num(lem_in->paths, lem_in->path_num);
	ft_printf("num paths: %d\n", lem_in->path_num);
	print_paths(lem_in);

//	room = find_last_room(lem_in->paths[0]->head);
//	ft_printf("room %s\n", room->name);
//	ft_printf("%s\n", room->name);
	move_ants(lem_in);

//	print_rooms(lem_in->rooms, lem_in->room_num);
}
