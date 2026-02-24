/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:11:56 by mimacdou          #+#    #+#             */
/*   Updated: 2026/02/24 21:22:34 by mimacdou         ###   ########.fr       */
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