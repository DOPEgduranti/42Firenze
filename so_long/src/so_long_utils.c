/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 10:24:01 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/13 15:42:42 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_vector	ft_findfirst(char **map, char c)
{
	int			i;
	int			j;
	t_vector	vec;

	i = 0;
	vec.y = -1;
	vec.x = -1;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c)
			{
				vec.x = j;
				vec.y = i;
				return (vec);
			}
			j++;
		}
		i++;
	}
	return (vec);
}

void	ft_mtxdel(char ***mtx)
{
	size_t	i;

	i = 0;
	while ((*mtx)[i])
	{
		free((*mtx)[i]);
		i++;
	}
	free(*mtx);
	mtx = NULL;
}

void	ft_putgrass(t_game *game, int x, int y, int id)
{
	if (id == 0)
		mlx_put_image_to_window(game->mlx, game->window,
			game->grass_img, x * 64, y * 64);
}

t_vector	ft_keymove(int keysym)
{
	t_vector	vec;

	vec.x = 0;
	vec.y = 0;
	if (keysym == XK_w)
		vec.y--;
	else if (keysym == XK_s)
		vec.y++;
	else if (keysym == XK_a)
		vec.x--;
	else if (keysym == XK_d)
		vec.x++;
	return (vec);
}

char	*ft_strjoin2(char *sta_str, char *buff)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!buff)
		return (NULL);
	if (!sta_str)
		sta_str = ft_calloc(1, sizeof(char));
	if (!sta_str)
		return (NULL);
	res = ft_calloc((ft_strlen(sta_str) + ft_strlen(buff) + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	if (sta_str)
		while (sta_str[++i] != '\0')
			res[i] = sta_str[i];
	while (buff[j] != '\0')
		res[i++] = buff[j++];
	res[ft_strlen(sta_str) + ft_strlen(buff)] = '\0';
	free(buff);
	return (res);
}
