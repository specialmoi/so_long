/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 21:46:24 by pthiruma          #+#    #+#             */
/*   Updated: 2023/10/18 13:14:20 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static void game_init(t_game *game)
{
	game->map = (t_map *)malloc(sizeof(t_map));
	if (!game->map)
		exit(EXIT_FAILURE);
	ft_bzero(game->map, sizeof(t_map));
	game->mlx = NULL;
	game->collected = 0;
	game->movement = 0;
}

/* save texture of image and then assign to mlx_image_t */
static void load_image_texture (t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(IMG_PLAYER);
	game->img_player = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(IMG_EXIT);
	game->img_exit = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(IMG_COLLECTIBLE);
	game->img_collectibles = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(IMG_WALL);
	game->img_wall = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(IMG_FLOOR);
	game->img_floor = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}

/* fill in the map with the images saved in mlx_image_t */
static void image_to_window(t_game *g)
{
	/* int	i;
	int	j;

	i = 0;
	while (g->map->lines[i])
	{
		j = 0;
		while (g->map->lines[i][j])
		{
			if (g->map->lines[i][j] == PLAYER)
				mlx_image_to_window(g->mlx, g->img_player, j * 32, i * 32);
			if (g->map->lines[i][j] == WALL)
				mlx_image_to_window(g->mlx, g->img_wall, j * 32, i * 32);
			if (g->map->lines[i][j] == COLLECTIBLES)
				mlx_image_to_window(g->mlx, g->img_collectibles, j * 32, i * 32);
			if (g->map->lines[i][j] == EXIT)
				mlx_image_to_window(g->mlx, g->img_exit, j * 32, i * 32);
			if (g->map->lines[i][j] == EMPTY_SPACE)
				mlx_image_to_window(g->mlx, g->img_floor, j * 32, i * 32);
			j++;
		}
		i++;
	} */
	int	x;
	int	y;

	y = -1;
	while (g->map->lines[++y])
	{
		x = -1;
		while (g->map->lines[y][++x])
		{
			if (g->map->lines[y][x] == WALL)
				mlx_image_to_window(g->mlx, g->img_wall, x * 32, y * 32);
			else
				mlx_image_to_window(g->mlx, g->img_floor, x * 32, y * 32);
			if (g->map->lines[y][x] == COLLECTIBLES)
				mlx_image_to_window(g->mlx, g->img_collectibles, x * 32, y * 32);
			if (g->map->lines[y][x] == EXIT)
				mlx_image_to_window(g->mlx, g->img_exit, x * 32, y * 32);
		}
	}
	mlx_image_to_window(g->mlx, g->img_player, g->player_pos.x * 32, \
		g->player_pos.y * 32);
}

int main(int argc, char **argv)
{
	t_game game;
	
	if (argc != 2)
		ft_error_end(ERR_ARG, NULL);
	game_init(&game);
	ft_parsemap(argv[1], &game);
	game.mlx = mlx_init(game.map->width * 32, game.map->height * 32, "so_long", false);
	if (!game.mlx)
		ft_error_end(mlx_strerror(mlx_errno), &game);
	load_image_texture(&game);
	image_to_window(&game);
	mlx_key_hook(game.mlx, &ft_key_hook, &game);
	mlx_close_hook(game.mlx, &ft_close_hook, &game);
	mlx_loop(game.mlx);
	return (EXIT_SUCCESS);
}
