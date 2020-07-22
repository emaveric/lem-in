#include "../includes/lem-in.h"

void print_links(int **arr,  int len)
{
	int i;
	int j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (arr[i][j] == 1 && i < j)
			{
					ft_printf("room%d -- room %d\n", i, j);
			}
			j++;
		}
		i++;
	}
}

void print_rooms(t_room **rooms, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_printf("room%d\n\tname: %s\n\tnum_input: %d\n\tnum_output: %d\n\tlevel: %d\n\n", i, rooms[i]->name,
				rooms[i]->num_input, rooms[i]->num_output, rooms[i]->level);
		i++;
	}
}
int 			level;
int             num;
int 			x;
int 			y;
int 			num_input;
int 			num_output;
int 			visited;
struct s_room	*next;
int 			ant_name;