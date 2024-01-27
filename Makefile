# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 18:58:22 by tasantos          #+#    #+#              #
#    Updated: 2024/01/26 23:20:09 by tasantos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=cub3d

HEADERS_DIR		= ./includes/
SOURCES_DIR		= ./source/

HEADERS_LIST	= cub3d.h \
				cub3d_parser.h \
				cub3d_window.h \
				cub3d_move_camera.h \
				cub3d_rays.h \

SOURCES_LIST	= cub3d.c \
		cub3d_read_map.c \
		cub3d_map_rules.c \
		cub3d_mlx_utils.c \
		cub3d_utils.c \
		cub3d_player.c \
		cub3d_move_camera.c \
		cub3d_draw_line.c \
		check_floor.c \
		check_textures_path.c \
		clear.c \
		clear_utils.c \
		cub3d_check_wall.c \
		cub3d_ray_casting.c \
		cub3d_ray_utils.c \
		cub3d_draw.c \
		cub3d_draw_scenario.c \
		cub3d_draw_scenario_utils.c \
		cub3d_debug_util.c \
		cub3d_check_collition.c \
		cub3d_window.c \
		cub3d_segregation.c \
		parser_map.c \
		parser_texture.c \
		cub3d_init_textures.c \
		cube3d_draw_texture.c

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
LIBRARIES		= -lmlx -lXext -lX11 -lm

RM 				= rm -f

VALGRIND		= @valgrind --leak-check=full --show-leak-kinds=all \
--track-origins=yes --quiet --tool=memcheck --keep-debuginfo=yes --verbose \
--log-file=valgrind-out.txt

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
		$(VALGRIND) ./cub3d maps/map_second_example.cub

valgrind2:
		$(VALGRIND) ./cub3d maps/big_maze.cub

clean:
			make -sC ${LIBFT_DIR} clean
			rm -rf ${OBJECTS_DIR}

fclean:		clean
			${RM} ${LIBFT}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all, clean, fclean, re
