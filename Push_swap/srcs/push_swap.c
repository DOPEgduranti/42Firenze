/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:55:45 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/12 09:18:31 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data.a_stack = ft_firstackgen(argc, argv);
	data.b_stack = NULL;
	if (!data.a_stack)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	data.size = ft_maxtag(&data.a_stack);
	ft_sort(&data);
	ft_freedata(&data);
	return (0);
}
