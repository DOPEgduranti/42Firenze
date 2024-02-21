/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 15:32:28 by gduranti          #+#    #+#             */
/*   Updated: 2024/02/05 12:41:06 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_philodied(void *arg)
{
	t_diner	*diner;

	diner = (t_diner *)arg;
	sem_wait(diner->data->dieall);
	sem_wait(diner->data->death);
	diner->imdead = TRUE;
	sem_post(diner->data->death);
	sem_post(diner->data->dieall);
	pthread_join(diner->undertaker, NULL);
	// ft_exit(diner->data);
	return (NULL);
}

void	*ft_checkdeath(void *arg)
{
	t_diner	*diner;
	t_bool	check;

	diner = (t_diner *)arg;
	check = FALSE;
	while (check == FALSE)
	{
		sem_wait(diner->data->death);
		if (diner->imdead == TRUE)
		{
			sem_post(diner->data->death);
			return (NULL);
		}
		else
			sem_post(diner->data->death);
		sem_wait(diner->data->meal);
		if (ft_get_time() > diner->lastmeal + diner->var.time_to_die / 1000)
		{
			sem_post(diner->data->meal);
			sem_post(diner->data->death);
			ft_semprint(diner, diner->data, P_DEATH);
			// printf("last meal %ld\n",diner->lastmeal);
			sem_post(diner->data->dieall);
			check = TRUE;
		}
		else
		{
			sem_post(diner->data->meal);
			sem_post(diner->data->death);
		}
		usleep(100);
	}
	return (NULL);
}