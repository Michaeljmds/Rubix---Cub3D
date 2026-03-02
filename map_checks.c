/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:14:16 by mimacdou          #+#    #+#             */
/*   Updated: 2026/03/02 16:46:05 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*gnl_to_matrix(char *line, int len)
{
	char	*send;
	int		i;

	i = 0;
	send = (char *)malloc(sizeof(char) * (len + 1));
	while (line[i])
	{
		send[i] = line[i];
		i++;
	}
	send[i] = '\0';
	return (send);
}

char	**make_floodfill_matrix(int fd, char *line, char *map_file)
{
	char	**matrix;
	int		tall_y;
	int		fd_two;
	int		i;

	tall_y = 1;
	while (line)
		(free(line), line = get_next_line(fd), tall_y++);
	close(fd);
	matrix = (char **)malloc(sizeof(char *) * (tall_y));
	fd_two = open(map_file, O_RDWR);
	i = 0;
	while (i <= 7)
		(free(line), line = get_next_line(fd_two), i++);
	store_house(tall_y);
		i = 0;
	while (i < tall_y)
	{
		matrix[i] = gnl_to_matrix(line, ft_strlen(line));
		(free(line), line = get_next_line(fd_two), i++);
	}
	return (free(line), close(fd_two), matrix);
}

void	flood_fill_check(char *map_file)
{
	char	**matrix;
	char	*line;
	int		fd;
	int		i;

	coloured_write("- Is Map Escapeable: ", YEL, 1);
	fd = open(map_file, O_RDWR);
	line = get_next_line(fd);
	i = 0;
	while (i <= 7)
		(free(line), line = get_next_line(fd), i++);
	matrix = make_floodfill_matrix(fd, line, map_file);
	if (!flood_matrix(matrix, store_house(999)))
		(free_matrix(matrix, store_house(999)), invaild_arg("Map isn't closed"));
	coloured_write("Passed\n", BHGRN, 1);
	free_matrix(matrix, store_house(999));
}

bool	vaild_map_characters(int fd, char *line)
{
	int	i;

	i = 0;
	while (line)
	{
		while (line[i])
		{
			if (line[i] != ' ' && line[i] != '1' && line[i] != '0' && \
line[i] != 'N' && line[i] != 'E' && line[i] != 'S' && line[i] != 'W' && \
line[i] != '\n')
				(free(line), close(fd), invaild_arg("Invaild characters \
present in map"));
			i++;
		}
		i = 0;
		(free(line), line = get_next_line(fd));
	}
	return (true);
}

void	map_checks(char *map_file)
{
	char	*line;
	int		fd;
	int		i;

	coloured_write("- Map Present Check: ", YEL, 1);
	fd = open(map_file, O_RDWR);
	line = get_next_line(fd);
	i = 0;
	while (i <= 7)
	{
		(free(line), line = get_next_line(fd), i++);
		if (i == 7)
			if (!line)
				invaild_arg("Map missing or misaligned");
	}
	if (!line || !ft_strchr(line, '1'))
		invaild_arg("Map missing or misaligned");
	coloured_write("Passed\n", BHGRN, 1);
	coloured_write("- Valid Map Characters: ", YEL, 1);
	vaild_map_characters(fd, line);
	coloured_write("Passed\n", BHGRN, 1);
	close(fd);
	flood_fill_check(map_file);
}
