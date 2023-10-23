/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 09:45:46 by pthiruma          #+#    #+#             */
/*   Updated: 2023/10/18 11:56:53 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void ft_collectibles(t_game *g)
{
	int i;

	i = 0;

	while (i < g->img_collectibles->count)
	{
		if (g->img_collectibles->instances[i].x == g->img_player->instances[0].x
		   && g->img_collectibles->instances[i].y == g->img_player->instances[0].y
		   && g->img_collectibles->instances[i].enabled)
		   {
				g->img_collectibles->instances[i].enabled = false;
				g->collected++;
		   }
		i++;
	}
}

void	ft_move(t_game *g, int x, int y)
{

	if (g->map->lines[y / 32][x / 32] == WALL)
		return ;
	g->img_player->instances[0].y = y;
	g->img_player->instances[0].x = x;
	g->movement++;
	ft_printf("Moved: %d\n", g->movement);
	ft_collectibles(g);
	if (g->map->lines[y / 32][x / 32] == EXIT && 
	    g->collected == g->map->collectibles)
	{
		mlx_terminate(g->mlx);	
		exit(EXIT_SUCCESS);
	}
}