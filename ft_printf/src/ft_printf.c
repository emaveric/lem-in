/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 16:10:21 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/28 21:40:44 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_chars(t_pf *pf)
{
	pf->size = NULL;
	pf->str = NULL;
	pf->tmp_oxfs = NULL;
	pf->sharp = NULL;
}

t_pf	*init(void)
{
	t_pf *pf;

	if (!(pf = (t_pf*)malloc(sizeof(t_pf))))
		return (NULL);
	if (!(pf->flags = ft_memalloc(6)))
		return (NULL);
	pf->width = 0;
	pf->precision = -1;
	pf->type = '\0';
	pf->symbol = -1;
	pf->symb_width = 0;
	pf->prec_width = 0;
	pf->dot = 0;
	pf->str_len = 0;
	pf->percent = 0;
	pf->counter = 0;
	pf->num.i = 0;
	pf->plus = 0;
	pf->minus = 0;
	pf->space = 0;
	pf->float_dot = 0;
	pf->buf_len = 0;
	init_chars(pf);
	return (pf);
}

int		work_part(char *p, t_pf *pf, va_list ap)
{
	while (*p != '\0')
	{
		if (*p == '%' && *(p + 1) != '%')
		{
			if (pf_format(pf, &p, ap) == -1)
			{
				free_t_pf(pf, 0);
				va_end(ap);
				return (0);
			}
			free_t_pf(pf, 1);
		}
		else
		{
			pf->counter += new_str(pf, &p);
			free_t_pf(pf, 1);
		}
	}
	return (1);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	char	*p;
	t_pf	*pf;
	int		sum;

	va_start(ap, format);
	p = (char*)format;
	if (!(pf = init()))
		return (0);
	if (work_part(p, pf, ap) == 0)
	{
		va_end(ap);
		return (0);
	}
	sum = pf->counter;
	free_t_pf(pf, 0);
	va_end(ap);
	return (sum);
}
