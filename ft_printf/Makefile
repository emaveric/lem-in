# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/06 17:02:06 by emaveric          #+#    #+#              #
#    Updated: 2020/03/02 16:51:13 by emaveric         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILES = check_is.c fill_final.c fill_find_other.c fill_new_str.c \
        find_mod.c find_str_size.c float_maker.c float_new_free.c \
        float_put.c floats.c ft_printf.c parse_format.c pf_format.c \
        pf_free.c pf_libft.c print_check.c

SRC = $(addprefix src/, $(FILES))

INC = includes/ft_printf.h

OBJ = $(addprefix obj/, $(FILES:.c=.o))

LIBFT = libft/libft.a

LIBFT_DIR = libft/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

lib:
	@make -C $(LIBFT_DIR)

obj:
	mkdir -p obj/

obj/%.o: src/%.c | obj
	gcc $(FLAGS) -I $(INC) -o $@ -c $<

$(NAME): $(OBJ) lib
	@cp $(LIBFT) $(NAME)
	@ar rc $(NAME) $(OBJ)

clean:
	make -C $(LIBFT_DIR) fclean
	rm -rf $(OBJ)
	rm -rf ./obj

fclean: clean
	make -C $(LIBFT_DIR) fclean
	/bin/rm -rf $(NAME)
	rm -rf ./obj

re: fclean all