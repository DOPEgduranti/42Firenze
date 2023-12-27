/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:07:27 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/19 10:04:10 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		perror("Error\nWrong input");
		return (0);
	}
	srand(time(NULL));
	game = ft_gameinit(argv[1]);
	ft_gamestart(&game);
	mlx_key_hook(game.window, ft_key_hook, &game);
	mlx_hook(game.window, 33, 1L << 5, ft_exitbutton, &game);
	mlx_loop(game.mlx);
	return (0);
}
