/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:13:24 by gduranti          #+#    #+#             */
/*   Updated: 2024/02/02 12:45:39 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_checkdeath(void *arg)
{
	t_diner	*diner;
	t_bool	check;

	diner = (t_diner *)arg;
	check = FALSE;
	while (check == FALSE)
	{
		if (ft_get_time() > diner->lastmeal + diner->var.time_to_die / 1000)
		{
			printf("last meal %ld\n",diner->lastmeal);
			ft_semprint(diner, diner->data, P_DEATH);
			sem_wait(diner->data->death);
			diner->data->b_death = TRUE;
			sem_post(diner->data->death);
			check = TRUE;
		}
	}
	return (NULL);
}

void	ft_think(t_data *data, t_diner *diner)
{
	sem_wait(data->death);
	if (data->b_death == TRUE)
	{
		write(1,"ciao\n",5);
		sem_post(data->death);
		return ;
	}
	else
		sem_post(data->death);
	ft_semprint(diner, data, P_THINK);
	if (diner->tag % 2 == 0 && diner->mealgot == 0)
		ft_usleep(diner->var.time_to_eat / 2);
	sem_wait(data->chopstick);
	ft_semprint(diner, data, P_FORK);
	if (sem_wait(data->chopstick) != 0)
	{
		sem_post(data->chopstick);
		ft_semprint(diner, data, P_DEATH);
		ft_think(data, diner);
	}
	ft_semprint(diner, data, P_FORK);
	ft_eat(data, diner);
}

void	ft_eat(t_data *data, t_diner *diner)
{
	sem_wait(data->death);
	if (data->b_death == TRUE)
	{
		sem_post(data->death);
		ft_think(data, diner);
	}
	else
		sem_post(data->death);
	ft_semprint(diner, data, P_EAT);
	diner->lastmeal = ft_get_time();
	diner->mealgot++;
	if (data->var.time_to_eat > data->var.time_to_die)
	{	
		ft_usleep(data->var.time_to_die);
		sem_post(data->chopstick);
		sem_post(data->chopstick);
		ft_think(data, diner);
	}	
	else
	{
		ft_usleep(data->var.time_to_eat);
		sem_post(data->chopstick);
		sem_post(data->chopstick);
	}
	ft_sleep(data, diner);
}

void	ft_sleep(t_data *data, t_diner *diner)
{
	sem_wait(data->death);
	if (data->b_death == TRUE)
	{
		sem_post(data->death);
		ft_think(data, diner);
	}
	else
		sem_post(data->death);
	ft_semprint(diner, data, P_SLEEP);
	if (data->var.time_to_eat + data->var.time_to_sleep > data->var.time_to_die)
		ft_usleep(data->var.time_to_die - data->var.time_to_eat);
	else
		ft_usleep(data->var.time_to_sleep);
 	ft_think(data, diner);
}

void	ft_test(t_data *data, t_diner *diner)
{
	sleep(2);
	ft_semprint(diner, data, P_SLEEP);
	//ft_freedata(data);
 	exit(EXIT_SUCCESS);	
}