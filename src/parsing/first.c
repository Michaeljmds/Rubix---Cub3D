/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moik <moik@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:51:17 by moik              #+#    #+#             */
/*   Updated: 2026/03/26 19:14:43 by moik             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

// WIP
void    parser(t_game *game, char *map_file)
{
	int			fd;
	char		*line;
	//t_texture	*tmp;

	//game->player = -maybe don't? not here at least
	fd = open(map_file, O_RDWR);
	//line = cycle_gnl(fd, "NO");
	//tmp = &game->textures[T_NORTH];
	//tmp->img = mlx_xpm_file_to_image(game->mlx->mlx);
	//tmp = &game->textures[T_SOUTH];
	//tmp = &game->textures[T_WEST];
	//tmp = &game->textures[T_EAST];
	line = cycle_gnl(fd, "F");
	game->floor_color = ft_split(ft_strchr(line, 'F') + 1, ',');
	(free(line), line = cycle_gnl(fd, "C"));
	game->ceiling_color = ft_split(ft_strchr(line, 'C') + 1, ',');
	(free(line), line = cycle_gnl(fd, "1"));
	game->map = make_floodfill_matrix(fd, line, map_file);
}
