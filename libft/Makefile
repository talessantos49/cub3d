NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g3

SRC = 	ft_atoi.c \
		ft_itoa.c \
		ft_toupper.c \
		ft_calloc.c \
		ft_bzero.c \
		ft_isdigit.c \
		ft_strlen.c \
		ft_strjoin.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strnstr.c \
		ft_strtrim.c \
		ft_strncmp.c \
		ft_strchr.c \
		ft_split.c \
		ft_memset.c \
		ft_memcpy.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_lstlast.c \
		ft_lstnew.c \
		ft_lstclear.c \
		ft_printf.c \
		ft_printf_other_convs.c \
		ft_printf_int_convs.c

OBJ=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -r $(NAME) $(OBJ)

%.o: %.c ../includes/libft.h 
	@$(CC) $(CFLAGS) -c $< -I../includes -o $@

re: fclean all

fclean: clean
	rm -rf $(NAME)

clean:
	rm -rf *.o
