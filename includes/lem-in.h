/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:07:40 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/20 20:50:12 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define MAX_INT 2147483647
# define ERROR -1


# include "../ft_printf/libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct		s_room
{
	char			*name;
	int 			level;
	int 			x;
	int 			y;
	int 			num_input;
	int 			num_output;
	int 			visited;
	struct s_room	*next;
	int 			ant_name;
}					t_room;

typedef struct		s_link
{
	t_room 			*start;
	t_room 			*end;
}					t_link;

typedef struct		s_queue
{
	t_room 			*room;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_lem_in
{
	int 			ant_num;
	int 			ant_start;
	int 			ant_end;
	int 			**link_arr;
	t_room			*rooms;
	t_link			*links;
}					t_lem_in;

#endif
