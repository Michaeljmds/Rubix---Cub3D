/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhidrob <shhidrob@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 21:17:27 by shhidrob          #+#    #+#             */
/*   Updated: 2026/03/06 21:11:38 by shhidrob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3D.h"

/*
** Renders one frame based on the current game state.
** Called from the MLX loop hook.
*/

void	render_frame(t_game *game) // draw the window's image
{
	mlx_put_image_to_window(
		game->mlx.mlx,
		game->mlx.win,
		game->mlx.img,
		0,
		0
	);
}

// void	test_mlx(void)
// {
// 	t_game	game;

// 	init_mlx(&game);
// 	mlx_loop(game.mlx.mlx);
// }
// int	main(int ac, char **av)
// {
// 	t_game	game;

// 	check_args(ac, av);

// 	parse_map(&game, av[1]);

// 	init_mlx(&game);

// 	mlx_loop(game.mlx.mlx);

// 	return (0);
// }
// int render_frame(t_game *game)
// {
// 	(void)game;
// 	return(0);
// }
