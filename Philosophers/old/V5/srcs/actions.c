/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:26:20 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/25 12:43:08 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_diner *diner)
{
	pthread_mutex_lock(&diner->var->look);
	diner->free_fork = TRUE;
	diner->next->free_fork = TRUE;
	ft_mutprint(diner, P_SLEEP);
	if (diner->last_meal - diner->start_time + diner->var->time_to_eat + diner->var->time_to_sleep > diner->var->time_to_die)
	{
		pthread_mutex_unlock(&diner->var->look);
		usleep(diner->time_to_die - diner->time_to_eat);
		diner->death = TRUE;
		ft_think((void *)diner);
	}
	pthread_mutex_unlock(&diner->var->look);
	usleep(diner->time_to_sleep);
	ft_mutprint(diner, P_THINK);
	ft_think((void *)diner);
}

void	ft_eat(t_diner *diner)
{
	pthread_mutex_lock(&diner->var->eat);
	if (!(diner->free_fork == TRUE && diner->next->free_fork == TRUE))
	{
		pthread_mutex_unlock(&diner->var->eat);
		usleep(diner->time_to_eat);
		ft_think((void *)diner);
	}
	diner->free_fork = FALSE;
	ft_mutprint(diner, P_FORK);
	diner->next->free_fork = FALSE;
	ft_mutprint(diner, P_FORK);
	diner->last_meal = ft_get_time();
	ft_mutprint(diner, P_EAT);
	diner->meal_got++;
	if (diner->var->nbr_time_philo_eat != 0 && diner->meal_got == diner->var->nbr_time_philo_eat)
	{
		diner->var->full++;
		if (diner->var->full == diner->var->nbr_of_philo)
		{
			pthread_mutex_unlock(&diner->var->eat);
			ft_mutprint(diner, P_FINISH);
			diner->death = ERROR;
			ft_think((void *)diner);
		}
	}
	if (diner->last_meal - diner->start_time + diner->var->time_to_eat > diner->var->time_to_die)
	{
		pthread_mutex_unlock(&diner->var->eat);
		usleep(diner->time_to_die);
		diner->death = TRUE;
		ft_think((void *)diner);
	}
	pthread_mutex_unlock(&diner->var->eat);
	usleep(diner->time_to_eat);
	ft_sleep(diner);
}

void	*ft_think(void *diner)
{
	static t_bool	finiamola = FALSE;

	pthread_mutex_lock(&((t_diner *)diner)->var->finish);
	if (((t_diner *)diner)->death == TRUE || finiamola == TRUE)
	{
		finiamola = TRUE;
		pthread_mutex_unlock(&((t_diner *)diner)->var->finish);
		return (NULL);
	}
	pthread_mutex_unlock(&((t_diner *)diner)->var->finish);
	ft_eat((t_diner *)diner);
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
	ft_forkunlock(diner);
	//ft_threadgen(diner);
}
