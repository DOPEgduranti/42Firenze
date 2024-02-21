/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:26:20 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/19 12:07:37 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(t_diner *diner)
{
	printf("%ld\t%d is sleeping\n\n", ft_get_time() - diner->start_time, diner->tag);
	if (diner->last_meal + diner->var.time_to_sleep + diner->var.time_to_eat > diner->var.time_to_die)
	{
		ft_usleep(diner->var.time_to_die);
		printf("%ld\t%d died while asleep\n\n", ft_get_time() - diner->start_time, diner->tag);
		ft_exit(&diner, TRUE);
	}
	ft_usleep(diner->var.time_to_sleep);
	printf("%ld\t%d is thinking\n\n", ft_get_time() - diner->start_time, diner->tag);
	ft_think((void *)diner);
}

void	ft_eat(t_diner *diner)
{
	printf("%ld\t%d is eating\n\n", diner->last_meal - diner->start_time, diner->tag);
	diner->meal_got++;
	if (diner->last_meal + diner->var.time_to_eat > diner->var.time_to_die)
	{
		ft_usleep(diner->var.time_to_die);
		printf("%ld\t%d died while eating pasta\n\n", ft_get_time() - diner->start_time, diner->tag);
		ft_exit(&diner, TRUE);
	}
	ft_usleep(diner->var.time_to_eat);
	if (diner->var.nbr_time_philo_eat != 0 && diner->meal_got == diner->var.nbr_time_philo_eat)
	{
		printf("%ld\t%d has eaten maximum times\n\n", ft_get_time() - diner->start_time, diner->tag);
		ft_exit(&diner, TRUE);
	}
	pthread_mutex_unlock(&diner->id_fork);
	pthread_mutex_unlock(&diner->next->id_fork);
	ft_sleep(diner);
}

void	*ft_think(void *diner1)
{
	t_diner *diner;

	diner = (t_diner *)diner1;
	
	// if (ft_get_time() - diner->last_meal > diner->var.time_to_die)
	// {
	// 	printf("%ld\t%d died while thinking\n\n", ft_get_time() - diner->start_time, diner->tag);
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
		ft_usleep(10); 
		ft_think(diner1);
	}
	return (NULL);
}

void	ft_begin(t_diner *diner)
{
	int				i;
	u_int64_t		now;

	now = ft_get_time();
	i = diner->var.nbr_of_philo;
	while (i)
	{
		diner->start_time = now;
		printf("%ld\t%d is thinking\n\n", ft_get_time() - diner->start_time, diner->tag);
		diner->last_meal = ft_get_time();
		i--;
		diner = diner->next;
	}
	i = diner->var.nbr_of_philo;
	while (i)
	{
		pthread_mutex_unlock(&diner->id_fork);
		ft_usleep(10);
		i--;
		diner = diner->next;
	}
}
