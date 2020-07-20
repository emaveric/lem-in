/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 15:55:05 by emaveric          #+#    #+#             */
/*   Updated: 2020/02/25 15:50:15 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BF_SIZE 60

# define RED "\x1B[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE "\x1b[34m"
# define PURPLE "\x1b[35m"
# define LIGHT_BLUE "\x1b[36m"
# define GRAY "\x1b[37m"
# define RESET "\x1b[0m"

# define B_BLACK "\x1b[40m"
# define B_RED "\x1b[41m"
# define B_GREEN "\x1b[42m"
# define B_YELLOW "\x1b[43m"
# define B_BLUE "\x1b[44m"
# define B_PURPLE "\x1b[45m"
# define B_LIGHT_BLUE "\x1B[46m"
# define B_GRAY "\x1B[47m"

# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include <limits.h>
# include <math.h>

typedef struct			s_float
{
	unsigned long long	first;
	unsigned long long	second;
	unsigned long long	i;
	unsigned long long	pos;
	char				*tmp;
	char				*res;
	char				*scnd;
	char				*frst;
	int					not_f;
	int					flag;
}						t_float;

union					u_number
{
	int					i;
	long long int		lli;
	unsigned long long	ulli;
	long double			ld;
	char				c;
	char				*str;
}						;

typedef struct			s_pf
{
	char				*flags;
	int					width;
	int					precision;
	int					prec_width;
	char				*size;
	char				type;
	int					str_len;
	char				*str;
	int					percent;
	int					counter;
	int					symbol;
	int					symb_width;
	char				*sharp;
	int					plus;
	int					minus;
	int					space;
	char				*tmp_oxfs;
	int					num_len;
	union u_number		num;
	int					dot;
	int					float_dot;
	char				buff[BF_SIZE];
	int					buf_len;
}						t_pf;

int						ft_printf(const char *format, ...);
int						new_str(t_pf *pf, char **p);
int						pf_format(t_pf *pf, char **p, va_list ap);
int						is_flags(char *p);
void					find_flags(t_pf *pf, char **p);
int						is_width(char *p);
void					find_width(t_pf *pf, char **p);
int						is_precision(char **p, t_pf *pf);
void					find_precision(t_pf *pf, char **p);
int						is_size(char *p);
void					find_size(t_pf *pf, char **p);
int						parse_format(t_pf *pf);
int						find_str_size(t_pf *pf);
void					fillbuff(t_pf *pf, char **p);
void					fill_string(t_pf *pf, char **p);
void					check_buf(t_pf *pf, char **p);
char					*find_tmp(t_pf *pf);
int						fill_final(t_pf *pf, char *str, int n, int len);
int						display_f(t_pf *pf);
char					*pf_itoa(unsigned long long n);
unsigned long long		ft_len_of_number(unsigned long long n);
char					*pf_strcpy(char *dst, const char *src, int j);
char					*add_null(t_pf *pf, t_float *fl, int what);
void					real_rounding(t_float *fl, t_pf *pf, long double num);
char					*rounding(long double num, unsigned long long i,
													t_float *fl, int prec);
void					free_t_float(t_float *fl);
char					*make_decimal(t_float *fl, t_pf *pf);
void					fill_char_from_int(unsigned long long what,
															char *where);
char					*init_memory_for_decimal(t_pf *pf, t_float *fl);
void					float_string_helper(t_float *fl, t_pf *pf,
															long double num);
char					*put_in_str(t_pf *pf, t_float *fl, long double num);
t_float					*init_t_float(void);
void					free_t_pf(t_pf *pf, int n);
void					free_chars(t_pf *pf);
void					fill_with_symb(char *str, int *i, char c, int len);
void					fill_with_sharp(t_pf *pf, char *str, int *i);

#endif
