#include "../includes/lem-in.h"

int main()
{
    t_lem_in *lem_in;
    t_room *room0;
    t_room *room1;
    t_room *room2;
	t_room *room3;
	t_room *room4;
	t_room *room5;
	t_room *room6;
	t_room *room7;
	char *name;

    t_room *room_temp;
//    t_link *link1;
//    t_link *link2;
//	t_link *link3;
//	t_link *link4;
//	t_link *link5;
//	t_link *link6;
//	t_link *link7;
//	t_link *link8;
//	t_link *link9;
//	t_link *link10;
    int i;
    int j;
    t_queue *node1;
    t_queue *node2;
    t_queue *node3;
    t_queue *temp;

    lem_in = malloc(sizeof(t_lem_in));
    lem_in->ant_num = 20;
    lem_in->ant_start = 20;
    lem_in->ant_end = 0;
    room0 = malloc(sizeof(t_room));
    room0->level = 0;
    room1 = malloc(sizeof(t_room));
    room1->level = -1;
    room2 = malloc(sizeof(t_room));
    room2->level = -1;
	room3 = malloc(sizeof(t_room));
	room3->level = -1;
	room4 = malloc(sizeof(t_room));
	room4->level = -1;
	room5 = malloc(sizeof(t_room));
	room5->level = -1;
	room6 = malloc(sizeof(t_room));
	room6->level = -1;
	room7 = malloc(sizeof(t_room));
	room7->level = MAX_INT;


	name = (char*)malloc(sizeof(char) * 5);
	name[0] = 'n';
	name[1] = 'a';
	name[2] = 'm';
	name[3] = 'e';
	name[4] = '\0';
    lem_in->room_num = 8;
    lem_in->link_num = 10;
//    link1 = malloc(sizeof(t_link));
//    link2 = malloc(sizeof(t_link));
//    link1->start = room0;
//    link1->end = room1;
//    link2->start = room1;
//    link2->end = room2;
    lem_in->rooms = (t_room**)malloc(sizeof(t_room*) * lem_in->room_num);
    lem_in->rooms[0] = room0;
    lem_in->rooms[1] = room1;
    lem_in->rooms[2] = room2;
	lem_in->rooms[3] = room3;
	lem_in->rooms[4] = room4;
	lem_in->rooms[5] = room5;
	lem_in->rooms[6] = room6;
	lem_in->rooms[7] = room7;
	i = 0;
	while (i < lem_in->room_num)
	{
		lem_in->rooms[i]->visited = 0;
		lem_in->rooms[i]->num = i;
		lem_in->rooms[i]->num_input = 0;
		lem_in->rooms[i]->num_output = 0;
		lem_in->rooms[i]->name = name;
		lem_in->rooms[i]->ant_name = -1;
		lem_in->rooms[i]->next = NULL;
		lem_in->rooms[i]->prev =NULL;
		i++;
	}
    lem_in->links = (t_link**)malloc(sizeof(t_link*) * lem_in->link_num);
//    lem_in->links[0] = link1;
//    lem_in->links[1] = link2;
    lem_in->link_arr = (int**)malloc(sizeof(int*) * lem_in->room_num);
    i = 0;
    while (i < lem_in->room_num)
    {
        j = 0;
        lem_in->link_arr[i] = (int*)malloc(sizeof(int) * lem_in->room_num);
        while (j < lem_in->room_num)
        {
            lem_in->link_arr[i][j] = 0;
            j++;
        }
        i++;
    }
    lem_in->link_arr[0][1] = 1;
    lem_in->link_arr[1][0] = 1;
    lem_in->link_arr[2][1] = 1;
    lem_in->link_arr[1][2] = 1;
	lem_in->link_arr[0][2] = 1;
	lem_in->link_arr[2][0] = 1;
	lem_in->link_arr[1][3] = 1;
	lem_in->link_arr[3][1] = 1;
	lem_in->link_arr[1][4] = 1;
	lem_in->link_arr[4][1] = 1;
	lem_in->link_arr[2][5] = 1;
	lem_in->link_arr[5][2] = 1;
	lem_in->link_arr[2][7] = 1;
	lem_in->link_arr[7][2] = 1;
	lem_in->link_arr[4][7] = 1;
	lem_in->link_arr[7][4] = 1;
	lem_in->link_arr[5][7] = 1;
	lem_in->link_arr[7][5] = 1;
	lem_in->link_arr[7][6] = 1;
	lem_in->link_arr[6][7] = 1;
	lem_in->link_arr[2][4] = 1;
	lem_in->link_arr[4][2] = 1;
    lem_in->start_room = room0;
    lem_in->path_num = 0;
    i = 0;
    print_links(lem_in->link_arr, lem_in->room_num);
	print_rooms(lem_in->rooms, lem_in->room_num);
    bfs(lem_in);
    i = 0;
    ft_printf("level: %d\n", lem_in->bfs_level);
	delete_useless(lem_in);
	print_links(lem_in->link_arr, lem_in->room_num);
//	print_rooms(lem_in->rooms, lem_in->room_num);
	count_input_output(lem_in);
	print_rooms(lem_in->rooms, lem_in->room_num);
	delete_dead_ends(lem_in);
	print_rooms(lem_in->rooms, lem_in->room_num);
	print_links(lem_in->link_arr, lem_in->room_num);
	delete_input_forks(lem_in);
	define_next(lem_in);
	print_links(lem_in->link_arr, lem_in->room_num);
	print_rooms(lem_in->rooms, lem_in->room_num);
	delete_output_forks(lem_in);
	print_rooms(lem_in->rooms, lem_in->room_num);
//	ft_printf("shortest len: %d\n", find_shortest(lem_in, 5));
	i = form_paths(lem_in);
//	ft_printf("form paths returned %d\n", i);

	sort_paths(lem_in->paths, lem_in->path_num);
	define_comp_num(lem_in->paths, lem_in->path_num);
	print_paths(lem_in);

	lem_in->ant_num = 5;
	lem_in->ant_start = 5;
	lem_in->ant_end = 0;
//	lem_in->rooms[1]->ant_name = 2;
//	lem_in->rooms[4]->ant_name = 1;
//	move_all_in_path(lem_in, 5, lem_in->paths[1]->head);
	move_ants(lem_in);
}
