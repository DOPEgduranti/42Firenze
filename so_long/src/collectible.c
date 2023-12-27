/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 11:16:20 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/18 09:43:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_coll_img	ft_collectgen(t_game *game)
{
	t_coll_img	collect;

	collect.img_0 = mlx_xpm_file_to_image(game->mlx, "img/thunderstone0.xpm",
			&game->img_size.x, &game->img_size.y);
	collect.anim_frames = 1;
	return (collect);
}

void	ft_putcoll(t_game *game, int x, int y, int id)
{
	if (id == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->collects_img.img_0, x * 64, y * 64);
}

t_bool	ft_getcoll(t_game *game, int keysym)
{
	t_vector	vec;
	int			i;

	i = 35000;
	vec = ft_keymove(keysym);
	if (game->map[game->player.tile.y + vec.y][game->player.tile.x + vec.x]
		!= COLLECTABLE)
		return (FALSE);
	game->map[game->player.tile.y + vec.y][game->player.tile.x + vec.x] = EMPTY;
	game->collects++;
	ft_putgrass(game, game->player.tile.x + vec.x,
		game->player.tile.y + vec.y, 0);
	while (i--)
		ft_putplayer(game, game->player.tile.x, game->player.tile.y, 1);
	ft_putplayer(game, game->player.tile.x, game->player.tile.y, 0);
	return (TRUE);
}

t_bool	ft_collectall(t_game *game)
{
	if (game->collects == game->og_collects)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->effect.img,
			game->player.tile.x * 64, game->player.tile.y * 64);
		mlx_destroy_image(game->mlx, game->player.idle_img_0);
		mlx_destroy_image(game->mlx, game->player.action_img_0);
		game->player.idle_img_0 = mlx_xpm_file_to_image(game->mlx,
				"img/raichu1.xpm", &game->img_size.x, &game->img_size.y);
		game->player.action_img_0 = mlx_xpm_file_to_image(game->mlx,
				"img/raichu2.xpm", &game->img_size.x, &game->img_size.y);
		usleep(400000);
		ft_putplayer(game, game->player.tile.x, game->player.tile.y, 0);
		return (TRUE);
	}
	return (FALSE);
}

void	ft_destroycollect(t_game *game)
{
	mlx_destroy_image(game->mlx, game->collects_img.img_0);
}
