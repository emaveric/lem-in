/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 16:53:29 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/30 11:54:23 by eshor            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		is_flags(char *p)
{
	if (*p == '#' || *p == '0' || *p == '+' || *p == '-' || *p == ' ')
		return (1);
	return (0);
}

int		is_width(char *p)
{
	if (*p > '0' && *p <= '9')
		return (1);
	return (0);
}

int		is_precision(char **p, t_pf *pf)
{
	if (**p == '.' && (*(*p + 1) >= '0' && *(*p + 1) <= '9'))
	{
		pf->dot = 1;
		return (1);
	}
	else if (**p == '.')
	{
		pf->dot = 1;
		*p += 1;
	}
	return (0);
}

int		is_size(char *p)
{
	if (ft_strchr("hlL", *p))
		return (1);
	return (0);
}
