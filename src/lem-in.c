/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:07:30 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/22 21:13:15 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int		map_reading(int fd, t_lem_in *l_i)
{
    char 	buff[B_SIZE + 1];
    int 	data;
    int 	i;
    char 	*line;

    /*if (!(data = read(fd, buff, B_SIZE)))
    	return (ERROR); // минимально возможное кол-во символов на валидной карте - 32
    buff[data] = '\0';*/
    i = 0;
    line = NULL;
    get_next_line(fd, &line);
    if (ft_strlen(line) < 32 || empty_line_check(line) == ERROR)
    	return (ERROR);
    l_i->line = ft_strsplit(buff, '\n');
    while (l_i->line[i])
	{
		if (l_i->line[i][0] != '#' && link_valid(l_i, l_i->line[i]) == 1)
			l_i->room_num++;
		i++;
	}
    if (get_map(l_i) == ERROR)
    	return (ERROR);
    return (0);
}

int		main(int ac, char **av)
{
	t_lem_in	*l_i;
	char 		tmp;

	if (init_l_i(l_i) == ERROR)
		return (0);
	if (ac == 1 && av[1] == NULL)
	{
		if (read(0, &tmp, 0) == 0)
		{
			map_reading(0, l_i);
		}
		else
			return (ERROR);
	}
	else
		return (ERROR);
	return (0);
}