# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/22 10:22:50 by root              #+#    #+#              #
#    Updated: 2025/07/22 22:50:49 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
MLX_DIR = 
MLX = $(MLX_DIR)/libmlx.a
LIBS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm -lbsd
SRCS = utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)
.PHONY: all clean fclean re
$(MLX):
	make -C $(MLX_DIR)

$(NAME): $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)

re: fclean all
