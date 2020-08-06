#include "../includes/lem-in.h"

void	sort_paths(t_path **paths, int left, int right)
{
	int		i;
	int		j;
    int num;
	t_path	*temp;

    num = right + 1;
	i = 0;
	while (i < num - 1)
	{
		j = i + 1;
		while (j < num)
		{
			if (paths[i]->len > paths[j]->len)
			{
				temp = paths[i];
				paths[i] = paths[j];
				paths[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	define_comp_num(t_path **paths, int num)
{
	int i;
	int j;

	i = 0;
	while (i < num)
	{
		paths[i]->comp = 0;
		j = 0;
		while (j < i)
		{
			paths[i]->comp += paths[i]->len - paths[j]->len;
			j++;
		}
		i++;
	}
}
