NAME = fractol
OBJS = fractol.o
CFLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJS)
	$(CC) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all
