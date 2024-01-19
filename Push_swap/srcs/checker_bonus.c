/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 15:53:34 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/15 09:55:18 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
{
	t_data	data;
	char	**moves;

	data.a_stack = ft_firstackgen(argc, argv);
	data.b_stack = NULL;
	if (!data.a_stack)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	data.size = ft_maxtag(&data.a_stack);
	moves = ft_readmoves();
	if (!moves)
	{
		ft_freedata(&data);
		return (0);
	}
	ft_domove(&data, moves, -1);
	ft_mtxdel(&moves);
	if (ft_sorted(&data.a_stack) == TRUE)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_freedata(&data);
	return (0);
}
