/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pthiruma <pthiruma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 22:02:13 by pthiruma          #+#    #+#             */
/*   Updated: 2023/10/18 11:12:18 by pthiruma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void ft_free_map(t_map *map)
{
	int	i;

	i = -1;
	while (map->lines && map->lines[++i])
		free(map->lines[i]);
	free (map->lines);
	i = -1;
	while (map->lines_copy && map->lines_copy[++i])
		free(map->lines_copy[i]);
	free (map->lines_copy);
	free (map);
}

//prints error message to STD_ERR, free data and exit with failure status
void ft_error_end(const char *msg, t_game *game)
{
	ft_putendl_fd(ERR_MSG, STD_ERR);
	perror(msg);
	ft_printf("HALLO\n");
	if (game && game->map)
		ft_free_map(game->map);
	if (game && game->mlx)
		mlx_terminate(game->mlx);
	exit(EXIT_FAILURE);
}