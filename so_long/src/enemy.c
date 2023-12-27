/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:33:51 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/19 10:25:00 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemyadd_back(t_enemy **lst, t_enemy *newe)
{
	t_enemy	*tmp_lst;

	if (!newe)
		return ;
	if (!*lst)
		*lst = newe;
	else
	{
		tmp_lst = *lst;
		while (tmp_lst->next)
			tmp_lst = tmp_lst->next;
		tmp_lst->next = newe;
	}
}

t_enemy	*ft_enemynew(t_vector tile, t_enemytype type)
{
	t_enemy	*enemy;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (!enemy)
		return (NULL);
	enemy->tile = tile;
	enemy->type = type;
	enemy->next = NULL;
	return (enemy);
}

void	ft_enemyclear(t_enemy **lst)
{
	t_enemy	*tofree_lst;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tofree_lst = *lst;
		*lst = (*lst)->next;
		free(tofree_lst);
	}
	lst = NULL;
}

t_enemy	*ft_enemygen(t_game *game)
{
	t_enemy		*enemy;
	t_vector	pos;

	enemy = NULL;
	pos.y = -1;
	while (game->map[++pos.y])
	{
		pos.x = -1;
		while (game->map[pos.y][++pos.x])
		{
			if (game->map[pos.y][pos.x] == ENEMY)
				ft_enemyadd_back(&enemy, ft_enemynew(pos, RANDOM_ENEMY));
		}
	}
	return (enemy);
}

void	ft_enemymove(t_game *game, t_enemy *enemy)
{
	t_vector	vec;
	int			i;

	i = 15000;
	vec = ft_randommove();
	if (game->map[enemy->tile.y + vec.y][enemy->tile.x + vec.x] == PLAYER)
		ft_death(game);
	if (game->map[enemy->tile.y + vec.y][enemy->tile.x + vec.x] != EMPTY)
		return ;
	game->map[enemy->tile.y + vec.y][enemy->tile.x + vec.x] = ENEMY;
	game->map[enemy->tile.y][enemy->tile.x] = EMPTY;
	while (i--)
		ft_putenemy(game, enemy->tile.x, enemy->tile.y, 1);
	ft_putgrass(game, enemy->tile.x, enemy->tile.y, 0);
	enemy->tile.x += vec.x;
	enemy->tile.y += vec.y;
	ft_putenemy(game, enemy->tile.x, enemy->tile.y, 0);
}
