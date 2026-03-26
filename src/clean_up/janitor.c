/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   janitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moik <moik@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:49:04 by mimacdou          #+#    #+#             */
/*   Updated: 2026/03/26 19:54:16 by moik             ###   ########.fr       */
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

void	free_game(t_game *game)
{
	free_matrix(game->map, store_house(999));
	free_matrix(game->floor_color, 3);
	free_matrix(game->ceiling_color, 3);
}
