# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/23 17:11:10 by mimacdou          #+#    #+#              #
#    Updated: 2026/02/24 20:10:32 by mimacdou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc
FLAGS = -Wall -Wextra -Werror -I./minilibx-linux
LIBFT = Libft/libft.a
LIBMLX = minilibx-linux/libmlx.a

SRC = 								\
		main						\
		check_args					\
		input_content_checks		\
		extra_input_content_checks	\
		ex_ex_input_content_checks	\

SRCS = $(addsuffix .c, $(SRC))
OBJS = $(addsuffix .o, $(SRC))

HEADERS = cub3D.h

%.o: %.c $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(LIBFT):
		@$(MAKE) -C Libft FLAGS=$(FLAGS)

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
		$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) \
		-L ./minilibx-linux $(LIBMLX) -lmlx -lX11 -lXext -lm

clean:
	rm -f *.o
	$(MAKE) -C Libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C Libft fclean

re: fclean all

.PHONY: all clean fclean re