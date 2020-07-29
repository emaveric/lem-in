/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:47:49 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/29 13:32:09 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

t_queue		*init_queue(void)
{
	t_queue		*new;

	if (!(new = (t_queue *)malloc(sizeof(t_queue))))
		return (NULL);
	new->next = NULL;
	new->room = NULL;
	return (new);
}

int 		**init_link_arr(t_lem_in *l_i)
{
	int 	**new;
	int 	i;
	int 	j;

	if (!(new = (int **)malloc(sizeof(int *) * l_i->room_num)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < l_i->room_num)
	{
		if (!(new[i] = (int *)malloc(sizeof(int) * l_i->room_num)))
			return (NULL);
		while (j < l_i->room_num)
		{
			new[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (new);
}

t_room		*init_room(void)
{
	t_room		*new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	new->level = -1;
	new->x = 0;
	new->y = 0;
	new->name = NULL;
	new->num_input = 0;
	new->num_output = 0;
	new->visited = 0;
	new->ant_name = -1;
	new->next = NULL;
	return (new);
}

t_lem_in	*init_l_i(void)
{
	t_lem_in	*new;

	if (!(new = (t_lem_in *)malloc(sizeof(t_lem_in))))
		return (NULL);
	new->ant_num = 0;
	new->ant_start = 0;
	new->ant_end = 0;
	new->room_num = 0;
	new->link_num = 0;
	new->line = NULL;
	new->link_arr = NULL;
	new->flag = 0;
	new->s_r_flag = 0;
	new->e_r_flag = 0;
	new->s_l_flag = 0;
	new->e_l_flag = 0;
	new->i = 1;
	new->j = 0;
	if (!(new->rooms = (t_room **)malloc(sizeof(t_room*))))
		return (NULL);
	return (new);
}

/*
int			init_all(t_lem_in **l_i, t_room **room, t_link **link)//, t_queue **queue)
{
	if (!(*room = init_room()))
		return (ERROR);
	if (!(*link = init_link()))
		return (ERROR);
	*/
/*if (!(*queue = init_queue()))
		return (ERROR);*//*

	if (!(*l_i = init_l_i()))
		return (ERROR);
	return (0);
}*/
