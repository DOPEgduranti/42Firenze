/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_basic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:38:37 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/19 09:35:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_enemy_img	ft_enemyimgset(t_game *game)
{
	t_enemy_img	enemy_imgs;

	enemy_imgs.basic_01 = mlx_xpm_file_to_image(game->mlx,
			"img/sudowoodo.xpm", &game->img_size.x, &game->img_size.y);
	enemy_imgs.basic_02 = mlx_xpm_file_to_image(game->mlx,
			"img/sudowoodo2.xpm", &game->img_size.x, &game->img_size.y);
	return (enemy_imgs);
}

void	ft_putenemy(t_game *game, int x, int y, int id)
{
	if (id == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemy_imgs.basic_01, x * 64, y * 64);
	if (id == 1)
		mlx_put_image_to_window(game->mlx, game->window,
			game->enemy_imgs.basic_02, x * 64, y * 64);
}

void	ft_enemystartmove(t_game *game)
{
	t_enemy	*tmp_enemy;

	tmp_enemy = game->enemy_list;
	while (tmp_enemy)
	{
		ft_enemymove(game, tmp_enemy);
		tmp_enemy = tmp_enemy->next;
	}
}

t_vector	ft_randommove(void)
{
	t_vector	vec;
	int			direction;

	direction = rand() % 4;
	vec.x = 0;
	vec.y = 0;
	if (direction == 0)
		vec.y++;
	if (direction == 1)
		vec.x++;
	if (direction == 2)
		vec.y--;
	if (direction == 3)
		vec.x--;
	return (vec);
}

void	ft_destroyenemy(t_game *game)
{
	ft_enemyclear(&game->enemy_list);
	mlx_destroy_image(game->mlx, game->enemy_imgs.basic_01);
	mlx_destroy_image(game->mlx, game->enemy_imgs.basic_02);
}
