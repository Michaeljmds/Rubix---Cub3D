/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_content_checks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:42:23 by mimacdou          #+#    #+#             */
/*   Updated: 2026/02/23 21:21:02 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	map_file_empty(char *map)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDWR);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (false);
	}
	close(fd);
	return (free(line), true);
}

void	input_content_checks(char *map)
{
	coloured_write("- Not Empty File: ", BHYEL, 1);
	if (!map_file_empty(map))
		invaild_arg("Error\nMap file empty");
	coloured_write("Passed\n", BHGRN, 1);
}