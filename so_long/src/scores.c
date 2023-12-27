/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scores.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:03:36 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/15 11:15:41 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_dellinefeed(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
}

void	ft_savescore(t_game *game)
{
	int		fd;
	char	*user;
	int		length;

	ft_printf("---------------\n\n");
	ft_printf("insert your name (max 10 chr) :\n");
	user = ft_calloc(11, sizeof(char));
	read(STDIN_FILENO, user, 10);
	ft_dellinefeed(user);
	user = ft_newstrjoin(user, ".txt");
	user = ft_strjoin2("score/", user);
	game->moves_str = ft_newstrjoin(game->moves_str, " \t ");
	game->moves_str = ft_newstrjoin(game->moves_str, game->mapname);
	fd = open(user, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (ft_filerror(fd) == FALSE)
	{
		length = 0;
		while (read(fd, user, 1))
			length++;
		write(fd, game->moves_str, ft_strlen(game->moves_str));
		write(fd, "\n", 1);
		close(fd);
	}
	free(user);
}
