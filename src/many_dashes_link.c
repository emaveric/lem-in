/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_dashes_link.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/26 19:33:42 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/27 18:15:08 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem-in.h"

int 	second_name(t_lem_in *l_i, char *str1, int i)
{
	while (i < l_i->room_num)
	{
		if (ft_strcmp(l_i->rooms[i]->name, str1) == 0 && l_i->j != i)
			break;
		i++;
	}
	//printf("test i = %d\n", i);
	if (i < l_i->room_num)
	{
		if (is_link(l_i, l_i->j, i) == ERROR)
			return (ERROR);
		/*l_i->link_arr[l_i->j][i] = 1;
		l_i->link_arr[i][l_i->j] = 1;
		l_i->link_num++;*/
		l_i->j = 0;
		//printf("i = %d, j = %d\n", i, l_i->j);
		printf("good\n");
		return (0);
	}
	printf("not found\n");
	return (ERROR);
}

int 	first_name(t_lem_in *l_i, const char *line, int k, const int *len)
{
	char	*str1;
	int		i;

	i = 0;
	while (l_i->j < k)
	{
		if (!(str1 = ft_memalloc(len[l_i->j] + 1)))
			return (ERROR);
		str1 = ft_strncpy(str1, line, len[l_i->j]);
		str1[len[l_i->j] + 1] = '\0';
		//printf("str1 = %s\n", str1);
		while (i < l_i->room_num)
		{
			if (ft_strcmp(l_i->rooms[i]->name, str1) == 0)
				break;
			i++;
		}
		//printf("%d\n", i);
		free(str1);
		if (i < l_i->room_num)
			break;
		l_i->j++;
		i = 0;
	}
	if (l_i->j == k)
		return (ERROR);
	return (i);
}

void	len_search(const char *line, t_lem_in *l_i, int k, int *len)
{
	int 	i;

	i = 1;
	if (k != ft_strlen(line) && l_i->j == 0)
		i = 0;
	l_i->j = 0;
	if (/*k == ft_strlen(line)*/i == 1)
		len[0] = 1;
	else
		while (line[i] == '-')
		{
			len[0] += 1;
			i++;
		}
	while (line[i] != '\0')
	{
		if (line[i] == '-')
		{
			//printf("len[%d] = %d\n", l_i->j, len[l_i->j]);
			l_i->j++;
			len[l_i->j] = len[l_i->j - 1];
		}
		len[l_i->j] += 1;
		i++;
	}
	//return (j);
}

int 	only_dashes(t_lem_in *l_i, const char *line, int i, int k)
{
	//printf("line = %s\n", line);
	while (line[i] == '-')
		i++;
	l_i->j = i;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			k++;
		i++;
	}
	if (k == 0 && line[l_i->j] != '\0')
	{
		printf("J = %d, LINE[J] = %c\n", l_i->j, line[l_i->j]);
		k = l_i->j;
	}
	if (k == 0)
		k = ft_strlen(line);
	return (k);
}

int 	many_dashes_link(t_lem_in *l_i, const char *line, int i)
{
	int 	k;
	int 	flag;
	int 	*len;
	char 	*str1;

	k = only_dashes(l_i, line, i, 0);
	flag = l_i->j;
	//printf("K = %d\n", k);
	/*if (k != ft_strlen(line))
		i = 0;*/
	if (!(len = (int *)malloc(sizeof(int) * k + 1)))
		return (ERROR);
	len_search(line, l_i, k, len);
	//printf("len[%d] = %d\n", l_i->j, len[l_i->j]);
	len[l_i->j + 1] = -1;
	//printf("last %d\n", l_i->j + 1);
	l_i->j = 0;
	//printf("%d, %d\n", len, k);
	if ((i = first_name(l_i, line, k, len)) == ERROR)
		return (ERROR);
	//printf("j = %d\n", l_i->j);
	if (k == ft_strlen(line) || flag != 0)
	{
		//j++;
		k--;
	}
	//printf("k = %d, len[k] = %d, len[j] = %d\n", k, len[k], len[l_i->j]);
	//printf("len = %d\n", len[k] - len[l_i->j]);
	if (!(str1 = ft_memalloc(len[k] - len[l_i->j])))
		return (ERROR);
	//printf("test\n");
	str1 = ft_strfromcpy(str1, line, len[l_i->j] + 1);
	//printf("str2 = %s\n", str1);
	l_i->j = i;
	if (second_name(l_i, str1, 0) == ERROR)
		return (ERROR);
	return (0);
}
