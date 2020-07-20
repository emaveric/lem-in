/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 17:26:29 by emaveric          #+#    #+#             */
/*   Updated: 2019/12/04 17:30:51 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp_free(char *s1, char *s2, int opt)
{
	int		numb;

	numb = ft_strcmp(s1, s2);
	if (opt == 1 || opt > 2)
		free(s1);
	if (opt >= 2)
		free(s2);
	return (numb);
}
