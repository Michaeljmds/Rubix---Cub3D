#include "../../../cub3D.h"

void	init_mlx(t_game *game)
{
	game->mlx.mlx = mlx_init();
	if (!game->mlx.mlx)
		exit(1);

	game->mlx.win = mlx_new_window(game->mlx.mlx, 800, 600, "cub3D");
	if (!game->mlx.win)
		exit(1);

	game->mlx.img = mlx_new_image(game->mlx.mlx, 800, 600);

	game->mlx.addr = mlx_get_data_addr(
		game->mlx.img,
		&game->mlx.bits_per_pixel,
		&game->mlx.line_length,
		&game->mlx.endian
	);

	init_hooks(game);
}