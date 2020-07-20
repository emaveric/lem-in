/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:01:37 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/19 17:01:37 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		put_if_precision_null(t_float *fl, t_pf *pf, long double num)
{
	real_rounding(fl, pf, num);
	fl->pos = 0;
	while (*(fl->frst + fl->pos) != '\0')
	{
		*(fl->res + fl->pos) = *(fl->frst + fl->pos);
		fl->pos++;
	}
}

void		put_if_precision_not_null(t_float *fl, t_pf *pf, long double num)
{
	real_rounding(fl, pf, num);
	fl->pos = 0;
	while (*(fl->frst + fl->pos) != '\0')
	{
		*(fl->res + fl->pos) = *(fl->frst + fl->pos);
		fl->pos++;
	}
	*(fl->res + fl->pos) = '.';
	fl->pos++;
	while (*(fl->scnd + fl->i) != '\0')
	{
		*(fl->res + fl->pos) = *(fl->scnd + fl->i);
		fl->pos++;
		fl->i++;
	}
}

char		*put_in_str(t_pf *pf, t_float *fl, long double num)
{
	if (!(fl->res = ft_memalloc((ft_strlen(fl->frst))
			+ ((pf->precision == 0) ? 0 : (ft_strlen(fl->scnd) + 1))
			+ (((*pf->flags == '#') && pf->precision == 0)
					? -1 : 0) + 1)))
		return (NULL);
	if (pf->precision == 0)
		put_if_precision_null(fl, pf, num);
	else
		put_if_precision_not_null(fl, pf, num);
	*(fl->res + fl->pos) = '\0';
	return (fl->res);
}
