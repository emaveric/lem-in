/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 14:55:37 by emaveric          #+#    #+#             */
/*   Updated: 2020/08/10 15:27:19 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int 	error(int flag, char **str)
{
	if (str)
		str_free(str, 0)
	if (flag == 1)
		ft_printf("Map error! No end or start link");
	if (flag == 2)
		ft_printf("Map error! Ant error");
	if (flag == 3)
		ft_printf("Map error! Error line");
	if (flag == 4)
		ft_printf("Map error! Same coordinate or room");
	if (flag == 5)
		ft_printf("Map error! Error link");
	if (flag == 6)
		ft_printf("Map error! Same link");
	if (flag == 7)
		ft_printf("Map error! Error room");
	if (flag == 8)
		ft_printf("Map error! Error coordinate");
	if (flag == 9)
		ft_printf("Map error! Too much room");
	return (-1);
}