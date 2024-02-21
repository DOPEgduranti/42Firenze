/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:54:34 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/21 11:00:47 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_player	ft_playergen(t_game *game)
{
	t_player	player;

	player.idle_img_0 = mlx_xpm_file_to_image(game->mlx, "img/delibird0.xpm",
			&game->img_size.x, &game->img_size.y);
	player.idle_img_1 = mlx_xpm_file_to_image(game->mlx, "img/delibird2.xpm",
			&game->img_size.x, &game->img_size.y);
	player.action_img_0 = mlx_xpm_file_to_image(game->mlx, "img/delibird1.xpm",
			&game->img_size.x, &game->img_size.y);
	player.onexit_img = mlx_xpm_file_to_image(game->mlx, "img/delionexit.xpm",
			&game->img_size.x, &game->img_size.y);
	player.idle_frames = 2;
	player.frame_count = 0;
	player.action_frames = 1;
	player.tile = ft_findfirst(game->map, PLAYER);
	return (player);
}

void	ft_putplayer(t_game *game, int x, int y, int id)
{
	if (id == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->player.idle_img_0, x * 64, y * 64);
	if (id == 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->player.idle_img_1, x * 64, y * 64);
	if (id == 2)
		mlx_put_image_to_window(game->mlx, game->window,
			game->player.action_img_0, x * 64, y * 64);
	if (id == 3)
		mlx_put_image_to_window(game->mlx, game->window,
			game->player.onexit_img, x * 64, y * 64);
}

void	ft_moveplayer(t_game *game, int keysym)
{
	static t_bool	canfinish = FALSE;
	static t_bool	collect = FALSE;

	collect = ft_getcoll(game, keysym);
	if (collect == TRUE && canfinish == FALSE)
		canfinish = ft_collectall(game);
	if (collect == FALSE)
		ft_pmove(game, keysym);
	ft_printmoves(game);
	if (canfinish == TRUE)
		ft_win(game);
	ft_playeronexit(game, canfinish);
	ft_enemystartmove(game);
}

void	ft_destroyplayer(t_game *game)
{
	mlx_destroy_image(game->mlx, game->player.action_img_0);
	mlx_destroy_image(game->mlx, game->player.idle_img_0);
	mlx_destroy_image(game->mlx, game->player.idle_img_1);
	mlx_destroy_image(game->mlx, game->player.onexit_img);
}
