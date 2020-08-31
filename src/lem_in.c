/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:07:30 by emaveric          #+#    #+#             */
/*   Updated: 2020/08/10 17:23:49 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		map_reading(int fd, t_lem_in *l_i)
{
	char	*buff;
	int		data;

	buff = (char*)ft_memalloc(B_SIZE + 1);
	if ((data = read(fd, buff, B_SIZE)) < 32)
	{
		ft_printf("Error map\n");
		return (buff_free(buff));
	}
	buff[data] = '\0';
	if (empty_line_check(buff) == ERROR)
		return (buff_free(buff));
	l_i->line = ft_strsplit(buff, '\n');
	if (room_num_check(l_i, 0) == ERROR)
		return (buff_free(buff));
	if (get_map(l_i, -1) == ERROR)
		return (buff_free(buff));
	free(buff);
	return (0);
}

int		main(int ac, char **av)
{
	t_lem_in	*l_i;
	char		tmp;

	if (!(l_i = init_l_i()))
		return (0);
	if (ac == 1 && av[1] == NULL)
	{
		if (read(0, &tmp, 0) == 0)
		{
			if (map_reading(0, l_i) == ERROR)
				return (free_all(&l_i));
		}
		else
			return (free_all(&l_i));
	}
	else
		return (free_all(&l_i));
	start_algo(l_i);
	free_all(&l_i);
	exit(0);
}
