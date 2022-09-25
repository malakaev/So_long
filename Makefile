# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgolda <kgolda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/11 21:15:13 by kgolda            #+#    #+#              #
#    Updated: 2021/12/30 18:27:21 by kgolda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

SRCS =	./srcs/so_long.c\
		./srcs/ft_put_img_bigmap.c\
		./srcs/exit_functions.c\
		./srcs/init_map.c\
		./srcs/read_map.c\
		./srcs/gnl_for_sl.c\
		./srcs/put_img_map.c\
		./srcs/key_actions.c\
		./srcs/ft_game_end.c\
		./srcs/allocation_memory.c\
		./srcs/render_maps.c\
		./srcs/ft_int_to_char.c\

SRCS_BONUS =	./srcs_bonus/so_long_bonus.c\
				./srcs_bonus/ft_put_img_bigmap_bonus.c\
				./srcs_bonus/exit_functions_bonus.c\
				./srcs_bonus/init_map_bonus.c\
				./srcs_bonus/read_map_bonus.c\
				./srcs_bonus/gnl_for_sl_bonus.c\
				./srcs_bonus/put_img_map_bonus.c\
				./srcs_bonus/key_actions_bonus.c\
				./srcs_bonus/ft_game_end_bonus.c\
				./srcs_bonus/allocation_memory_bonus.c\
				./srcs_bonus/puts_info_on_table_bonus.c\
				./srcs_bonus/patrol_move_bonus.c\
				./srcs_bonus/render_maps_bonus.c\
				./srcs_bonus/ft_int_to_char_bonus.c\

OBJ = $(SRCS:.c=.o)
OBJ_BONUS = $(SRCS_BONUS:.c=.o)

OBJ_DIR			= srcs/
OBJ_BONUS_DIR	= srcs_bonus/

HEADER = ./srcs/so_long.h
HEADER_BONUS = ./srcs_bonus/so_long_bonus.h

CC = gcc

INCLUDES=libmlx.a


# CFLAGS = -g -fsanitize=address
CFLAGS = -Wall -Werror -Wextra
# CFLAGS = -Wall -Werror -Wextra -I./srcs/$(HEADER)
# CFLAGS_BONUS = -Wall -Werror -Wextra -I./srcs_bonus/$(HEADER_BONUS)

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

RM = rm -f

# only for MacOS graphics.
$(NAME): $(OBJ) $(HEADER)
	$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJ_BONUS) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(MLX_FLAGS) -o $(NAME_BONUS)

$(OBJ_DIR)%.o: 	$(OBJ_DIR)%.c $(HEADER)
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)%.o: 	$(OBJ_BONUS_DIR)%.c $(HEADER_BONUS)
						$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(NAME_BONUS)
bonus: $(NAME_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

rebonus: fclean bonus

.PHONY: all bonus clean fclean re rebonus
