/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   janitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moik <moik@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:49:04 by mimacdou          #+#    #+#             */
/*   Updated: 2026/03/28 20:55:32 by moik             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	free_matrix(char **matrix, int height)
{
	int	n;

	n = 0;
	while (n != height)
	{
		free(matrix[n]);
		n++;
	}
	free(matrix);
}

void	free_textures(t_game *game, enum e_tex flag)
{
	t_texture	*tmp;

	tmp = &game->textures[flag];
	//mlx_destroy_image(game->mlx.mlx, tmp->img); for later
	free(tmp->addr);
}

void	free_game(t_game *game)
{
	free_textures(game, T_NORTH);
	free_textures(game, T_SOUTH);
	free_textures(game, T_EAST);
	free_textures(game, T_WEST);
	free_matrix(game->map, store_house(999));
	free_matrix(game->floor_color, 3);
	free_matrix(game->ceiling_color, 3);
}
