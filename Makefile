NAME=cub3d

CCW=cc 

W_FLAGS=-Wall -Werror -Wextra

MAKE_LIBFT = libft.a

SRC =	cub3d.c \
		cub3d_map_rules.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MAKE_LIBFT)
	# $(CC) $(WFLAGS) $(OBJ) -L ./ -lft -L./ -lmlx -L./ -lX11 -L./ -lXext -o $(NAME) --> comeentado enquanto nao add libmlx 
	$(CC) $(WFLAGS) $(OBJ) -L ./ -lft -o $(NAME)

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
