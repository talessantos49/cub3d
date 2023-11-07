NAME=cub3d

CCW=cc 

W_FLAGS=-Wall -Werror -Wextra

MAKE_LIBFT = libft.a

SRC =	cub3d.c \
		cub3d_read_map.c \
		cub3d_map_rules.c \
		cub3d_mlx_utils.c \
		bresenham_algorithm.c \
		cub3d_ray_casting.c \
		cub3d_window.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MAKE_LIBFT)
	$(CC) $(WFLAGS) $(OBJ) -L ./ -lft -L./ -lmlx -L./ -lX11 -L./ -lXext -o $(NAME)

%.o: %.c
	$(CCW) -g3 $(FLAGS) -c $< -o $@

$(MAKE_LIBFT):
	make -C libft/

re: fclean all

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o
	rm -rf libft/*.o
	rm -rf libft.a

.PONHY: re fclean clean all
