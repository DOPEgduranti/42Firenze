/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:32:40 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/18 10:17:24 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	ft_filerror(int fd)
{
	if (fd >= 0)
		return (FALSE);
	perror("Error\nError opening file");
	exit(0);
	return (TRUE);
}

t_bool	ft_mtxerror(char **mtx)
{
	if (mtx)
		return (FALSE);
	perror("Error\nError generating the map");
	return (TRUE);
}

t_bool	ft_objerror(char **map, int door, int player, int collect)
{
	if (door == 1 && player == 1 && collect > 0)
		return (FALSE);
	ft_mtxdel(&map);
	perror("Error\nInvalid objects");
	return (TRUE);
}

t_bool	ft_mapsizerror(char **map, int a, int b)
{
	if (a == b)
		return (FALSE);
	ft_mtxdel(&map);
	perror("Error\nInvalid map dimensions");
	return (TRUE);
}
