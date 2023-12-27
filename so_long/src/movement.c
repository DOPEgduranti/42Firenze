/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:50:22 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/15 11:09:37 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_death(t_game *game)
{
	int	i;

	i = 50000;
	while (i--)
		mlx_put_image_to_window(game->mlx, game->window, game->effect.death,
			game->player.tile.x * 64, game->player.tile.y * 64);
	ft_printf("-----------------\n| YOU LOST NOOB |\n-----------------\n");
	ft_printf("Game total moves : %d\n", game->moves);
	ft_closegame(game);
}

void	ft_pmove(t_game *game, int keysym)
{
	t_vector	vec;
	int			i;

	i = 15000;
	vec = ft_keymove(keysym);
	game->moves++;
	if (game->map[game->player.tile.y + vec.y][game->player.tile.x + vec.x]
		== ENEMY)
		ft_death(game);
	if (game->map[game->player.tile.y + vec.y][game->player.tile.x + vec.x]
		== WALL)
		return ;
	while (i--)
		ft_putplayer(game, game->player.tile.x, game->player.tile.y, 2);
	game->map[game->player.tile.y + vec.y][game->player.tile.x + vec.x]
		= PLAYER;
	game->map[game->player.tile.y][game->player.tile.x] = EMPTY;
	ft_putgrass(game, game->player.tile.x, game->player.tile.y, 0);
	game->player.tile.y += vec.y;
	game->player.tile.x += vec.x;
	ft_putplayer(game, game->player.tile.x, game->player.tile.y, 0);
}

void	ft_playeronexit(t_game *game, t_bool canfinish)
{
	if (game->exit_img.tile.x == game->player.tile.x
		&& game->exit_img.tile.y == game->player.tile.y)
		ft_putplayer(game, game->exit_img.tile.x, game->exit_img.tile.y, 3);
	else
	{
		if (canfinish == FALSE)
			ft_putexit(game, game->exit_img.tile.x, game->exit_img.tile.y, 0);
		else
			ft_putexit(game, game->exit_img.tile.x, game->exit_img.tile.y, 1);
		game->map[game->exit_img.tile.y][game->exit_img.tile.x] = EXIT;
	}
}

void	ft_printmoves(t_game *game)
{
	mlx_string_put(game->mlx, game->window, 64,
		game->map_size.y * IMG_SIZE + 32, 0x000000, game->moves_str);
	free(game->moves_str);
	game->moves_str = ft_itoa(game->moves);
	if (!game->moves_str)
		return ;
	game->moves_str = ft_strjoin2("Moves done : ", game->moves_str);
	mlx_string_put(game->mlx, game->window, 64,
		game->map_size.y * IMG_SIZE + 32, 0xFFFFFF, game->moves_str);
}
