/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moik <moik@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:38:29 by mimacdou          #+#    #+#             */
/*   Updated: 2026/03/25 18:27:53 by moik             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main(int ac,char **av)
{
	t_game game;

	check_args(ac, av);
	ft_memset(&game, 0, sizeof(t_game));
	parser(&game, av[1]);
	test_mlx(&game);
	return(0);
}