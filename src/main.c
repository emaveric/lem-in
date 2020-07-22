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
    room0->visited = 0;
    room1->visited = 0;
    room2->visited = 0;
	room3->visited = 0;
	room4->visited = 0;
	room5->visited = 0;
	room6->visited = 0;
	room7->visited = 0;
    room0->num = 0;
    room1->num = 1;
    room2->num = 2;
	room3->num = 3;
	room4->num = 4;
	room5->num = 5;
	room6->num = 6;
	room7->num = 7;



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
    lem_in->start_room = room0;
    i = 0;
    print_links(lem_in->link_arr, lem_in->room_num);
    while (i < lem_in->room_num)
    {
        ft_printf("room level: %d\n", lem_in->rooms[i]->level);
        i++;
    }
    bfs(lem_in);
    i = 0;
	while (i < lem_in->room_num)
	{
		ft_printf("room%d level: %d\n", i, lem_in->rooms[i]->level);
		i++;
	}
	delete_useless(lem_in);
	print_links(lem_in->link_arr, lem_in->room_num);
}
