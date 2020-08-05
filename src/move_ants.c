#include "../includes/lem-in.h"

void	print_space(int *is_start)
{
	if (*is_start != 1)
		ft_printf(" ");
	else
		*is_start = -1;
}

void	move_all_in_path(t_lem_in *l_i, t_room *room, int *is_start, int even)
{
	t_room *temp;
    t_room *temp2;
    int k;

    k = 0;
	temp = room;
	if (temp->level == MAX_INT)
		return ;
	if (temp->next->level == MAX_INT && temp->ant_name != -1)
	{
		l_i->ant_end++;
        if (even == 1)
        {
            print_space(is_start);
		    ft_printf("L%d-%s", temp->ant_name, temp->next->name);
        }
		if (l_i->ant_end == l_i->ant_num)
			return ;
	}
	while (temp->prev)
	{
		temp->ant_name = temp->prev->ant_name;
		if (temp->ant_name != -1 && k % 2 == 1)
		{
            if (even == 1)
            {
                print_space(is_start);
                ft_printf("L%d-%s", temp->ant_name, temp->name);
            }
		}
        k++;
		temp->prev->ant_name = -1;
		temp = temp->prev;
	}
}

t_room	*find_last_room(t_room *head)
{
	t_room *temp;

	temp = head;
	if (!temp->next)
		return (temp);
	if (!temp->next->next)
		return (temp);
	while (temp->next->next)
		temp = temp->next;
	return (temp);
}

void	move_from_start(t_lem_in *l_i, int i, int *is_start)
{
	l_i->paths[i]->head->ant_name = l_i->ant_num - l_i->ant_start + 1;
	l_i->ant_start--;
	print_space(is_start);
	ft_printf("L%d-%s", l_i->paths[i]->head->ant_name,
			l_i->paths[i]->head->name);
	if (l_i->paths[i]->head->level == MAX_INT)
		l_i->ant_end++;
}

void	move_ants(t_lem_in *l_i)
{
	int		i;
	int		is_start;
	t_room	*tail;

	while (l_i->ant_end != l_i->ant_num)
	{
		i = 0;
		is_start = 1;
		while (i < l_i->path_num)
		{
            // ft_printf("\npath %d\n", i);
			if (l_i->ant_end == l_i->ant_num)
				break ;
			tail = find_last_room(l_i->paths[i]->head);
			move_all_in_path(l_i, tail, &is_start, 0);
            move_all_in_path(l_i, tail, &is_start, 1);
			if (l_i->ant_start > l_i->paths[i]->comp)
				move_from_start(l_i, i, &is_start);
			i++;
		}
//		ft_printf("ANTS IN END: %d\n", l_i->ant_end);
		ft_printf("\n");
	}
}