/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mimacdou <mimacdou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:11:56 by mimacdou          #+#    #+#             */
/*   Updated: 2026/02/23 20:48:09 by mimacdou         ###   ########.fr       */
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
void	check_args(int ac, char **av);
void	input_content_checks(char *map);

////////////////////////FUNCTIONS END//////////////////////////

#endif