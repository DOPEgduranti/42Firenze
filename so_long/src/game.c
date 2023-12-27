/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:59:44 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/19 10:04:36 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	ft_gameinit(char *mapname)
{
	t_game	game;

	game.map = ft_mapgen(&game, mapname);
	if (game.map == NULL)
		exit(0);
	game.mapname = mapname;
	game.mlx = mlx_init();
	game.player = ft_playergen(&game);
	game.enemy_list = ft_enemygen(&game);
	game.enemy_imgs = ft_enemyimgset(&game);
	game.collects_img = ft_collectgen(&game);
	game.wall_img = ft_wallgen(&game);
	game.exit_img = ft_exitgen(&game);
	game.grass_img = mlx_xpm_file_to_image(game.mlx, "img/grass.xpm",
			&game.img_size.x, &game.img_size.y);
	game.effect.img = mlx_xpm_file_to_image(game.mlx, "img/thunder.xpm",
			&game.img_size.x, &game.img_size.y);
	game.effect.death = mlx_xpm_file_to_image(game.mlx, "img/death.xpm",
			&game.img_size.x, &game.img_size.y);
	game.collects = 0;
	game.moves = 0;
	game.moves_str = ft_calloc(1, sizeof(char));
	game.window = mlx_new_window(game.mlx, game.map_size.x * IMG_SIZE,
			game.map_size.y * IMG_SIZE + 64, "so_long");
	return (game);
}

int	ft_key_hook(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		ft_closegame(game);
	if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d)
		ft_moveplayer(game, keysym);
	return (0);
}

int	ft_exitbutton(t_game *game)
{
	ft_closegame(game);
	return (0);
}

void	ft_win(t_game *game)
{
	int			i;

	i = 1000;
	if (!(game->exit_img.tile.x == game->player.tile.x
			&& game->exit_img.tile.y == game->player.tile.y))
		return ;
	while (i--)
		ft_putexit(game, game->exit_img.tile.x, game->exit_img.tile.y, 2);
	ft_printf("-----------------\n| !! YOU WON !! |\n-----------------\n\n");
	ft_printf("Game total moves : %d\n", game->moves);
	ft_savescore(game);
	ft_closegame(game);
}

void	ft_gamestart(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	ft_putplayer(game, game->player.tile.x, game->player.tile.y, 0);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == EXIT)
				ft_putexit(game, j, i, 0);
			if (game->map[i][j] == COLLECTABLE)
				ft_putcoll(game, j, i, 0);
			if (game->map[i][j] == WALL)
				ft_putwall(game, j, i, 0);
			if (game->map[i][j] == EMPTY)
				ft_putgrass(game, j, i, 0);
			if (game->map[i][j] == ENEMY)
				ft_putenemy(game, j, i, 0);
			j++;
		}
		i++;
	}
}
