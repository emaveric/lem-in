/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:47:49 by emaveric          #+#    #+#             */
/*   Updated: 2020/08/10 14:11:45 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	**init_link_arr(t_lem_in *l_i)
{
	char	**new;
	int 	i;
	int 	j;

	if (!(new = (char **)malloc(sizeof(char *) * l_i->room_num)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < l_i->room_num)
	{
		if (!(new[i] = (char *)malloc(sizeof(char) * l_i->room_num)))
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

	if (!(new = (t_room *)malloc(sizeof(struct s_room))))
		return (NULL);
	new->level = -1;
	new->x = 0;
	new->y = 0;
	new->name = NULL;
	new->num_input = 0;
	new->num_output = 0;
	new->visited = 1;
	new->flag = 0;
	new->label = 0;
	new->ant_name = -1;
	new->d_flag = 0;
	new->next = NULL;
    new->temp_next = NULL;
    new->prev = NULL;
    new->temp_prev = NULL;
	return (new);
}

t_lem_in	*init_l_i(void)
{
	t_lem_in	*new;

	if (!(new = (t_lem_in *)malloc(sizeof(struct s_lem_in))))
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
    new->n_turns = MAX_INT;
    new->paths_temp = NULL;
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
