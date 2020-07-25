/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 22:50:49 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 16:06:52 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFF_SIZE 10

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <fcntl.h>

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
int					ft_atoi(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
int					ft_strncmp(const char *s1, const char *s2, size_t len);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strrchr(const char *str, int n);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_putstr(char const *s1);
void				ft_putchar(char c);
void				ft_putnbr(int n);
char				*ft_strnew(size_t size);
void				*ft_memalloc(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_itoa(int n);
void				ft_putendl(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*
ft_strnstr(const char *haystack, const char *needle, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_memdel(void **ap);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_swap(int *a, int *b);
int					ft_sqrt(int nb);
void				ft_div_mod(int a, int b, int *div, int *mod);
int					ft_recursive_factorial(int nb);
int					ft_is_whitespaces(char c);
int					ft_numlen(int num);
char				*ft_num_to_str(int num);
char				*ulltoa_base(unsigned long long int value,
					int base);
int					ft_isnan(long double num);
int					number_len_ll(long long n);
int					ft_isinf(long double num);
char				*ft_lltoa(long long int n);
void				ft_putnbr_max(long long int nb);
int					number_len_ull(unsigned long long n);
char				*to_uppercase(char *str);
unsigned long long	ft_pow(unsigned long long n, unsigned long long pow);
char				*ft_ulltoa(unsigned long long int n);
int					ft_is_minus_inf(long double num);
long double			ft_pow_double(long double n, unsigned long long pow);
int					ft_atoi_base(const char *str);
void				*ft_clear_table(char **tables, int i);
int					ft_countwords(char const *str, char c);
char				*ft_llutoa(unsigned long long int n);
int					ft_strcmp_free(char *s1, char *s2, int opt);
char				*ft_strcut(const char *s, int c);
char				*ft_strjoin_free(char *s1, char *s2, int opt);
char				*ft_strncut(char *s, int start, int end);
char				*itoa_base(int value, int base);
void				ft_free(char **res, size_t i);
int					get_next_line(const int fd, char **line);
int					ft_atoi_max_int(int *n, const char *str);
int					ft_check_space(const char *line);

#endif
