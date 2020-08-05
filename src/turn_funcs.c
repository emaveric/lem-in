/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:18:48 by eshor             #+#    #+#             */
/*   Updated: 2020/08/05 21:40:47 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	count_move_all_in_path(t_lem_in *l_i, t_room *room, int *is_start, int even)
{
	t_room *temp;
    t_room *temp2;
    int k;

    k = 0;
	temp = room;
	if (temp->level == MAX_INT)
		return ;
	if (temp->temp_next->level == MAX_INT && temp->ant_name != -1)
	{
		l_i->ant_end++;
		if (l_i->ant_end == l_i->ant_num)
			return ;
	}
	while (temp->temp_prev)
	{
		temp->ant_name = temp->temp_prev->ant_name;
		// if (temp->ant_name != -1 && k % 2 == 1)
		// {
        //     if (even == 1)
        //     {
        //         ft_printf(" in path ");
        //     }
		// }
        k++;
		temp->temp_prev->ant_name = -1;
		temp = temp->temp_prev;
	}
}

void	count_move_from_start(t_lem_in *l_i, int i, int *is_start)
{
	l_i->paths[i]->head->ant_name = l_i->ant_num - l_i->ant_start + 1;
	l_i->ant_start--;
	// print_space(is_start);
	// ft_printf("L%d-%s", l_i->paths[i]->head->ant_name,
			// l_i->paths[i]->head->name);
	if (l_i->paths[i]->head->level == MAX_INT)
		l_i->ant_end++;
}

void    no_ants(t_lem_in *lem_in)
{
    int i;

    i = 0;
    while (i < lem_in->room_num)
    {
        lem_in->rooms[i]->ant_name = -1;
        i++;
    }   
}

t_room	*count_find_last_room(t_room *head)
{
	t_room *temp;

	temp = head;
	if (!temp->temp_next)
		return (temp);
	if (!temp->temp_next->temp_next)
		return (temp);
	while (temp->temp_next->temp_next)
		temp = temp->temp_next;
	return (temp);
}

int	count_turns(t_lem_in *l_i)
{
	int		i;
	int		is_start;
	t_room	*tail;
    int count;

    count = 0;
	while (l_i->ant_end != l_i->ant_num)
	{
		i = 0;
		is_start = 1;
		while (i < l_i->path_num)
		{
			if (l_i->ant_end == l_i->ant_num)
            {
                count++;
				break ;
            }
			tail = count_find_last_room(l_i->paths[i]->head);
            count_move_all_in_path(l_i, tail, &is_start, 0);
			count_move_all_in_path(l_i, tail, &is_start, 1);
			if (l_i->ant_start > l_i->paths[i]->comp)
				count_move_from_start(l_i, i, &is_start);
			i++;
		}
//		ft_printf("ANTS IN END: %d\n", l_i->ant_end);
        count++;
		// ft_printf("\n");
	}
    l_i->ant_start = l_i->ant_end;
    l_i->ant_end = 0;
    no_ants(l_i);
    return (count);
}