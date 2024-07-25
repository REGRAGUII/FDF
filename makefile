CC = cc -g -fsanitize=address
# CFLAGS = -Wall -Wextra -Werror
LIBFTDIR = Libft
MLXFLAGS = -Lminilibx-linux -lmlx_Linux -Iminilibx-linux -lXext -lX11 -lm -lz


SRCS = \
		fdf.c \
		./source/errors.c \
		./source/get_map.c \
		./source/get_next_line.c \
		./source/get_next_line_utils.c \
		./source/draw.c \

EXEC = fdf

OBJS = $(SRCS:.c=.o)



all:	${EXEC}

${EXEC}: $(OBJS)
	make -C Libft --silent
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS)  -L$(LIBFTDIR) -lft  -o $(EXEC)


%.o: %.c
	$(CC) $(CFLAGS)   -c $< -o $@
	

clean:
	make clean -C Libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C Libft
	rm -f $(EXEC)

re: fclean all

.PHONY: all clean fclean re