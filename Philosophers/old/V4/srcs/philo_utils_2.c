/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:04 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/24 16:41:22 by gduranti         ###   ########.fr       */
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
		diner->free_fork = TRUE;
		i--;
		diner = diner->next;
	}
}
