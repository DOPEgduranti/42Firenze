/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:23:28 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/15 10:58:03 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_exit_img	ft_exitgen(t_game *game)
{
	t_exit_img	exit;

	exit.img_0 = mlx_xpm_file_to_image(game->mlx, "img/exit_0.xpm",
			&game->img_size.x, &game->img_size.y);
	exit.img_1 = mlx_xpm_file_to_image(game->mlx, "img/exit_1.xpm",
			&game->img_size.x, &game->img_size.y);
	exit.img_2 = mlx_xpm_file_to_image(game->mlx, "img/exit_win.xpm",
			&game->img_size.x, &game->img_size.y);
	exit.anim_frames = 3;
	exit.tile = ft_findfirst(game->map, EXIT);
	return (exit);
}

void	ft_putexit(t_game *game, int x, int y, int id)
{
	if (id == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit_img.img_0, x * 64, y * 64);
	if (id == 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit_img.img_1, x * 64, y * 64);
	if (id == 2)
		mlx_put_image_to_window(game->mlx, game->window,
			game->exit_img.img_2, x * 64, y * 64);
}

void	ft_destroyexit(t_game *game)
{
	mlx_destroy_image(game->mlx, game->exit_img.img_0);
	mlx_destroy_image(game->mlx, game->exit_img.img_1);
	mlx_destroy_image(game->mlx, game->exit_img.img_2);
}

void	ft_destroygame(t_game *game)
{
	ft_mtxdel(&game->map);
	mlx_destroy_image(game->mlx, game->grass_img);
	mlx_destroy_image(game->mlx, game->effect.img);
	mlx_destroy_image(game->mlx, game->effect.death);
	free(game->moves_str);
}

void	ft_closegame(t_game *game)
{
	ft_destroyplayer(game);
	ft_destroyenemy(game);
	ft_destroycollect(game);
	ft_destroyexit(game);
	ft_destroywall(game);
	ft_destroygame(game);
	mlx_destroy_window(game->mlx, game->window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
