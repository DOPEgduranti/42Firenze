/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:04 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/30 11:10:41 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philodeath(void *diner)
{
	long	die;
	int		i;
	t_bool	flag;
	t_diner	*lst;

	die = ((t_diner *)diner)->var->time_to_die / 1000;
	lst = (t_diner *)diner;
	// ft_threadgen(&lst);
	flag = TRUE;
	while (flag == TRUE)
	{
		//printf(" actual time [%ld]\tlast meal[%ld]\ttime to die[%ld]\n",ft_get_time() - lst->start_time,lst->last_meal - lst->start_time,tmp->time_to_die / 1000);
		pthread_mutex_lock(&lst->var->look);
		if (ft_get_time() > lst->last_meal + die)
		{
			pthread_mutex_unlock(&lst->var->look);
			ft_mutprint(lst, P_DEATH);
			flag = FALSE;
			pthread_mutex_lock(&lst->var->finish);
			lst->var->stop = TRUE;
			pthread_mutex_unlock(&lst->var->finish);
		}
		else
			pthread_mutex_unlock(&lst->var->look);
		lst = lst->next;
		//usleep(1000);
	}
	// printf("ciao");
	i = lst->var->nbr_of_philo;
	while (i)
	{
		// printf("ciao");
		pthread_join(lst->id_philo, NULL);
		lst = lst->next;
		i--;
	}
	// i = tmp->nbr_of_philo;
	// while (i)
	// {
	// 	pthread_detach(lst->id_philo);
	// 	lst = lst->next;
	// 	i--;
	// }
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
		if (ft_threrr(pthread_create(&tmp->id_philo, NULL, ft_think, (void *)tmp), diner) == TRUE)
			ft_exit(diner, FALSE);
		i--;
		tmp = tmp->next;
	}
}

t_bool	ft_checkdeath(t_diner *diner)
{
	// printf("[%d]", diner->var->stop);
	pthread_mutex_lock(&diner->var->finish);
	if (diner->var->stop == TRUE)
	{
		pthread_mutex_unlock(&diner->var->finish);
		return (TRUE);
	}
	else
		pthread_mutex_unlock(&diner->var->finish);
	return (FALSE);
}
