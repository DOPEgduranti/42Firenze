/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:26:20 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/22 10:51:09 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_diner *diner)
{
	ft_mutprint(diner, P_SLEEP);
	if (diner->last_meal.tv_usec + diner->var->time_to_sleep + diner->var->time_to_eat > diner->var->time_to_die)
	{
		ft_usleep(diner->var->time_to_die);
		ft_mutprint(diner, P_DEATH);
		ft_exit(&diner, TRUE);
	}
	ft_usleep(diner->var->time_to_sleep);
	ft_mutprint(diner, P_THINK);
	ft_think((void *)diner);
}

void	ft_eat(t_diner *diner)
{
	static int	full = 0;

	ft_mutprint(diner, P_EAT);
	diner->meal_got++;
	if (diner->last_meal.tv_usec + diner->var->time_to_eat > diner->var->time_to_die)
	{
		ft_usleep(diner->var->time_to_die);
		ft_mutprint(diner, P_DEATH);
		ft_exit(&diner, TRUE);
	}
	if (diner->var->nbr_time_philo_eat != 0 && diner->meal_got == diner->var->nbr_time_philo_eat)
	{
		full++;
		if (full == diner->var->nbr_of_philo)
		{
			ft_mutprint(diner, P_FINISH);
			ft_exit(&diner, TRUE);
		}
	}
	ft_usleep(diner->var->time_to_eat);
	pthread_mutex_unlock(&diner->id_fork);
	pthread_mutex_unlock(&diner->next->id_fork);
	ft_sleep(diner);
}

void	*ft_think(void *diner1)
{
	t_diner *diner;

	diner = (t_diner *)diner1;
	gettimeofday(&diner->act_time, NULL);
	// if (diner->act_time.tv_usec - diner->last_meal.tv_sec > diner->var->time_to_die)
	// {
	// 	ft_mutprint(diner, P_DEATH);
	// 	ft_exit(&diner, TRUE);
	// }
	// else
	if (diner->next && diner->id_fork.__data.__lock == FALSE && diner->next->id_fork.__data.__lock == FALSE)
	{
		ft_takefork(diner);
		ft_eat(diner);
	}
	else
	{
		ft_usleep(1);
		ft_think(diner1);
	}
	return (NULL);
}

void	ft_begin(t_diner *diner)
{
	int				i;
	struct timeval	now;

	gettimeofday(&now, NULL);
	i = diner->var->nbr_of_philo;
	while (i)
	{
		diner->start_time = now;
		ft_mutprint(diner, P_THINK);
		gettimeofday(&diner->last_meal, NULL);
		i--;
		diner = diner->next;
	}
	i = diner->var->nbr_of_philo;
	while (i)
	{
		pthread_mutex_unlock(&diner->id_fork);
		ft_usleep(1);
		i--;
		diner = diner->next;
	}
}
