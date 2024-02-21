/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:46:42 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/17 11:41:43 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_table *ft_table_set(int argc, char **argv)
{
	t_table *table;

	table = malloc(sizeof(t_table));
	if (ft_malloc_err(table) == TRUE)
		exit(0);
	table->nbr_of_philo = ft_atoi(argv[1]);
	if (table->nbr_of_philo == 0)
		table->nbr_of_philo = NUMBER_OF_PHILO;
	table->nbr_fork = table->nbr_of_philo;
	table->time_to_die = ft_atoi(argv[2]);
	if (table->time_to_die == 0)
		table->time_to_die = TIME_TO_DIE;
	table->time_to_eat = ft_atoi(argv[3]);
	if (table->time_to_eat == 0)
		table->time_to_eat = TIME_TO_EAT;
	table->time_to_sleep = ft_atoi(argv[4]);
	if (table->time_to_sleep == 0)
		table->time_to_sleep = TIME_TO_SLEEP;
	if (argc == 6)
		table->nbr_time_philo_eat = ft_atoi(argv[5]);
	else
		table->nbr_time_philo_eat = 0;
	return (table);
}

t_diner	*ft_diner_set(t_table **table)
{
	t_diner	*diner;
	int		i;

	diner = NULL;
	i = (*table)->nbr_of_philo;
	while (i > 1)
	{
		ft_dineradd_back(&diner, ft_dinernew(table));
		i--;
		usleep(100);
	}
	ft_dineradd_last(&diner, ft_dinernew(table));
	usleep(100);
	return (diner);
}
