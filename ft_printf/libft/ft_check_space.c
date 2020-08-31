/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_space.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/25 20:12:42 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/25 20:13:06 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_space(const char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			return (0);
		i++;
	}
	return (-1);
}
