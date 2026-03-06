/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhidrob <shhidrob@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 21:17:43 by shhidrob          #+#    #+#             */
/*   Updated: 2026/03/06 21:55:58 by shhidrob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

/*
** Handles keyboard input and updates the game state.
*/

int key_press(int keycode, t_game *game) //when using ESC
{
	if(keycode == KEY_ESC)
		close_window(game);
	return(0);
}

void	init_hooks(t_game *game)
{
	mlx_hook(game->mlx.win, DestroyNotify, NoEventMask, (void *)&close_window, game);
	// mlx_hook(game->mlx.win, KeyPress, KeyPressMask, close_window, game); //17=DestroyNotify event so MLX calls this function each time typing in the keyboard - in this case when pressing X
	mlx_key_hook(game->mlx.win, key_press, game);//call to key_press when typing in the keyboard
}

