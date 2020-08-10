/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshor <eshor@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 20:07:40 by emaveric          #+#    #+#             */
/*   Updated: 2020/08/10 16:52:06 by eshor            ###   ########.fr       */
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
	int				num;
	char			*name;
	int				level;
	int				x;
	int				y;
	int				num_input;
	int				num_output;
	int				visited;
	int				flag;
	int				label;
	int				d_flag;
	struct s_room	*next;
	struct s_room	*prev;
	struct s_room	*temp_next;
	struct s_room	*temp_prev;
	int				ant_name;
}					t_room;

typedef struct		s_queue
{
	t_room			*room;
	struct s_queue	*next;
}					t_queue;

typedef struct		s_path
{
	t_room			*head;
	int				len;
	int				comp;
	struct s_path	*next;
}					t_path;

typedef struct		s_lem_in
{
	int				i;
	int				j;
	int				flag;
	int				s_r_flag;
	int				e_r_flag;
	int				s_l_flag;
	int				e_l_flag;
	int				ant_num;
	int				ant_start;
	int				ant_end;
	int				room_num;
	int				link_num;
	char			**link_arr;
	char			**line;
	t_room			**rooms;
	t_path			**paths;
	int				path_num;
	t_path			**paths_temp;
	int				path_num_temp;
	int				bfs_level;
	int				n_turns;
}					t_lem_in;

int					empty_line_check(const char *line);
int					get_map(t_lem_in *l_i, int i);
int					link_or_room(t_lem_in *l_i, const char *line, int flag);
int					coord_valid(t_lem_in *l_i, char **str, int n);
int					get_room(t_lem_in *l_i, char *line, int i, int j);
int					get_command(t_lem_in *l_i, char **line, int i);
t_lem_in			*init_l_i(void);
t_room				*init_room(void);
char				**init_link_arr(t_lem_in *l_i);
int					same_name_and_coord_valid(t_lem_in *l_i);
int					is_link(t_lem_in *l_i, int j, int k);
int					room_num_check(t_lem_in *l_i, int i);
int					get_end_or_start_room(t_lem_in *l_i, char **str, int i);
int					start_end_room_check(t_lem_in *l_i, int i, char **str);
int					many_dashes_link(t_lem_in *l_i, const char *line, int i);
void				level_correction(t_lem_in *l_i, int flag, int k, int i);
int					str_free(char **str, int i);
int					buff_free(char *buff);
int					error(int flag, char **str);
int					free_len(int *len);

/*
** queue functions
*/

t_queue				*new_queue_node(t_room *room);
void				push_node(t_queue **queue, t_queue *node);
t_room				*pop_node(t_queue **queue);
void				free_queue(t_queue **queue);

int					start_algo(t_lem_in *lem_in);

/*
** operations with paths
*/

void				sort_paths(t_path **paths, int right);
void				define_comp_num(t_path **paths, int num);
t_path				*create_path(t_room *head, int len);
void				add_path(t_path **paths, t_path *new);
int					does_path_end(t_lem_in *lem_in, int room_id);
t_path				**pathfinder(t_lem_in *lem_in);

/*
** edmonds-karp
*/

int					edmonds_karp(t_lem_in *lem_in);
void				find_path_backwards(t_lem_in *lem_in, int room_id);
void				refresh_visited_and_lvl(t_room **rooms, int num);
int					find_level(t_lem_in *lem_in, int prev, int curr);
t_room				*find_last_room(t_room *head);
int					count_turns(t_lem_in *l_i);
void				set_true_prev(t_lem_in *lem_in);
void				set_optimal_path(t_lem_in *lem_in, int n_new);

/*
** move ants
*/

t_room				*find_last_room(t_room *head);
void				move_all_in_path(t_lem_in *l_i, t_room *room, int *is_start,
int even);
void				move_ants(t_lem_in *lem_in);
void				free_paths(t_path **paths, int num);
int					free_all(t_lem_in **lem_in);

#endif
