/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:09:35 by gduranti          #+#    #+#             */
/*   Updated: 2024/02/05 10:40:40 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

void	ft_semprint(t_diner *diner, t_data *data, int action)
{
	long	current;

	sem_wait(data->death);
	if (diner->imdead == TRUE)
		return ;
	else
		sem_post(data->death);
	sem_wait(data->print);
	current = ft_get_time();
	if (action == P_DEATH)
		printf("%ld %d Morto\n", current - data->starttime, diner->tag);
	if (action == P_EAT)
		printf("%ld %d Mangio\n", current - data->starttime, diner->tag);
	if (action == P_THINK)
		printf("%ld %d Penso\n", current - data->starttime, diner->tag);
	if (action == P_SLEEP)
		printf("%ld %d Dormo\n", current - data->starttime, diner->tag);
	if (action == P_FORK)
		printf("%ld %d Piglio una forchetta\n", current - data->starttime, diner->tag);
	sem_post(data->print);
}

void	ft_unlink(void)
{
	sem_unlink("Chopstick");
	sem_unlink("Print");
	sem_unlink("Full");
	sem_unlink("Death");
	sem_unlink("Semafero");
	sem_unlink("Dieall");
	sem_unlink("Meal");
}
/*
void	ft_exit(t_diner **diner, t_bool status)
{
	ft_dinerclear(diner);
	if (status == TRUE)
		exit(EXIT_SUCCESS);
	exit(EXIT_FAILURE);
}

t_bool	ft_go_print(t_diner *diner)
{
	if (diner->var->stop == TRUE)
		return (FALSE);
	return (TRUE);
}

void	ft_mutprint(t_diner *diner, int action)
{
	if (ft_go_print(diner) == FALSE)
		return ;
	diner->act_time = ft_get_time();
	if (action == P_THINK)
		printf("%ld %d is thinking\n", diner->act_time - diner->start_time,
			diner->tag);
	else if (action == P_FORK)
		printf("%ld %d has taken a fork\n", diner->act_time - diner->start_time,
			diner->tag);
	else if (action == P_EAT)
		printf("%ld %d is eating\n", diner->last_meal - diner->start_time,
			diner->tag);
	else if (action == P_SLEEP)
		printf("%ld %d is sleeping\n", diner->act_time - diner->start_time,
			diner->tag);
	else if (action == P_DEATH)
		printf("%ld %d died\n", diner->act_time - diner->start_time,
			diner->tag);
	else if (action == P_FINISH)
		printf("%ld every philosopher ate %d times\n", diner->act_time
			- diner->start_time, diner->var->nbr_time_philo_eat);
}*/
