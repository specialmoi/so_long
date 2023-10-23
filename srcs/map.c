/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 11:48:24 by pthiruma          #+#    #+#             */
/*   Updated: 2023/10/18 11:42:18 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

/* check for valid chars and valid width (rectangle) */
static void ft_parsemap_chars(t_game *game, t_map *m)
{
	int	i;
	int	j;

	i = 0;

	while (m->lines[i])
	{
		j = 0;
		while (m->lines[i][j])
		{
			if ((i == 0 || i == m->height - 1 || j == 0 || j == m->width - 1) && m->lines[i][j] != WALL)
			{
				ft_error_end(ERR_WALL, game);
			}
			else if (m->lines[i][j] == PLAYER)
				m->player++;
			else if (m->lines[i][j] == COLLECTIBLES)
				m->collectibles++;
			else if (m->lines[i][j] == EXIT)
				m->exit++;
			else if (m->lines[i][j] != EMPTY_SPACE && m->lines[i][j] != WALL)
				ft_error_end(ERR_CONT, game);
			j++;
		}
		if (m->width != j)
			ft_error_end(ERR_RECT, game);
		i++;
	}
}


/* check if right number of chars */
static void ft_parsemap_validator(t_game *game, t_map *m)
{
	if (m->collectibles == 0)
		ft_error_end(ERR_COLLECT, game);
	if (m->player != 1)
		ft_error_end(ERR_PLAYER, game);
	if (m->exit != 1)
		ft_error_end(ERR_EXIT, game);
}

/* fill with X */
static void flood_fill(char **map, t_game *g, int x, int y)
{
	if (x < 0 || y < 0 || y >= g->map->height || x >= g->map->width
		|| (map[y][x] != EMPTY_SPACE && map[y][x] != PLAYER
		&& map[y][x] != COLLECTIBLES && map[y][x] != EXIT))
		return ;
	map[y][x] = 'X';
	flood_fill(map, g, x + 1, y);
	flood_fill(map, g, x - 1, y);
	flood_fill(map, g, x , y + 1);
	flood_fill(map, g, x , y - 1);
}

/* determine player pos, do and check if flood_fill is right */
static void	ft_parsemap_path(t_game *game, t_map *m)
{
	int	i;
	int	j;
	
	//check player position
	i = 0;
	while (m->lines[i])
	{
		j = 0;
		while (m->lines[i][j])
		{
			if(m->lines[i][j] == PLAYER)
			{
				game->player_pos.y = i;
				game->player_pos.x = j;
				break ;
			}
			j++;
		}
		i++;
	}
/* 	do flood fill */
	flood_fill(m->lines_copy, game, game->player_pos.x, game->player_pos.y);
/* check flood fill result */
	i = 0;
	while (m->lines_copy[i])
	{
		j = 0;
		while (m->lines_copy[i][j])
		{
			if(m->lines_copy[i][j] != 'X' && m->lines_copy[i][j] != WALL)
				ft_error_end(ERR_PATH, game);
			j++;
		}
		i++;
	}
}

/* checks .ext and parse map */
void ft_parsemap(char *file_name, t_game *game)
{
	char *ext;
	char *content;
	
	ext = ft_strrchr(file_name, '.');
	if (!ext || ft_strncmp(ext, FILE_EXT, ft_strlen(FILE_EXT)))
		ft_error_end(ERR_EXT, game);
	content = ft_read_file(file_name);
	if (!content)
	{
		ft_putendl_fd(ERR_MSG, STD_ERR);
		perror(ERR_OPEN);
		free(game->map);
		exit(EXIT_FAILURE);
	}
	if (!*content)
		ft_error_end(ERR_CONT, game);
	game->map->lines = ft_split(content, '\n');
	game->map->lines_copy = ft_split(content,'\n');
	free(content);
	game->map->width = ft_strlen(game->map->lines[0]);
	game->map->height = ft_collen(game->map->lines);
	ft_parsemap_chars(game, game->map);
	ft_parsemap_validator(game, game->map);
	ft_parsemap_path(game, game->map);
}
