/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 13:06:58 by eshor             #+#    #+#             */
/*   Updated: 2020/08/10 17:30:53 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		buff_free(char *buff)
{
	if (buff)
		free(buff);
	return (ERROR);
}

void	free_rooms(t_lem_in **lem_in)
{
	int i;

	i = 0;
	while (i < (*lem_in)->room_num && (*lem_in)->rooms)
	{
		free((*lem_in)->rooms[i]->name);
		free((*lem_in)->rooms[i]);
		i++;
	}
	if ((*lem_in)->rooms)
		free((*lem_in)->rooms);
}

int		str_free(char **str, int i)
{
	if (str)
	{
		while (str[i])
		{
			free(str[i]);
			i++;
		}
		if (str)
			free(str);
	}
	return (0);
}

int		free_all(t_lem_in **lem_in)
{
	int i;

	i = 0;
	while (i < (*lem_in)->room_num && (*lem_in)->link_arr)
	{
		if ((*lem_in)->link_arr[i])
			free((*lem_in)->link_arr[i]);
		i++;
	}
	if ((*lem_in)->link_arr)
		free((*lem_in)->link_arr);
	free_rooms(lem_in);
	free_paths((*lem_in)->paths, (*lem_in)->path_num);
	str_free((*lem_in)->line, 0);
	free(*lem_in);
	return (ERROR);
}

void	free_paths(t_path **paths, int num)
{
	int i;

	i = 0;
	while (i < num)
	{
		free(paths[i]);
		i++;
	}
	if (paths)
		free(paths);
	paths = NULL;
}
