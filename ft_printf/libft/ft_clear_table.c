/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:44:25 by emaveric          #+#    #+#             */
/*   Updated: 2020/01/22 14:37:51 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_clear_table(char **tables, int i)
{
	int index;

	index = 0;
	if (!tables)
		return (NULL);
	while (index < i)
	{
		ft_memdel((void**)&tables[index]);
		index++;
	}
	ft_memdel((void**)&tables);
	return (NULL);
}
