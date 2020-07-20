/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 20:18:51 by emaveric          #+#    #+#             */
/*   Updated: 2019/05/20 22:16:39 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	ft_new_line(const int fd, char **line, char **point, int div)
{
	int		len;
	char	*tnew;

	len = 0;
	tnew = NULL;
	while (point[fd][len] != '\n' && point[fd][len] != '\0')
		len++;
	if (point[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(point[fd], 0, len)))
			return (-1);
		if (!(tnew = ft_strdup(point[fd] + len + 1)))
			return (-1);
		ft_strdel(&point[fd]);
		point[fd] = ft_strdup(tnew);
	}
	else if (point[fd][len] == '\0')
	{
		if (div == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(point[fd]);
		ft_strdel(&point[fd]);
	}
	free(tnew);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*text;
	int			div;
	static char	*point[12000];

	if (fd < 0 || (!line) || BUFF_SIZE < 1 || fd > 12000)
		return (-1);
	while ((div = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[div] = '\0';
		if (point[fd] == NULL)
			text = ft_strdup(buf);
		else if (!(text = ft_strjoin(point[fd], buf)))
			return (-1);
		ft_strdel(&point[fd]);
		point[fd] = ft_strdup(text);
		free(text);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (div < 0)
		return (-1);
	if (div == 0 && (point[fd] == NULL || point[fd][0] == '\0'))
		return (0);
	return (ft_new_line(fd, line, point, div));
}
