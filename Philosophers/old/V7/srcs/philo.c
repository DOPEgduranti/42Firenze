/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:40:36 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/30 16:20:10 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_var	*var;
	t_diner	*diner;

	if (ft_argc_err(argc) == TRUE)
		return (0);
	var = ft_var_set(argc, argv);
	if (!var)
		return (0);
	diner = ft_diner_set(var);
	ft_thread_exec(diner);
	ft_dinerclear(&diner);
	return (0);
}
