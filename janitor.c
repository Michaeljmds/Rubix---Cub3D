/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   janitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 15:49:04 by mimacdou          #+#    #+#             */
/*   Updated: 2026/02/27 21:24:18 by mimacdou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
