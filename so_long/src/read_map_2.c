/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:16:52 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/14 13:25:27 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	ft_isrectang(char **map)
{
	t_vector	size;
	int			tiles;
	int			i;
	int			j;

	size = ft_mapsize(map);
	tiles = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			tiles++;
			j++;
		}
		if (ft_mapsizerror(map, j, size.x) == TRUE)
			return (FALSE);
		i++;
	}
	if (ft_mapsizerror(map, i, size.y) == TRUE)
		return (FALSE);
	if (size.x * size.y != tiles)
		return (FALSE);
	return (TRUE);
}

t_bool	ft_checkwalls(char **map)
{
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != WALL && (i == 0 || map[i + 1] == NULL))
				return (FALSE);
			if (map[i][j] != WALL && (j == 0 || map[i][j + 1] == '\0'))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool	ft_checkother(char **map)
{
	int			i;
	int			j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != WALL && map[i][j] != PLAYER && map[i][j] != ENEMY
				&& map[i][j] != EXIT && map[i][j] != COLLECTABLE
				&& map[i][j] != EMPTY)
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}
