/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:46:42 by gduranti          #+#    #+#             */
/*   Updated: 2024/02/02 15:23:39 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_var	ft_var_set(int ac, char **av)
{
	t_var	var;

	var.nbr_of_philo = ft_atoi(av[1]);
	var.time_to_die = ft_atoi(av[2]) * 1000;
	var.time_to_eat = ft_atoi(av[3]) * 1000;
	var.time_to_sleep = ft_atoi(av[4]) * 1000;
	var.nbr_time_philo_eat = 0;
	if (ac == 6)
		var.nbr_time_philo_eat = ft_atoi(av[5]);
	ft_inputcheck(var);
	// if (ft_solo(var) == TRUE)
	// 	return (var);
	return (var);
}

t_bool	ft_inputcheck(t_var var)
{
	if (var.nbr_of_philo > 0 && var.time_to_die > 0 && var.time_to_eat > 0
		&& var.time_to_sleep > 0 && var.nbr_time_philo_eat >= 0)
		return (TRUE);
	write(2, "Error: Wrong input\n", 19);
	exit (EXIT_SUCCESS);
}

t_data	*ft_datagen(int ac, char **av)
{
	t_data	*data;
	
	data = malloc(sizeof(*data));
	ft_malloc_err(data);
	data->var = ft_var_set(ac, av);
	data->diner = malloc(data->var.nbr_of_philo * sizeof(t_diner));
	ft_malloc_err(data->diner);
	data->chopstick = sem_open("Chopstick", O_CREAT, 0666, data->var.nbr_of_philo);
	ft_sem_err(data, 1);
	data->full = sem_open("Full", O_CREAT, 0666, 1);
	ft_sem_err(data, 2);
	data->print = sem_open("Print", O_CREAT, 0666, 1);
	ft_sem_err(data, 3);
	data->death = sem_open("Death", O_CREAT, 0666, 1);
	ft_sem_err(data, 4);
	data->semafero = sem_open("Semafero", O_CREAT, 0666, 1);
	ft_sem_err(data, 5);
	data->total_meal = 0;
	data->i_full = 0;
	data->b_death = FALSE;
	return (data);
}

void	ft_philo_init(t_diner *diner, t_data *data, int i)
{
	diner->mealgot = 0;
	diner->lastmeal = ft_get_time();
	diner->tag = i + 1;
	diner->starttime = data->starttime;
	diner->data = data;
	if(ft_threrr(pthread_create(&diner->undertaker, NULL, ft_checkdeath, diner), data) == TRUE)
		exit(EXIT_FAILURE);
}

void	ft_philo_gen(t_data *data)
{
	int	i;
	
	i = 0;
	data->starttime = ft_get_time();
	while(i < data->var.nbr_of_philo)
	{
		data->diner[i].pid = fork();
		if (data->diner[i].pid == -1)
		{
			printf("error");
			exit(EXIT_FAILURE);
		}
		else if (data->diner[i].pid == 0)
		{
			data->diner[i].var = data->var;
			ft_philo_init(&data->diner[i], data, i);
			ft_think(data, &data->diner[i]);
			ft_freedata(data);
			exit(0);
		}
		i++;
		usleep(100);
	}
}
