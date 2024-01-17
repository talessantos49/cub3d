/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tasantos <tasantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:33:46 by tasantos          #+#    #+#             */
/*   Updated: 2024/01/16 19:09:34 by tasantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSER_H
# define CUB3D_PARSER_H
# define  STR_SPACES 	" \t\r\f\v\n"

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_fase
{
	int	floor;
	int	ceiling;
	int	map;
	int	no_texture;
	int	so_texture;
	int	we_texture;
	int	ea_texture;
	int	player;
	int	attributes;
	int	completed;
}	t_fase;

typedef struct s_map
{
	char	**map;
	char	**original;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	int		n_row;
	int		n_col;
	t_fase	fase;
	t_color	floor;
	t_color	ceiling;
}	t_map;

typedef struct Node {
	char			key;
	int				value;
	struct Node		*next;
}	Node;

int		parser_map_north(char *line);
int		parser_map(char *path_map, t_map *map);
int		parser_map_south(char *line);
int		parser_map_west(char *line);
int		parser_map_east(char *line);
int		comma_check(char *line, char constant);
char	*ft_strjoin_gnl(char *string1, const char *string2);
char	*is_spaces(char *line, char *spaces);
void	around_map(t_map *map, int len, int row, int k);
void	check_rgb_and_split(char *line, t_map *map, char constant, char type);
void	clean_before_exit(char *message, int fd);
void	clean_str_exit(char	*str, char *line, int error);
void	initialize_map(t_map *map);
void	parser_atributes(t_map *map, char *line);
void	parser_map_floor(char *line, t_map *map);
void	parser_map_ceiling(char *line, t_map *map);

#endif