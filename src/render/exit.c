/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhidrob <shhidrob@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 21:18:23 by shhidrob          #+#    #+#             */
/*   Updated: 2026/02/27 21:21:18 by shhidrob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

/*
** Frees allocated resources and exits the program cleanly.
*/

int close_window(t_game *game) //close window when ESC or X in the window
{
	if(game->mlx.win)
		mlx_destroy_window(game->mlx.mlx, game->mlx.win);
	if(game->mlx.mlx)
	{
		mlx_destroy_display(game->mlx.mlx);
		free(game->mlx.mlx);
	}
	exit(0);
	return(0);
}


// int close_game(t_game *game)
// {
// 	(void)game;
// 	return(0);
// }