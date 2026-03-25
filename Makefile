# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moik <moik@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 17:11:10 by mimacdou          #+#    #+#              #
#    Updated: 2026/03/25 19:40:16 by moik             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
FLAGS = -Wall -Wextra -Werror -I./minilibx-linux -g3 -O0
LIBFT = Libft/libft.a
FRAMEWORKS = -lXext -lX11 -lm
#FRAMEWORKS = -L ./minilibx -lmlx -lmlx_Linux -L/usr/lib/X11 -LXext -LX11 -lm
MLX_PATH = ./minilibx-linux
MLX = $(MLX_PATH)/libmlx.a
SRC = \
		main \
		src/arg_checks/check_args \
		src/arg_checks/input_content_checks	\
		src/arg_checks/extra_input_content_checks \
		src/arg_checks/ex_ex_input_content_checks \
		src/arg_checks/additional_rgb_checks \
		src/arg_checks/map_checks \
		src/arg_checks/extra_map_checks	\
		src/arg_checks/check_utils \
		src/parsing/first \
		janitor	\
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

$(MLX):
		$(MAKE) -C minilibx-linux

#$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
#		$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)
#		-L $(MLX) $(FRAMEWORKS)

$(NAME): $(LIBFT) $(MLX) $(OBJS)
		$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(MLX) $(FRAMEWORKS) -o $(NAME)

clean:
	rm -f *.o src/*/*.o
	$(MAKE) -C Libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re
