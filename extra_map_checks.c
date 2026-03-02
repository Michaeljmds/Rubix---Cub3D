/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_map_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 20:37:56 by mimacdou          #+#    #+#             */
/*   Updated: 2026/03/02 22:19:11 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_player_coords(char **matrix, int height, int flag)
{
	int	y;
	int	x;

	y = 0;
	x = 1;
	while (!strchr(matrix[y], 'N') && !strchr(matrix[y], 'E') \
&& !strchr(matrix[y], 'S') && !strchr(matrix[y], 'W') && y <= height)
		y++;
	while (matrix[y][x] != 'N' && matrix[y][x] != 'E' \
&& matrix[y][x] != 'S' && matrix[y][x] != 'W')
		x++;
	if (flag == 0)
		return (y);
	return (x);
}

bool	flood_status(int result)
{
	static bool	overview = false;

	if (result == 1)
		overview = true;
	return (overview);
}

int	store_house(int flag)
{
	static int	storage;

	if (flag < 999)
		storage = flag;
	return (storage);
}

void	fill(char **matrix, int y, int x, int height)
{
	if (y < 0 || x < 0 || y >= height || !matrix[y] || \
!matrix[y][x] || matrix[y][x] == ' ')
	{
		flood_status(1);
		return ;
	}
	if (matrix[y][x] == 'F' || matrix[y][x] == '1')
		return ;
	matrix[y][x] = 'F';
	fill(matrix, y + 1, x, height);
	fill(matrix, y - 1, x, height);
	fill(matrix, y, x + 1, height);
	fill(matrix, y, x - 1, height);
	fill(matrix, y + 1, x + 1, height);
	fill(matrix, y - 1, x - 1, height);
	fill(matrix, y -1, x + 1, height);
	fill(matrix, y + 1, x - 1, height);
}

bool	flood_matrix(char **matrix, int height)
{
	int	x;
	int	y;

	y = get_player_coords(matrix, height, 0);
	x = get_player_coords(matrix, height, 1);
	fill(matrix, y, x, height);
	if (flood_status(0) == false)
		return (true);
	return (false);
}
