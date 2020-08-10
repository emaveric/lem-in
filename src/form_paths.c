/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_paths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:07:32 by eshor             #+#    #+#             */
/*   Updated: 2020/08/10 14:11:36 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_path	*create_path(t_room *head, int len)
{
	t_path *path;

	if (!(path = (t_path*)malloc(sizeof(t_path))))
		return (NULL);
	path->head = head;
	path->len = len;
	path->comp = 0;
	return (path);
}

int		does_path_end(t_lem_in *lem_in, int room_id)
{
	int i;
	int len;

	len = 0;
	if (room_id == lem_in->room_num - 1)
		return (1);
	while (1)
	{
		i = 1;
		while (i < lem_in->room_num)
		{
			if (lem_in->link_arr[room_id][i] == 1)
			{
				len++;
				if (i == lem_in->room_num - 1)
					return ((len + 1) / 2);
				room_id = i;
				break ;
			}
			i++;
		}
		if (i == lem_in->room_num)
			return (ERROR);
	}
}

void	set_next_prev(t_lem_in *lem_in, int room_id)
{
	int i;

	lem_in->rooms[room_id]->temp_prev = NULL;
	while (room_id != lem_in->room_num - 1)
	{
		i = 1;
		while (i < lem_in->room_num)
		{
			if (lem_in->link_arr[room_id][i] == 1)
			{
				lem_in->rooms[room_id]->temp_next = lem_in->rooms[i];
				if (i != lem_in->room_num - 1)
					lem_in->rooms[i]->temp_prev = lem_in->rooms[room_id];
				room_id = i;
				break ;
			}
			i++;
		}
	}
}

int		get_num_paths(t_lem_in *lem_in)
{
	int num;
	int i;

	num = 0;
	i = 0;
	while (i < lem_in->room_num)
	{
		if (lem_in->link_arr[0][i] == 1 &&
		(i == lem_in->room_num - 1 || does_path_end(lem_in, i) != ERROR))
			num++;
		i++;
	}
	return (num);
}

t_path	**pathfinder(t_lem_in *lem_in, int *num)
{
	int		i;
	int		len;
	t_path	*one_path;

	lem_in->path_num = get_num_paths(lem_in);
	if (!(lem_in->paths = (t_path**)malloc(sizeof(t_path*) * lem_in->path_num)))
		return (NULL);
	i = 0;
	lem_in->path_num = 0;
	while (++i < lem_in->room_num)
	{
		if (lem_in->link_arr[0][i] == 1 &&
		(len = does_path_end(lem_in, i)) != ERROR)
		{
			one_path = create_path(lem_in->rooms[i], len);
			if (!one_path)
				return (NULL);
			set_next_prev(lem_in, i);
			lem_in->paths[lem_in->path_num] = one_path;
			lem_in->path_num++;
		}
	}
	sort_paths(lem_in->paths, 0, lem_in->path_num - 1);
	define_comp_num(lem_in->paths, lem_in->path_num);
	return (lem_in->paths);
}
