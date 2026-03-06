/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhidrob <shhidrob@student.42london.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:38:29 by mimacdou          #+#    #+#             */
/*   Updated: 2026/03/06 22:08:15 by shhidrob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int	main(int ac, char **av)
// {
// 	check_args(ac, av);
// }

int main(int ac,char **av)
{
	
	t_game game;

	ft_memset(&game, 0, sizeof(t_game));

	(void)ac;
	(void)av;
	test_mlx(&game);
	return(0);
}