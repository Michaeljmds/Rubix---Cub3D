/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moik <moik@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:51:17 by moik              #+#    #+#             */
/*   Updated: 2026/03/25 20:29:00 by moik             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

// WIP
void    parser(t_game *game, char *map_file)
{
	int			fd;
	char		*line;
	t_texture	*tmp;

	//game->player = -maybe don't? not here at least
	fd = open(map_file, O_RDWR);
	line = cycle_gnl(fd, "NO");
	tmp = &game->textures[T_NORTH];
	tmp->img = mlx_xpm_file_to_image(game->mlx->mlx);
	//tmp = &game->textures[T_SOUTH];
	//tmp = &game->textures[T_WEST];
	//tmp = &game->textures[T_EAST];
	//game->map =
	//game->floor_color =
	//game->ceiling_color =
}
