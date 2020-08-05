/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:18:48 by eshor             #+#    #+#             */
/*   Updated: 2020/08/05 16:24:28 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

void	count_move_all_in_path(t_lem_in *l_i, t_room *room, int *is_start)
{
	t_room *temp;

	temp = room;
	if (temp->level == MAX_INT)
		return ;
	if (temp->next->level == MAX_INT && temp->ant_name != -1)
	{
		l_i->ant_end++;
		// print_space(is_start);
		// ft_printf("L%d-%s", temp->ant_name, temp->next->name);
		if (l_i->ant_end == l_i->ant_num)
			return ;
	}
	while (temp->prev)
	{
		temp->ant_name = temp->prev->ant_name;
		if (temp->ant_name != -1)
		{
			// print_space(is_start);
			// ft_printf("L%d-%s", temp->ant_name, temp->name);
		}
		temp->prev->ant_name = -1;
		temp = temp->prev;
	}
}

void	count_move_from_start(t_lem_in *l_i, int i, int *is_start)
{
	l_i->paths[i]->head->ant_name = l_i->ant_num - l_i->ant_start + 1;
	l_i->ant_start--;
	// print_space(is_start);
	// ft_printf("L%d-%s", l_i->paths[i]->head->ant_name,
			l_i->paths[i]->head->name);
	if (l_i->paths[i]->head->level == MAX_INT)
		l_i->ant_end++;
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
				break ;
			tail = find_last_room(l_i->paths[i]->head);
			move_all_in_path(l_i, tail, &is_start);
			if (l_i->ant_start > l_i->paths[i]->comp)
				move_from_start(l_i, i, &is_start);
			i++;
		}
//		ft_printf("ANTS IN END: %d\n", l_i->ant_end);
        count++;
		ft_printf("\n");
	}
    return (count);
}