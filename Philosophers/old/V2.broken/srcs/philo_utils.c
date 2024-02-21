/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 11:09:35 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/19 12:06:21 by gduranti         ###   ########.fr       */
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
		printf("%ld\t%d has taken a fork\n\n", ft_get_time() - diner->start_time, diner->tag);
	if (pthread_mutex_lock(&diner->next->id_fork) == 0)
		printf("%ld\t%d has taken a fork\n\n", ft_get_time() - diner->start_time, diner->tag);
	diner->last_meal = ft_get_time();
}

u_int64_t	ft_get_time(void)
{
	struct timeval	tv;
	
	gettimeofday(&tv, NULL);
	return ((tv.tv_usec / 1000));
}

int	ft_usleep(useconds_t time)
{
	u_int64_t	start;
	start = ft_get_time();
	while ((ft_get_time() - start) < time)
		usleep(time / 10);
	return(0);
}
