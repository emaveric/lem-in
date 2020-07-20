/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 21:53:56 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/19 17:06:49 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (del && alst)
	{
		if (*alst)
		{
			del((*alst)->content, (*alst)->content_size);
			free(*alst);
			*alst = NULL;
		}
	}
}
