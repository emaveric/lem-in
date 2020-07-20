/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_maker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:52:42 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/22 13:46:21 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*add_null(t_pf *pf, t_float *fl, int what)
{
	unsigned long long i;

	i = 0;
	if (what == 1)
		while (*(fl->scnd + i) != '\0')
			i++;
	while (i < (unsigned long long)pf->precision)
	{
		*(fl->scnd + i) = 48;
		i += 1;
	}
	*(fl->scnd + i) = '\0';
	return (fl->scnd);
}

char		*rounding(long double num, unsigned long long i,
										t_float *fl, int prec)
{
	int precsn;

	precsn = prec;
	if ((num) < 0.1 && num != 0 && i < (unsigned long long)prec)
	{
		*((fl->scnd) + i) = '0';
		i += 1;
		rounding(num * 10 + ft_pow_double(0.1, precsn), i,
			fl, prec--);
	}
	return (fl->scnd);
}

void		fill_char_from_int(unsigned long long what, char *where)
{
	int i;

	i = (int)ft_len_of_number(what);
	*(where + i) = '\0';
	i -= 1;
	while (what && i >= 0)
	{
		*(where + i) = (char)((what % 10) + 48);
		i--;
		what = what / 10;
	}
}

char		*make_decimal(t_float *fl, t_pf *pf)
{
	if (pf->precision > 0)
	{
		if (pf->precision < 19)
			fl->second = (fl->second % 10 > 4) ? (fl->second / 10 + 1)
					: (fl->second / 10);
		if (fl->second == 0)
			return (fl->scnd);
		if (!(fl->tmp = ft_memalloc(ft_len_of_number(fl->second) + 1)))
			return (NULL);
		fill_char_from_int(fl->second, fl->tmp);
		fl->scnd = pf_strcpy(fl->scnd, fl->tmp, ft_strlen(fl->scnd));
		return (fl->scnd);
	}
	return (fl->scnd);
}

void		real_rounding(t_float *fl, t_pf *pf, long double num)
{
	fl->flag = 0;
	if (pf->precision == 0)
	{
		if (*(fl->scnd) == 53 && (num - fl->first) >= 0.5)
			(((fl->first) % 2 == 0 && (num - fl->first) <= 0.5) ? 0
			: ((fl->first += 1) && (fl->flag = 1)));
		if (fl->flag == 1)
		{
			free(fl->frst);
			fl->frst = pf_itoa(fl->first);
		}
		else
			((*(fl->scnd) > 52) ? (fl->first += 1) &&
			(fl->frst = pf_itoa(fl->first)) : 0);
	}
	else if ((pf->precision == 1 && (*(fl->scnd + 1) == '0'))
	|| ((fl->second % 10) > 0 && (*(fl->scnd + 1) == '0') && fl->tmp == NULL) ||
	((*(fl->scnd + 1) == '0') && (num - fl->first > 0.901)))
	{
		fl->first += 1;
		fill_char_from_int(fl->first, fl->frst);
		fl->scnd = add_null(pf, fl, 0);
	}
}
