/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:26:20 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/30 11:07:07 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_diner *diner)
{
	pthread_mutex_unlock(&diner->next->my_fork);
	pthread_mutex_unlock(&diner->my_fork);
	if(ft_checkdeath(diner) == TRUE)
		ft_think(diner);
	ft_mutprint(diner, P_SLEEP);
	if (diner->time_to_eat + diner->time_to_sleep > diner->time_to_die)
	{
		ft_usleep(diner->time_to_die - diner->time_to_eat);
		// ft_mutprint(diner, P_DEATH);
		// pthread_mutex_lock(&diner->var->finish);
		// diner->var->stop = TRUE;
		// pthread_mutex_unlock(&diner->var->finish);
		ft_think(diner);
	}
	else
		ft_usleep(diner->time_to_sleep);
	ft_mutprint(diner, P_THINK);
	ft_think(diner);
}

void	ft_eat(t_diner *diner)
{
	if(ft_checkdeath(diner) == TRUE)
		ft_think(diner);
	ft_mutprint(diner, P_FORK);
	ft_mutprint(diner, P_FORK);
	diner->last_meal = ft_get_time();
	ft_mutprint(diner, P_EAT);
	if (diner->time_to_eat > diner->time_to_die)
	{
		ft_usleep(diner->time_to_die);
		pthread_mutex_unlock(&diner->next->my_fork);
		pthread_mutex_unlock(&diner->my_fork);
		ft_think(diner);
	}
	else
		ft_usleep(diner->time_to_eat);
	ft_sleep(diner);
}

void	*ft_think(void *arg)
{
	t_diner *diner;

	diner = (t_diner *)arg;
	if(ft_checkdeath(diner) == TRUE)
		return (NULL);
	if(pthread_mutex_lock(&diner->my_fork))
		ft_think(diner);
	if(!pthread_mutex_lock(&diner->next->my_fork))
		ft_eat(diner);
	else
	{
		pthread_mutex_unlock(&diner->my_fork);
		ft_think(diner);
	}
	return (NULL);
}

void	ft_begin(t_diner **diner)
{
	int		i;
	long	now;
	t_diner	*tmp;

	tmp = *diner;
	now = ft_get_time();
	i = tmp->var->nbr_of_philo;
	while (i)
	{
		tmp->start_time = now;
		tmp->last_meal = ft_get_time();
		ft_mutprint(tmp, P_THINK);
		i--;
		tmp = tmp->next;
	}
	//ft_forkunlock(diner);
	//ft_threadgen(diner);
}
