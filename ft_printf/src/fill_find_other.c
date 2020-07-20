/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:13:05 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/19 16:13:05 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*find_tmp(t_pf *pf)
{
	char *tmp;

	tmp = NULL;
	if (pf->type == '%')
		pf->num.c = '%';
	if (pf->type == 's' || pf->type == 'S')
		tmp = (pf->precision <= 0 && pf->dot) ? NULL : ft_strdup(pf->tmp_oxfs);
	if (ft_strchr("fF", pf->type))
		tmp = ft_strdup(pf->tmp_oxfs);
	if (ft_strchr("poxX", pf->type))
		tmp = ft_strdup(pf->tmp_oxfs);
	if (ft_strchr("di", pf->type))
		if (!(tmp = ft_lltoa(pf->num.lli)))
			return (NULL);
	if ((pf->precision <= 0 && pf->dot) && pf->num.lli == 0)
		tmp = NULL;
	if (pf->type == 'u')
	{
		if (pf->num.ulli == 0 && (pf->precision <= 0 && pf->dot))
			tmp = NULL;
		else
			tmp = ft_ulltoa(pf->num.ulli);
	}
	return (tmp);
}

void	fill_with_symb(char *str, int *i, char c, int len)
{
	len += *i;
	while (*i < len)
	{
		str[*i] = c;
		*i += 1;
	}
}

void	fill_with_sharp(t_pf *pf, char *str, int *i)
{
	int j;

	j = 0;
	while (pf->sharp[j] != '\0')
	{
		str[*i] = pf->sharp[j];
		j++;
		*i += 1;
	}
}
