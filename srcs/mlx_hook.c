/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:28:30 by pthiruma          #+#    #+#             */
/*   Updated: 2023/10/17 15:32:28 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"/* free memory to close */
void	ft_close_hook(void *param)
{
	t_game *game;

	game = param;
	ft_free_map(game->map);
}

/* ESC and arrow key hooks */
void ft_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	mlx_instance_t player;

	game = param;
	player = game->img_player->instances[0];
	if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		ft_move(game, player.x, player.y - 32);
	if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		ft_move(game, player.x, player.y + 32);
	if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		ft_move(game, player.x + 32, player.y);
	if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		ft_move(game, player.x - 32, player.y);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		mlx_terminate(game->mlx);
		exit(EXIT_SUCCESS);
	}
}