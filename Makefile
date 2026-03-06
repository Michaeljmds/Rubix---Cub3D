# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shhidrob <shhidrob@student.42london.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 17:11:10 by mimacdou          #+#    #+#              #
#    Updated: 2026/03/06 22:22:34 by shhidrob         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
FLAGS = -Wall -Wextra -Werror -I./minilibx-linux -g3 -O0
LIBFT = Libft/libft.a
LIBMLX = minilibx-linux/libmlx.a

SRC = 								\
		main						\
		check_args					\
		input_content_checks		\
		extra_input_content_checks	\
		ex_ex_input_content_checks	\
		additional_rgb_checks		\
		map_checks					\
		extra_map_checks			\
		check_utils					\
		janitor						\
		src/render/test_mlx \
		src/render/exit \
		src/render/hooks \
		src/render/mlx_init \
		src/render/render \

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

HEADERS = cub3D.h

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
		$(MAKE) -C Libft FLAGS="$(FLAGS)"

$(LIBMLX):
		$(MAKE) -C minilibx-linux


$(NAME): $(LIBFT) $(LIBMLX) $(OBJS) $(HEADERS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) \
		-L ./minilibx-linux $(LIBMLX) -lmlx -lX11 -lXext -lm

clean:
	rm -f *.o src/render/*.o
	$(MAKE) -C Libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re
