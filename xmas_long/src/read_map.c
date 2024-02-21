/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 09:25:43 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/18 10:11:10 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_bool	ft_mapobjcheck(char **map, int door, int player, t_game *game)
{
	int	i;
	int	j;

	i = -1;
	game->og_collects = 0;
	if (ft_checkwalls(map) == FALSE)
		return (ft_objerror(map, 0, 0, 0));
	if (ft_checkother(map) == TRUE)
		return (ft_objerror(map, 0, 0, 0));
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == EXIT)
				door++;
			if (map[i][j] == PLAYER)
				player++;
			if (map[i][j] == COLLECTABLE)
				game->og_collects++;
		}
	}
	return (ft_objerror(map, door, player, game->og_collects));
}

static char	**ft_maptomtx(char *mapname)
{
	int		fd;
	char	**mtx;
	char	*tmp_str;
	char	*maptoline;

	fd = open(mapname, O_RDONLY);
	if (ft_filerror(fd) == TRUE)
		return (NULL);
	maptoline = ft_calloc(1, sizeof(char));
	tmp_str = "";
	while (tmp_str)
	{
		tmp_str = get_next_line(fd);
		if (tmp_str)
		{
			maptoline = ft_newstrjoin(maptoline, tmp_str);
			free(tmp_str);
		}
	}
	close(fd);
	mtx = ft_split(maptoline, '\n');
	free(maptoline);
	if (ft_mtxerror(mtx) == TRUE)
		return (NULL);
	return (mtx);
}

t_vector	ft_mapsize(char **map)
{
	t_vector	size;

	size.y = 0;
	size.x = 0;
	while (map[size.y])
		size.y++;
	while (map[0][size.x])
		size.x++;
	return (size);
}

static void	ft_havepath(char **map, t_game *game, int *counter, t_vector pos)
{
	if (pos.y >= game->map_size.y || pos.x >= game->map_size.x
		|| map[pos.y][pos.x] == WALL)
		return ;
	if (map[pos.y][pos.x] == COLLECTABLE || map[pos.y][pos.x] == EXIT)
	{
		map[pos.y][pos.x] = WALL;
		(*counter)++;
	}
	if (*counter == game->og_collects + 1)
		return ;
	map[pos.y][pos.x] = WALL;
	ft_havepath(map, game, counter, (t_vector){pos.x, pos.y + 1});
	ft_havepath(map, game, counter, (t_vector){pos.x, pos.y - 1});
	ft_havepath(map, game, counter, (t_vector){pos.x + 1, pos.y});
	ft_havepath(map, game, counter, (t_vector){pos.x - 1, pos.y});
}

char	**ft_mapgen(t_game *game, char *mapname)
{
	char	**mapmtx;
	int		tmp_int;

	mapmtx = ft_maptomtx(mapname);
	if (ft_mtxerror(mapmtx) == TRUE || ft_isrectang(mapmtx) == FALSE
		|| ft_mapobjcheck(mapmtx, 0, 0, game) == TRUE)
		return (NULL);
	game->map_size = ft_mapsize(mapmtx);
	tmp_int = 0;
	ft_havepath(mapmtx, game, &tmp_int, ft_findfirst(mapmtx, PLAYER));
	ft_mtxdel(&mapmtx);
	mapmtx = ft_maptomtx(mapname);
	if (ft_mtxerror(mapmtx) == TRUE)
		return (NULL);
	if (tmp_int != game->og_collects + 1)
	{
		perror("Error\nNo path found in map");
		ft_mtxdel(&mapmtx);
		return (NULL);
	}
	return (mapmtx);
}
