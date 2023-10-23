/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:57:58 by pthiruma          #+#    #+#             */
/*   Updated: 2023/10/18 11:45:52 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "../libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

# define ERR_MSG "Error!\n"
# define ERR_ARG "Invalid number of arguments: requires 1 (map path)"
# define ERR_EXT "Invalid map: wrong file extension (requires .ber)"
# define ERR_OPEN "Invalid file: cannot read map"
# define ERR_CONT "Invalid map: invalid chars in map"
# define ERR_WALL "Invalid map: needs to be surrounded by wall"
# define ERR_RECT "Invalid map: not a rectangle"
# define ERR_COLLECT "Invalid map: no collectibles"
# define ERR_PLAYER "Invalid map: not 1 player"
# define ERR_EXIT "Invalid map: not 1 exit"
# define ERR_PATH "Invalid map: no valid path"
# define ERR_TERM "Ended the pogram though Esc"|| i == m->height - 1 || j == 0 || j == m->width - 1

# define FILE_EXT 		".ber"
# define PLAYER  		'P'
# define COLLECTIBLES	'C'
# define EMPTY_SPACE 	'0'
# define WALL			'1'
# define EXIT			'E'
# define STD_ERR 		2
# define STD_OUT 		1
# define SUCCESS 		0
# define FAILURE 		1

# define IMG_WALL "./png/wall.png"
# define IMG_FLOOR "./png/floor.png"
# define IMG_EXIT "./png/exit.png"
# define IMG_COLLECTIBLE "./png/collectible.png"
# define IMG_PLAYER "./png/player.png"

typedef struct t_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_map
{
	char	**lines;
	char	**lines_copy;
	int		width;
	int		height;
	int		collectibles;
	int		player;
	int		exit;
	
}				t_map;

typedef struct s_game
{
	mlx_t		*mlx;
	t_map		*map;
	t_pos		player_pos;
	mlx_image_t	*img_player;
	mlx_image_t	*img_floor;
	mlx_image_t	*img_exit;
	mlx_image_t	*img_collectibles;
	mlx_image_t	*img_wall;
	int32_t		player_id;
	int32_t		collected;
	int32_t		movement;
}				t_game;

/* error */
void ft_error_end(const char *msg, t_game *game);

/* action */
void ft_collectibles(t_game *g);
void	ft_move(t_game *g, int x, int y);
void ft_free_map(t_map *map);

/* parsemap */
void ft_parsemap(char *file_name, t_game *game);

/* mlx_hook */
void	ft_close_hook(void *param);
void ft_key_hook(mlx_key_data_t keydata, void *param);


#endif