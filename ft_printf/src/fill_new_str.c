/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_new_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 16:11:09 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/25 15:57:05 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	fillbuff(t_pf *pf, char **p)
{
	int i;
	int len;

	i = 0;
	i += pf->buf_len;
	len = pf->str_len + i;
	while (i < len)
	{
		if (**p == '%')
		{
			pf->buff[i] = '%';
			i++;
			*p += 2;
			pf->percent += 1;
		}
		else
		{
			pf->buff[i] = **p;
			i++;
			*p += 1;
		}
	}
	pf->buf_len += pf->str_len;
}

void	fill_string(t_pf *pf, char **p)
{
	int i;

	i = 0;
	while (i < pf->str_len)
	{
		if (**p == '%')
		{
			pf->str[i] = '%';
			i++;
			*p += 2;
			pf->percent += 1;
		}
		else
		{
			pf->str[i] = **p;
			i++;
			*p += 1;
		}
	}
	pf->str[i] = '\0';
}

int		new_str(t_pf *pf, char **p)
{
	int i;

	i = 0;
	pf->str_len = 0;
	while (*(*p + i) != '\0')
	{
		if (*(*p + i) == '%' && *(*p + i + 1) != '%')
			break ;
		if (*(*p + i) == '%' && *(*p + i + 1) == '%')
			i++;
		i++;
		pf->str_len += 1;
	}
	if (pf->str_len == 0)
		return (0);
	if (!(pf->str = ft_memalloc(pf->str_len + 1)))
		return (0);
	check_buf(pf, &*p);
	return (pf->str_len);
}
