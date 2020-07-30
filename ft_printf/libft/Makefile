# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaveric <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/06 19:36:08 by emaveric          #+#    #+#              #
#    Updated: 2020/07/30 11:54:23 by eshor            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_div_mod.c ft_is_whitespaces.c ft_isalnum.c \
	  ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
	  ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	  ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	  ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c \
	  ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	  ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_recursive_factorial.c \
	  ft_sqrt.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	  ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	  ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	  ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	  ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
	  ft_strtrim.c ft_swap.c ft_tolower.c ft_toupper.c ft_num_to_str.c \
	  ft_numlen.c ft_num_to_str.c ulltoa_base.c ft_isnan.c number_len_ll.c \
	  ft_isinf.c ft_lltoa.c ft_putnbr_max.c number_len_ull.c to_uppercase.c \
	  ft_pow.c ft_ulltoa.c ft_is_minus_inf.c ft_pow_double.c ft_atoi_base.c \
	  ft_clear_table.c ft_countwords.c ft_llutoa.c ft_strcmp_free.c \
	  ft_strcut.c ft_strjoin_free.c ft_strncut.c itoa_base.c ft_free.c \
	  get_next_line.c ft_atoi_int_max.c ft_check_space.c ft_strfromcpy.c \

HEADER = libft.h

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(HEADER) $(OBJ)
				@gcc $(FLAGS) -I $(HEADER) -c $(SRC)
				ar rc $(NAME) $(OBJ)
				ranlib $(NAME)

clean:
				rm -rf $(OBJ)

fclean: clean
				rm -rf $(NAME)
				rm -rf $(OBJ)

re: fclean all