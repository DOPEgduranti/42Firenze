/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:04 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/22 16:03:03 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_threadgen(t_diner *diner)
{
	int	i;

	i = diner->var->nbr_of_philo;
	while (i)
	{
		if (ft_threrr(pthread_create(&diner->id_philo, NULL, ft_think, (void *)diner), &diner) == TRUE)
			ft_exit(&diner, FALSE);
		usleep(0);
		i--;
		diner = diner->next;
	}
}

void	ft_forkunlock(t_diner *diner)
{
	int	i;

	i = diner->var->nbr_of_philo;
	while (i)
	{
		pthread_mutex_unlock(&diner->id_fork);
		usleep(0);
		i--;
		diner = diner->next;
	}
}