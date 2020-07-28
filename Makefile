# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/23 16:43:36 by emaveric          #+#    #+#              #
#    Updated: 2020/07/28 16:59:58 by eshor            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEM-IN = lem-in

HEADER_NAME = lem-in.h
PRINTF_A = ft_printf/libftprintf.a

INC_DIR = ./includes/
INC_PRINTF = ./ft_printf/includes/
SRC_DIR = ./src/
OBJ_DIR = ./obj/

SRC_NAME =	lem-in.c init.c get_room.c map.c validation.c check.c move_ants.c \
			many_dashes_link.c bfs.c aux.c counts_links.c form_paths.c \
			improve_links.c delete_links.c start_algo.c queue_funcs.c \
			begin_delete.c delete_input_forks.c

HEADER = $(addprefix $(INC_DIR), $(HEADER_NAME))

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

FLAGS =
GCC_PRINTF = -L ./ft_printf -l ftprintf

all: $(LEM-IN)

$(LEM-IN): $(OBJ_DIR) $(OBJ) $(PRINTF_A) $(HEADER)
	gcc $(GCC_PRINTF) $(addprefix -I, $(INC_DIR)) $(OBJ) $(FLAGS) -o $(LEM-IN)

$(OBJ_DIR):
	@mkdir -p obj

$(PRINTF_A):
	make -C ft_printf/

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	gcc -c -I $(INC_DIR) -I $(INC_PRINTF) $(FLAGS) $< -o $@

clean:
	make -C ./ft_printf clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C ./ft_printf fclean
	rm -f $(LEM-IN)

re: fclean all