#include "../../cub3D.h"


void test_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlx, 800,600, "cub3d test");
	mlx_hook(game->mlx.win, DestroyNotify, NoEventMask, (void *)&close_window, game);

	mlx_loop(game->mlx.mlx);
}
