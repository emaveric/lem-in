/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 17:01:09 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/25 15:54:21 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	find_flags(t_pf *pf, char **p)
{
	int i;

	i = 0;
	while (ft_strchr("-+ #0", **p))
	{
		if (**p == '-')
			pf->flags[i] = '-';
		if (**p == '+')
			pf->flags[i] = '+';
		if (**p == ' ')
			pf->flags[i] = ' ';
		if (**p == '#')
			pf->flags[i] = '#';
		if (**p == '0')
			pf->flags[i] = '0';
		i++;
		*p += 1;
	}
}

void	find_width(t_pf *pf, char **p)
{
	pf->width = ft_atoi(*p);
	*p += ft_numlen(pf->width);
}

void	find_precision(t_pf *pf, char **p)
{
	++(*p);
	pf->precision = ft_atoi(*p);
	while (!(ft_strchr("LlhdifFouxXsScCp%", **p)))
		*p += 1;
}

void	find_size(t_pf *pf, char **p)
{
	if ((**p == 'h' && *(*p + 1) == 'h') || (**p == 'l' && *(*p + 1) == 'l'))
	{
		pf->size = ft_strdup((**p == 'h') ? "hh" : "ll");
		*p += 2;
	}
	else if (**p == 'h' || **p == 'l')
	{
		pf->size = ft_strdup((**p == 'h') ? "h" : "l");
		*p += 1;
	}
	else if (**p == 'L')
	{
		pf->size = ft_strdup("L");
		*p += 1;
	}
}
