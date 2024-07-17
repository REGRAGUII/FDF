CC = cc
NAME = fdf
# CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = Libft
FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit
LIBS = -L$(LIBFTDIR) -lft -Lmlx -lmlx -framework OpenGL -framework AppKit
SRCS = \
		fdf.c \
		./source/errors.c \
		./source/get_map.c \
		./source/get_next_line.c \
		./source/get_next_line_utils.c \
		# ./Libft/Libft.a \

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
