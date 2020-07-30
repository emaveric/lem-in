#include "../includes/lem-in.h"

void free_rooms(t_room **rooms,  int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		free(rooms[i]->name);
		free(rooms[i]);
		i++;
	}
	free(rooms);
}

void free_paths(t_path **paths, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void free_all(t_lem_in *lem_in)
{
	int i;

	i = 0;
	while (i < (lem_in)->room_num)
	{
		free((lem_in)->link_arr[i]);
		i++;
	}
	free((lem_in)->link_arr);
	(lem_in)->link_arr = NULL;
	free_rooms((lem_in)->rooms, (lem_in)->room_num);
	free_paths((lem_in)->paths, (lem_in)->path_num);
	free(lem_in);
	//free line
}