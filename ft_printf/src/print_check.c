/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 16:39:21 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/19 16:39:21 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			print_res(char *str, int len, int n)
{
	if ((n == 1 && *str) || n == 2)
		write(1, str, len);
}

static void		fill_buf(t_pf *pf, char **p)
{
	(pf->type) ? fill_final(pf, pf->buff, 1, pf->buf_len)
				: fillbuff(pf, &*p);
	if (pf->str_len + pf->buf_len == BF_SIZE - 1)
	{
		print_res(pf->buff, pf->buf_len, 2);
		pf->buf_len = 0;
	}
}

void			check_buf(t_pf *pf, char **p)
{
	if (pf->str_len + pf->buf_len < BF_SIZE)
		fill_buf(pf, p);
	else if (pf->str_len + pf->buf_len >= BF_SIZE)
	{
		if (pf->buf_len > 0)
		{
			print_res(pf->buff, pf->buf_len, 2);
			pf->buf_len = 0;
			(pf->type) ? fill_final(pf, pf->buff, 1, pf->buf_len)
						: fillbuff(pf, &*p);
		}
		else
		{
			(pf->type) ? fill_final(pf, pf->str, 2, pf->str_len)
						: fill_string(pf, &*p);
			print_res(pf->str, pf->str_len, 1);
		}
	}
	if (**p == '\0' && pf->buf_len > 0)
		print_res(pf->buff, pf->buf_len, 2);
}
