/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:09:35 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/22 15:22:31 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		res;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res += nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_exit(t_diner **diner, t_bool status)
{
	ft_dinerclear(diner);
	if (status == TRUE)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

void	ft_takefork(t_diner *diner)
{
	if (pthread_mutex_lock(&diner->id_fork) == 0)
		ft_mutprint(diner, P_FORK);
	if (pthread_mutex_lock(&diner->next->id_fork) == 0)
		ft_mutprint(diner, P_FORK);
	gettimeofday(&diner->last_meal, NULL);
}

void	ft_mutprint(t_diner *diner, int action)
{
	gettimeofday(&diner->act_time, NULL);
	pthread_mutex_lock(&diner->var->print);
	if (action == P_THINK)
		printf("%ld %d is thinking\n", diner->act_time.tv_usec - diner->start_time.tv_usec, diner->tag);
	else if (action == P_FORK)
		printf("%ld %d has taken a fork\n", diner->act_time.tv_usec - diner->start_time.tv_usec, diner->tag);
	else if (action == P_EAT)
		printf("%ld %d is eating\n", diner->last_meal.tv_usec - diner->start_time.tv_usec, diner->tag);
	else if (action == P_SLEEP)
		printf("%ld %d is sleeping\n", diner->act_time.tv_usec - diner->start_time.tv_usec, diner->tag);
	else if (action == P_DEATH)
		printf("%ld %d died\n", diner->act_time.tv_usec - diner->start_time.tv_usec, diner->tag);
	else if (action == P_FINISH)
		printf("%ld every philosopher ate %d times\n", diner->act_time.tv_usec - diner->start_time.tv_usec, diner->var->nbr_time_philo_eat);
	pthread_mutex_unlock(&diner->var->print);
}
