/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:16:48 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/13 15:44:10 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_wall_img	ft_wallgen(t_game *game)
{
	t_wall_img	wall;

	wall.block = mlx_xpm_file_to_image(game->mlx, "img/gen_wall.xpm",
			&game->img_size.x, &game->img_size.y);
	wall.gen = mlx_xpm_file_to_image(game->mlx, "img/gen_wall.xpm",
			&game->img_size.x, &game->img_size.y);
	wall.corner1 = mlx_xpm_file_to_image(game->mlx, "img/wall_1.xpm",
			&game->img_size.x, &game->img_size.y);
	wall.corner2 = mlx_xpm_file_to_image(game->mlx, "img/wall_0.xpm",
			&game->img_size.x, &game->img_size.y);
	return (wall);
}

void	ft_putwall(t_game *game, int x, int y, int id)
{
	if (id == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall_img.gen, x * 64, y * 64);
	if (id == 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall_img.block, x * 64, y * 64);
	if (id == 2)
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall_img.corner1, x * 64, y * 64);
	if (id == 3)
		mlx_put_image_to_window(game->mlx, game->window,
			game->wall_img.corner2, x * 64, y * 64);
}

void	ft_destroywall(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall_img.block);
	mlx_destroy_image(game->mlx, game->wall_img.gen);
	mlx_destroy_image(game->mlx, game->wall_img.corner1);
	mlx_destroy_image(game->mlx, game->wall_img.corner2);
}
