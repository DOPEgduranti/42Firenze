/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:40:36 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/22 09:17:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_diner	*diner;
	t_var	*var;
 
	if (ft_argc_err(argc) == TRUE)
		exit(0);
	var = ft_var_set(argc, argv);
	diner = ft_diner_set(var);
	if (!diner)
		return (1);
	return (0);
}

