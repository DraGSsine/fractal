# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: youchen <youchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 20:58:54 by youchen           #+#    #+#              #
#    Updated: 2024/01/08 14:45:41 by youchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
OBJS = fractol.o mlx.o utilities.o
CFLAGS = -Wall -Wextra -Werror
CC = cc
MLX = -lmlx -framework OpenGL -framework AppKit

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS)  -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -Imlx -c $<

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all
