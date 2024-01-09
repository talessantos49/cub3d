# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: root <root@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 18:58:22 by tasantos          #+#    #+#              #
#    Updated: 2023/11/19 21:37:36 by root             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3d

HEADERS_DIR		= ./includes/
SOURCES_DIR		= ./source/

HEADERS_LIST	= cub3d.h \
				cub3d_window.h \
				cub3d_rays.h

SOURCES_LIST	= cub3d.c \
		cub3d_read_map.c \
		cub3d_map_rules.c \
		parser_map.c \
		clear.c \
		parser_texture.c
		# cub3d_mlx_utils.c \
		bresenham_algorithm.c \
		cub3d_ray_casting.c \
		cub3d_window.c \

GREEN			= \033[0;32m

RESET_COLOR		= \033[0m

HEADERS			= ${addprefix ${HEADERS_DIR}, ${HEADERS_LIST}}
SOURCES			= ${addprefix ${SOURCES_DIR}, ${SOURCES_LIST}}
INCLUDES		= -I ${HEADERS_DIR} -I ${LIBFT_HEADERS}

OBJECTS_DIR		= ./objects/
OBJECTS_LIST	= ${patsubst %.c, %.o, ${SOURCES_LIST}}
OBJECTS			= ${addprefix ${OBJECTS_DIR}, ${OBJECTS_LIST}}

LIBFT_DIR		= ./libft/
LIBFT_HEADERS	= ${LIBFT_DIR}includes/
LIBFT			= ${LIBFT_DIR}libft.a

CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -g3
LIBRARIES		=
#  -lmlx -lXext -lX11

RM 				= rm -f

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes --verbose \
--log-file=valgrind-out.txt

# $(NAME): $(OBJ) $(MAKE_LIBFT)
# 	$(CC) $(WFLAGS) $(OBJ) -L ./ -lft -L./ -lmlx -L./ -lX11 -L./ -lXext -o $(NAME)

# %.o: %.c
# 	$(CCW) -g3 $(FLAGS) -c $< -o $@


all:			${NAME}
				@echo "$(GREEN)Cub3D Was compiled!"
				@echo "Lets Play!$(RESET_COLOR)"

${NAME}:		${LIBFT} ${OBJECTS_DIR} ${OBJECTS}
			${CC} ${CFLAGS} ${SOURCES} ${LIBFT} ${LIBRARIES} ${INCLUDES} -o ${NAME}

${OBJECTS_DIR}:
			mkdir -p ${OBJECTS_DIR}
			@echo Objects folder has been created!

${OBJECTS_DIR}%.o : ${SOURCES_DIR}%.c ${HEADERS}
			${CC} ${CFLAGS} -c ${INCLUDES} $< -o $@
			@echo Library created!

${LIBFT}:
			make -sC ${LIBFT_DIR}
			@echo Libft has been compiled!

valgrind:
		$(VALGRIND) ./cub3d maps/map_example.cub

clean:
			make -sC ${LIBFT_DIR} clean
			rm -rf ${OBJECTS_DIR}

fclean:		clean
			${RM} ${LIBFT}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all, clean, fclean, re
