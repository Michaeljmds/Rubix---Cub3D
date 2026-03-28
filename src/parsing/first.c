/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moik <moik@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:51:17 by moik              #+#    #+#             */
/*   Updated: 2026/03/28 19:02:05 by moik             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

void	init_texture(t_game *game, enum e_tex flag, char *line)
{
	t_texture	*tmp;

	tmp = &game->textures[flag];
	tmp->addr = ft_strdup(ft_strchr(line, 'M'));
	tmp->img = mlx_xpm_file_to_image(game->mlx.mlx, tmp->addr, (int *)64, (int *)64); //setting height/width to 64 for time being
}

// WIP
void    parser(t_game *game, char *map_file)
{
	int			fd;
	char		*line;

	game->mlx.mlx = mlx_init();
	fd = open(map_file, O_RDWR);
	(line = cycle_gnl(fd, "NO"), init_texture(game, T_NORTH, line));
	(free(line), line = cycle_gnl(fd, "SO"), init_texture(game, T_SOUTH, line));
	(free(line), line = cycle_gnl(fd, "WE"), init_texture(game, T_WEST, line));
	(free(line), line = cycle_gnl(fd, "EA"), init_texture(game, T_EAST, line));
	(free(line), line = cycle_gnl(fd, "F"));
	game->floor_color = ft_split(ft_strchr(line, 'F') + 1, ',');
	(free(line), line = cycle_gnl(fd, "C"));
	game->ceiling_color = ft_split(ft_strchr(line, 'C') + 1, ',');
	(free(line), line = cycle_gnl(fd, "1"));
	game->map = make_floodfill_matrix(fd, line, map_file);
}
