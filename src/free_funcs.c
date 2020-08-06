#include "../includes/lem-in.h"

void    free_rooms(t_lem_in **lem_in)
{
    int i;

    i = 0;
    while (i < (*lem_in)->room_num)
    {
        free((*lem_in)->rooms[i]->name);
        free((*lem_in)->rooms[i]);
        i++;
    }
    if ((*lem_in)->rooms)
        free((*lem_in)->rooms);
}

void 	str_free(char **str, int i)
{
	while(str[i])
	{
		free(str[i]);
		i++;
	}
    if (str)
	    free(str);
}

void free_all(t_lem_in **lem_in)
{
	int i;

	i = 0;
    while (i < (*lem_in)->room_num)
    {
        free((*lem_in)->link_arr[i]);
        i++;
    }
    if ((*lem_in)->link_arr)
        free((*lem_in)->link_arr);
    free_rooms(lem_in);
    free_paths((*lem_in)->paths, (*lem_in)->path_num);
    str_free((*lem_in)->line, 0);
    free(*lem_in);
}

void free_paths(t_path **paths,  int num)
{
    int i;

    i = 0;
    while (i < num)
    {
        free(paths[i]);
        i++;
    }
    if (paths)
        free(paths);
    paths = NULL;
}