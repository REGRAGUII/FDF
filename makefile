CC = cc
NAME = fdf
CFLAGS = -Wall -Wextra -fsanitize=address -g3
LIBFTDIR = Libft
FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBS = -L$(LIBFTDIR) -lft -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS = \
		./source/fdf.c \
		./source/errors.c \
		./source/get_map.c \
		./Libft/Libft.a \
		./source/get_next_line.c \
		./source/get_next_line_utils.c \

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
