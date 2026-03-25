/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moik <moik@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:11:56 by mimacdou          #+#    #+#             */
/*   Updated: 2026/03/25 18:55:11 by moik             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//////////////////////////LIBRARIES START//////////////////////

# include <math.h>
# include <errno.h> //only in files .c
# include <sys/time.h> //to measure time
# include "./Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"//not sure we need to include it here bc it's for internal mlx purposes?
# include <X11/keysym.h>

//////////////////////////LIBRARIES END////////////////////////

//////////////////////////MARCOS START/////////////////////////

# define KEY_ESC	XK_Escape
# define KEY_W		XK_w
# define KEY_A		XK_a
# define KEY_S		XK_s
# define KEY_D		XK_d
# define KEY_LEFT	XK_Left
# define KEY_RIGHT	XK_Right

# define START 'N'
# define WALL '1'
# define FLOOR '0' //empty space

//////////////////////////MARCOS END///////////////////////////

/////////////////////////STRUCTS START/////////////////////////

typedef enum e_direct
{
	NORTH = 0,
	SOUTH,
	WEST,
	EAST
}	t_dir;

typedef enum e_tex
{
	T_NORTH = 0,
	T_SOUTH,
	T_WEST,
	T_EAST
}	t_tex;

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

typedef struct s_texture // each texture has its own image, its own buffer & its own dimensions - used to pick what pixel to draw in the wall (raycasting)
{
	void	*img; //off-screen buffer (image in memory) - to draw here not directly to the window(no parpadeos)
	char	*addr;//image memory address - to write the pixels e.g. addr[y * line_length + x * (bpp / 8)] = color;
	int		width;
	int		height;
	int		bits_per_pixel;//usually 32 - bytes in a pixel
	int		line_length;//bytes per line/row - it's not always width * bpp, can't be calculated by hand
	int		endian;//bytes order - MLX gives this, we only use it - orden de bytes 
}	t_texture;

typedef	struct	s_game
{
	t_mlx	mlx;// for all graphic related - mlx context and rendering data
	t_player	player;// player state (position + direction)
	t_texture	textures[4];//wall textures NO,SO,WE,EA - orden tbc with parsing - indexed by t_tex enum - floor & ceiling are not textures - they're colours(int)
	char	**map;//parsed map, each char represents a tile e.g. map[y][x] == '1' = the wall
	int		floor_color;//color RGB converted to an int,parsing fills it and render uses it (same for ceiling)
	int		ceiling_color;
}	t_game;

/////////////////////////STRUCTS END///////////////////////////

//////////////////////////FUNCTIONS////////////////////////////

// ARG_CHECKS FUNCTIONS

void	invaild_arg(char *str);
void	f_and_c_checks(char *map);
void	map_checks(char *map_file);
void	actually_xpm_test(char *map);
void	check_args(int ac, char **av);
void	input_content_checks(char *map);
void	extra_input_content_checks(char *map);
void	input_content_extension_checks(char *map);
void	invaild_rgb(int fd, char *line, int flag);
void	additional_rgb_checks(int fd, char *line, int flag);

bool	file_empty(char *file);
bool	exists_check(char *str);
bool	flood_status(int result);
bool	check_first_two_lines(char *texture);
bool	texture_not_empty(char *map, int flag);
bool	flood_matrix(char **matrix, int height);

int		store_house(int flag);

char	*cycle_gnl(int fd, char *to_search);

// PARSING FUNCTIONS

void	parser(t_game *game, char *map_file);

// FREEING/EXIT FUNCTIONS

void	free_matrix(char **matrix, int height);

// RENDER FUNCTIONS

int		key_press(int keycode, t_game *game);
void	init_hooks(t_game *game);
int 	close_window(t_game *game);
void	init_mlx(t_game *game);
void	render_frame(t_game *game);
void	test_mlx(t_game *game);
////////////////////////FUNCTIONS END//////////////////////////

#endif
