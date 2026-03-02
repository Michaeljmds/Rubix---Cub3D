/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_content_checks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:42:23 by mimacdou          #+#    #+#             */
/*   Updated: 2026/02/27 19:11:36 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static bool	texture_checks_two(char *map, int flag)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map, O_RDWR);
	line = get_next_line(fd);
	while (i <= 1)
		(free(line), line = get_next_line(fd), i++);
	if (!line)
		return (close(fd), false);
	if (flag == 2)
		if (line[0] == 'W' && line[1] == 'E')
			return (free(line), close(fd), true);
	(free(line), line = get_next_line(fd));
	if (!line)
		return (close(fd), false);
	if (flag == 3)
		if (line[0] == 'E' && line[1] == 'A')
			return (free(line), close(fd), true);
	return (free(line), close(fd), false);
}

static bool	texture_checks(char *map, int flag)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDWR);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), false);
	if (flag == 0)
		if (line[0] == 'N' && line[1] == 'O')
			return (free(line), close(fd), true);
	(free(line), line = get_next_line(fd));
	if (!line)
		return (close(fd), false);
	if (flag == 1)
		if (line[0] == 'S' && line[1] == 'O')
			return (free(line), close(fd), true);
	return (free(line), close(fd), false);
}

static bool	texture_exist(char *map, int flag)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDWR);
	line = get_next_line(fd);
	if (flag == 0)
		if (exists_check(line + 3))
			return (free(line), close(fd), true);
	(free(line), line = get_next_line(fd));
	if (flag == 1)
		if (exists_check(line + 3))
			return (free(line), close(fd), true);
	(free(line), line = get_next_line(fd));
	if (flag == 2)
		if (exists_check(line + 3))
			return (free(line), close(fd), true);
	(free(line), line = get_next_line(fd));
	if (flag == 3)
		if (exists_check(line + 3))
			return (free(line), close(fd), true);
	return (free(line), close(fd), false);
}

void	extra_content_checks(char *map)
{
	coloured_write("- NO Texture Exist: ", YEL, 1);
	if (!texture_exist(map, 0))
		invaild_arg(strerror(errno));
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- SO Texture Exist: ", YEL, 1);
	if (!texture_exist(map, 1))
		invaild_arg(strerror(errno));
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- WE Texture Exist: ", YEL, 1);
	if (!texture_exist(map, 2))
		invaild_arg(strerror(errno));
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- EA Texture Exist: ", YEL, 1);
	if (!texture_exist(map, 3))
		invaild_arg(strerror(errno));
	coloured_write("Passed\n", BHGRN, 1);
	input_content_extension_checks(map);
	extra_input_content_checks(map);
	actually_xpm_test(map);
	f_and_c_checks(map);
	map_checks(map);
}

void	input_content_checks(char *map)
{
	coloured_write("- Not Empty File: ", YEL, 1);
	if (!file_empty(map))
		invaild_arg("Map file empty");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- NO Texture Present: ", YEL, 1);
	if (!texture_checks(map, 0))
		invaild_arg("Texture NO absent");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- SO Texture Present: ", YEL, 1);
	if (!texture_checks(map, 1))
		invaild_arg("Texture SO absent");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- WE Texture Present: ", YEL, 1);
	if (!texture_checks_two(map, 2))
		invaild_arg("Texture WE absent");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- EA Texture Present: ", YEL, 1);
	if (!texture_checks_two(map, 3))
		invaild_arg("Texture EA absent");
	coloured_write("Passed\n", BHGRN, 1);
	extra_content_checks(map);
}
