/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:11:56 by mimacdou          #+#    #+#             */
/*   Updated: 2026/02/27 18:53:58 by shhidrob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//////////////////////////LIBRARIES START//////////////////////

# include <math.h>
# include <errno.h>
# include <sys/time.h>
# include "./Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

//////////////////////////LIBRARIES END////////////////////////

//////////////////////////MARCOS START/////////////////////////

//////////////////////////MARCOS END///////////////////////////

/////////////////////////STRUCTS START/////////////////////////

typedef struct s_player
{
	double x; //double? because the player will be moving between cells = e.g. x = 2.5 y = 3.5
	double y;
	double dir_x; //direction vector to where the player looks at - used for back and forward moves & raycasting direction e.g.dir_x = 0 dir_y = -1 = looking to north
	double dir_y;
	double plane_x;//represents the camera's view plan, defines FOV (campo de vision) e.g. dir_x = -1; dir_y = 0;plane_x = 0; plane_y = 0.66; 0.66 = FOV of 66"
	double plane_y; //used for calculate each camera window laser direction & generate 3D efect
}	t_player;


typedef struct s_mlx
{
	void	*mlx;//made when mlx_init()
	void	*win;//graphic window - without it there's no render neither events
	void	*img; //off-screen buffer (image in memory) - to draw here not directly to the window(no parpadeos)
	char	*addr;//image memory address - to write the pixels e.g. addr[y * line_length + x * (bpp / 8)] = color; 
	int		bits_per_pixel;//usually 32 - bytes in a pixel
	int		line_length;//bytes per line/row - it's not always width * bpp, can't be calculated by hand
	int		endian;//bytes order - MLX gives this, we only use it - orden de bytes 
}	t_mlx;

typedef struct s_texture
{
	void	*img;// each texture has its own image, its own buffer & its own dimensions - used to pick what pixel to draw in the wall (raycasting)
	char	*addr;//
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;

typedef	struct	s_game
{
	t_mlx	mlx;// for all graphic related
	t_player	player;// player status
	t_texture	textures[4];// NO,SO,WE,EA - orden tbc with parsing
	char	**map;//parsed map, each char represents a tile e.g. map[y][x] == '1' = the wall
	int		floor_color;//color RGB converted to an int,parsing fills it and render uses it (same for ceiling)
	int		ceiling_color;
}	t_game;

/////////////////////////STRUCTS END///////////////////////////

//////////////////////////FUNCTIONS////////////////////////////

void	invaild_arg(char *str);
void	f_and_c_checks(char *map);
void	actually_xpm_test(char *map);
void	check_args(int ac, char **av);
void	input_content_checks(char *map);
void	extra_input_content_checks(char *map);
void	input_content_extension_checks(char *map);

bool	file_empty(char *file);
bool	exists_check(char *str);
bool	check_first_two_lines(char *texture);
bool	texture_not_empty(char *map, int flag);

////////////////////////FUNCTIONS END//////////////////////////

#endif
