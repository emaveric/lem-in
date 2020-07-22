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
