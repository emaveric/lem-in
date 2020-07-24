/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:07:40 by emaveric          #+#    #+#             */
/*   Updated: 2020/07/24 13:54:46 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define MAX_INT 2147483647
# define ERROR -1
# define B_SIZE 3000000

# include "../ft_printf/libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"

typedef struct		s_room
{
	int 			num; // номер комнаты
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
	int 			i;
	int 			flag;
	int 			s_flag;
	int 			e_flag;
	int 			ant_num;
	int 			ant_start;
	int 			ant_end;
	int 			room_num; // кол-во
	int 			link_num;
	int 			**link_arr;
	char 			**line;
	/*t_room 			*start;
	t_room			*end;*/
	t_room			**rooms;
	t_link			**links;
}					t_lem_in;

int					empty_line_check(const char *line);
int 				get_map(t_lem_in *l_i);
int 				link_or_room(t_lem_in *l_i, const char *line);
int 				coord_valid(t_lem_in *l_i, char **str, int n);
int					get_room(t_lem_in *l_i, char *line, int i, int j);
t_lem_in			*init_l_i(void);
t_room				*init_room(void);
int 				**init_link_arr(t_lem_in *l_i);
int 				same_name_and_coord_valid(t_lem_in *l_i);
int 				is_link(t_lem_in *l_i);


#endif
