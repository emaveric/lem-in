/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 15:47:49 by emaveric          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/07/27 16:23:50 by emaveric         ###   ########.fr       */
=======
/*   Updated: 2020/08/10 16:45:28 by eshor            ###   ########.fr       */
>>>>>>> lexa
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char		**init_link_arr(t_lem_in *l_i)
{
	char	**new;
	int		i;
	int		j;

	if (!(new = (char **)malloc(sizeof(char *) * l_i->room_num)))
		return (NULL);
<<<<<<< HEAD
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
=======
>>>>>>> lexa
	i = 0;
	j = 0;
	while (i < l_i->room_num)
	{
<<<<<<< HEAD
		if (!(new[i] = (int *)malloc(sizeof(int) * l_i->room_num)))
=======
		if (!(new[i] = (char *)malloc(sizeof(char) * l_i->room_num)))
>>>>>>> lexa
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
<<<<<<< HEAD
	new->visited = 0;
	new->ant_name = -1;
	new->next = NULL;
	new->prev = NULL;
=======
	new->visited = 1;
	new->flag = 0;
	new->label = 0;
	new->ant_name = -1;
	new->d_flag = 0;
	new->next = NULL;
	new->temp_next = NULL;
	new->prev = NULL;
	new->temp_prev = NULL;
>>>>>>> lexa
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
<<<<<<< HEAD
	new->paths = NULL;
	new->path_num = 0;
	new->bfs_level = 0;
	/*new->start = NULL;
	new->end = NULL;*/
	if (!(new->rooms = (t_room **)malloc(sizeof(t_room*))))
		return (NULL);
	new->links = NULL;
=======
	new->n_turns = MAX_INT;
	new->paths_temp = NULL;
>>>>>>> lexa
	return (new);
}
