/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:40:36 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/17 11:47:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;
 
	if (ft_argc_err(argc) == TRUE)
		exit(0);
	table = ft_table_set(argc, argv);
	table->diner = ft_diner_set(&table);
	
	return (0);
}

