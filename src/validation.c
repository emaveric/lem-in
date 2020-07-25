/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 14:56:06 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/25 21:01:10 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int 	coord_valid(t_lem_in *l_i, char **str, int n)
{
	int 	i;
	int 	j;

	i = 0;
	j = 1;
	while (j < 3)
	{
		while (str[j][i] != '\0')
		{
			if (ft_isdigit(str[j][i]) == 0)
			{
				printf("error coord\n");
				return (ERROR);
			}
			i++;
		}
		i = 0;
		j++;
	}
	if (ft_atoi_max_int(&l_i->rooms[n]->x, str[1]) == -1)
		return (ERROR);
	if (ft_atoi_max_int(&l_i->rooms[n]->y, str[2]) == -1)
		return (ERROR);
	return (0);
}

int 	is_link(t_lem_in *l_i, int j, int k)
{
	if (k == -1 || j == -1 ||
		l_i->link_arr[j][k] == 1 || l_i->link_arr[k][j] == 1)
	{
		//printf("k = %d, j = %d, [j][k] = %d, [k][j] = %d, same link\n", k, j, l_i->link_arr[j][k], l_i->link_arr[k][j]);
		return (ERROR);
	}
	if (k == 0 || j == 0)
		l_i->s_l_flag = 1;
	if (k == l_i->room_num - 1 || j == l_i->room_num - 1)
		l_i->e_l_flag = 1;
	return (0);
	/*int 	i;
	int 	flag;
	int 	j;


	i = 0;
	flag = 0;
	while (i < l_i->room_num)
	{
		if (l_i->link_arr[0][i] == 1)
		{
			flag = 1;
			break;
		}
		i++;
	}
	if (flag == 0)
		return (ERROR);
	i = 0;
	while (i < l_i->room_num)
	{
		if (l_i->link_arr[l_i->room_num - 1][i] == 1)
			return (0);
		i++;
	} ^ проверка на линки в начальной и конечной комнатах */
	/*i = 0;
	j = 0;
	while (i < l_i->room_num)
	{
		while (j < l_i->room_num)
		{
			if (l_i->link_arr[i][j] == 1 && l_i->link_arr[j][i] == 1)
				return (0);
			j++;
		}
		i++;
		j = 0;
	}*/
	return (ERROR);
}

int 	same_name_and_coord_valid(t_lem_in *l_i)
{
	int		i;
	int 	j;

	i = 0;
	j = 1;
	while (i < l_i->room_num)
	{
		while (j < l_i->room_num)
		{
			if (i != j)
				if (ft_strcmp(l_i->rooms[i]->name, l_i->rooms[j]->name) == 0 ||
					(l_i->rooms[i]->x == l_i->rooms[j]->x &&
					l_i->rooms[i]->y == l_i->rooms[j]->y))
				{
					//printf("same\n");
					return (ERROR);
				}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int 	link_or_room(t_lem_in *l_i, const char *line)
{
	int 	i;

	i = 0;
	while (line[i] != '\0' && line[i] != ' ')
		i++;
	if (line[i] == ' ')
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\0')
			return (ERROR);
		else
			return (1);
	}
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-' || line[0] == '#')
			return (0);
		i++;
	}
	return (ERROR);
}

/*
int 	test_links(t_lem_in *l_i, const char *line)
{
	int 	i;
	int 	j;
	int 	k;
	int 	len;
	char 	*str1;
	char 	*str2;

	i = 0;
	k = 0;
	len = 0;
	while (line[i] != '\0')
	{
		if (k == 0)
			len++;
		if (line[i] == '-')
			k++;
		i++;
	}
	i = 0;
	j = k;
	printf("%d, %d\n", len, k);
	while (j > 1)
	{
		str1 = ft_memalloc(len + j);
		str1 = ft_strncpy(str1, line, len + j - 1);
		printf("str1 = %s\n", str1);
		while (i < l_i->room_num)
		{
			if (ft_strcmp(l_i->rooms[i]->name, str1) == 0)
				break;
			i++;
		}
		if ()
		printf("%d\n", i);
		free(str1);
		i = 0;
		j--;
	}
	j = k - j;
	while (j > 1)
	{
		if (k == j)
		{
			str2= ft_memalloc(ft_strlen(line) + 1);
			str2 = ft_strcpy(str2, line);
			str2 = ft_strcut(str2, '-');
		}
		str2 = ft_strjoin("-", str2);
		printf("str2 = %s\n", str2);
		while (i < l_i->room_num)
		{
			if (ft_strcmp(l_i->rooms[i]->name, str2) == 0)
				break;
			i++;
		}
		i = 0;
		j--;
	}
	printf("\ntest\n");
	return (0);
}*/
