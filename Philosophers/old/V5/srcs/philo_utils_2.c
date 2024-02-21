/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:04 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/25 12:46:34 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philodeath(void *diner)
{
	t_diner *tmp;
	int		i;

	tmp = (t_diner *)diner;
	ft_threadgen(&tmp);
	while (tmp)
	{
		i = tmp->var->nbr_of_philo;
		while (i)
		{
			if (tmp->death == TRUE)
			{
				ft_mutprint(tmp, P_DEATH);
				return (NULL);
			}
			else if (tmp->death == ERROR)
			{
				pthread_mutex_lock(&tmp->var->print);
				printf("%ld every philosopher ate %d times\n", tmp->act_time - tmp->start_time, tmp->var->nbr_time_philo_eat);
				pthread_mutex_unlock(&tmp->var->print);
				return (NULL);
			}
			tmp = tmp->next;
			i--;
		}
		usleep(1000);
	}
	i = tmp->var->nbr_of_philo;
	while (i)
	{
		pthread_join(*tmp->id_philo, NULL);
		tmp = tmp->next;
		i--;
	}
	i = tmp->var->nbr_of_philo;
	while (i)
	{
		pthread_detach(*tmp->id_philo);
		free(tmp->id_philo);
		tmp = tmp->next;
		i--;
	}
	return (NULL);
}

void	ft_threadgen(t_diner **diner)
{
	int		i;
	t_diner	*tmp;

	tmp = *diner;
	i = tmp->var->nbr_of_philo;
	while (i)
	{
		tmp->id_philo = malloc(sizeof(pthread_t));
		if (ft_threrr(pthread_create(tmp->id_philo, NULL, ft_think, (void *)tmp), &tmp) == TRUE)
			ft_exit(&tmp, FALSE);
		i--;
		tmp = tmp->next;
	}
}

void	ft_forkunlock(t_diner **diner)
{
	int		i;
	t_diner	*tmp;

	tmp = *diner;
	i = tmp->var->nbr_of_philo;
	while (i)
	{
		tmp->free_fork = TRUE;
		i--;
		tmp = tmp->next;
	}
}
