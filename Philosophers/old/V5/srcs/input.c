/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:46:42 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/25 12:42:04 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_var *ft_var_set(int ac, char **av)
{
	t_var *var;

	var = malloc(sizeof(t_var));
	if (ft_malloc_err(var) == TRUE)
		exit (EXIT_FAILURE);
	var->nbr_of_philo = ft_atoi(av[1]);
	if (var->nbr_of_philo <= 0)
		var->nbr_of_philo = NUMBER_OF_PHILO;
	var->nbr_fork = var->nbr_of_philo;
	var->time_to_die = ft_atoi(av[2]) * 1000;
	if (var->time_to_die <= 0)
		var->time_to_die = TIME_TO_DIE * 1000;
	var->time_to_eat = ft_atoi(av[3]) * 1000;
	if (var->time_to_eat <= 0)
		var->time_to_eat = TIME_TO_EAT * 1000;
	var->time_to_sleep = ft_atoi(av[4]) * 1000;
	if (var->time_to_sleep <= 0)
		var->time_to_sleep = TIME_TO_SLEEP * 1000;
	if (ac == 6)
		var->nbr_time_philo_eat = ft_atoi(av[5]);
	if (var->nbr_time_philo_eat <= 0)
		var->nbr_time_philo_eat = 0;
	var->full = 0;
	if (var->nbr_of_philo == 1)
	{
		printf("0 1 is thinking\n");
		usleep(var->time_to_die);
		printf("%ld 1 died\n", var->time_to_die / 1000);
		free(var);
		exit(EXIT_SUCCESS);
	}
	var->stop = FALSE;
	pthread_mutex_init(&var->print, NULL);
	pthread_mutex_init(&var->look, NULL);
	pthread_mutex_init(&var->eat, NULL);
	pthread_mutex_init(&var->finish, NULL);
	return (var);
}

t_diner	*ft_diner_set(t_var *var)
{
	t_diner	*diner;
	int		i;
	pthread_t	*undertaker;

	diner = NULL;
	i = var->nbr_of_philo;
	while (i > 1)
	{
		ft_dineradd_back(&diner, ft_dinernew(&diner, var));
		i--;
	}
	ft_dineradd_last(&diner, ft_dinernew(&diner, var));
	ft_begin(&diner);
	undertaker = malloc(sizeof(pthread_t));
	if (ft_threrr(pthread_create(undertaker, NULL, ft_philodeath, (void *)diner), &diner) == TRUE)
			ft_exit(&diner, FALSE);
	pthread_join(*undertaker, NULL);
	pthread_detach(*undertaker);
	free (undertaker);
	return (diner);
}
