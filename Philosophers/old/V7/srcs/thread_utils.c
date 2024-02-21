/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 12:44:04 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/31 09:29:35 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_philodeath(void *diner)
{
	t_bool	flag;
	t_diner	*lst;

	lst = (t_diner *)diner;
	flag = TRUE;
	while (flag == TRUE)
	{
		pthread_mutex_lock(&lst->var->look);
		if (ft_get_time() > lst->last_meal + lst->time_to_die / 1000)
		{
			pthread_mutex_unlock(&lst->var->look);
			flag = FALSE;
			ft_mutprint(lst, P_DEATH);
			pthread_mutex_lock(&lst->var->finish);
			lst->var->stop = TRUE;
			pthread_mutex_unlock(&lst->var->finish);
		}
		else
			pthread_mutex_unlock(&lst->var->look);
		lst = lst->next;
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
		if (ft_threrr(pthread_create(&tmp->id_philo, NULL, ft_think,
					(void *)tmp), diner) == TRUE)
			ft_exit(diner, FALSE);
		i--;
		tmp = tmp->next;
	}
}

t_bool	ft_checkdeath(t_diner *diner)
{
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

void	*ft_alone(void *arg)
{
	t_var	*var;
	long	begin;

	var = (t_var *)arg;
	begin = ft_get_time();
	pthread_mutex_lock(&var->print);
	printf("%ld 1 is thinking\n", ft_get_time() - begin);
	pthread_mutex_unlock(&var->print);
	ft_usleep(var->time_to_die);
	pthread_mutex_lock(&var->print);
	printf("%ld 1 died\n", ft_get_time() - begin);
	pthread_mutex_unlock(&var->print);
	return (NULL);
}

t_bool	ft_solo(t_var *var)
{
	pthread_t	my_thread;

	if (var->nbr_of_philo != 1)
		return (FALSE);
	if (ft_threrr(pthread_create(&my_thread, NULL, ft_alone,
				(void *)var), NULL) == TRUE)
		ft_exit(NULL, FALSE);
	pthread_join(my_thread, NULL);
	pthread_mutex_destroy(&var->print);
	free(var);
	return (TRUE);
}
