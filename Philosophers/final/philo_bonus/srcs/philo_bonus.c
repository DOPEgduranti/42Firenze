/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:34:44 by gduranti          #+#    #+#             */
/*   Updated: 2024/02/06 15:56:25 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (ft_argc_err(argc) == TRUE)
		return (EXIT_FAILURE);
	ft_unlink();
	data = ft_datagen(argc, argv);
	ft_philo_gen(data);
	ft_wait(data);
	ft_freedata(data);
	ft_unlink();
	return (EXIT_SUCCESS);
}
