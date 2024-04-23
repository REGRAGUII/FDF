CC = cc
NAME = fdf
CFLAGS = -Wall -Wextra 
LIBFTDIR = Libft
FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBS = -L$(LIBFTDIR) -lft -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS = \
		fdf.c \
		./error/errors.c \

EXEC = fdf

all:
	$(CC) $(FLAGS) $(CFLAGS) -L$(LIBFTDIR) -lft $(SRCS) -o $(NAME)



%.o: %.c
	$(CC) $(CFLAGS) -I$(LIBFTDIR)  -I$(MLXDIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re