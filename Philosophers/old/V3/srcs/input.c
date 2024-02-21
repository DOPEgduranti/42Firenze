/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:46:42 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/22 15:28:25 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_var *ft_var_set(int ac, char **av)
{
	t_var *var;

	var = malloc(sizeof(t_var));
	if (ft_malloc_err(var) == TRUE)
		exit (EXIT_FAILURE);
	pthread_mutex_init(&var->print, NULL);
	pthread_mutex_init(&var->look, NULL);
	var->nbr_of_philo = ft_atoi(av[1]);
	if (var->nbr_of_philo == 0)
		var->nbr_of_philo = NUMBER_OF_PHILO;
	var->nbr_fork = var->nbr_of_philo;
	var->time_to_die = ft_atoi(av[2]);
	if (var->time_to_die == 0)
		var->time_to_die = TIME_TO_DIE;
	var->time_to_eat = ft_atoi(av[3]);
	if (var->time_to_eat == 0)
		var->time_to_eat = TIME_TO_EAT;
	var->time_to_sleep = ft_atoi(av[4]);
	if (var->time_to_sleep == 0)
		var->time_to_sleep = TIME_TO_SLEEP;
	if (ac == 6)
		var->nbr_time_philo_eat = ft_atoi(av[5]);
	else
		var->nbr_time_philo_eat = 0;
	return (var);
}

t_diner	*ft_diner_set(t_var *var)
{
	t_diner	*diner;
	int		i;

	diner = NULL;
	i = var->nbr_of_philo;
	while (i > 1)
	{
		ft_dineradd_back(&diner, ft_dinernew(&diner, var));
		i--;
		// usleep(1);
	}
	ft_dineradd_last(&diner, ft_dinernew(&diner, var));
	// usleep(1);
	ft_begin(diner);
	i = var->nbr_of_philo;
	while (i > 0)
	{
		pthread_join(diner->id_philo, NULL);
		diner = diner->next;
		i--;
	}
	return (diner);
}
