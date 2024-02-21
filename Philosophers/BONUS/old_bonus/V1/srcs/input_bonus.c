/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:46:42 by gduranti          #+#    #+#             */
/*   Updated: 2024/02/01 13:23:46 by gduranti         ###   ########.fr       */
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

t_data	ft_datagen(int ac, char **av)
{
	t_data	data;
	
	data.var = ft_var_set(ac, av);
	data.diner = malloc(data.var.nbr_of_philo * sizeof(t_diner));
	ft_malloc_err(data.diner);
	data.chopstick = sem_open("Chopsticks", O_CREAT, 0666, (unsigned int)data.var.nbr_of_philo);
	if (data.chopstick == SEM_FAILED) {
        perror("sem_open chopstick");
        exit(EXIT_FAILURE);
    }
	data.full = sem_open("Full", O_CREAT, 0666, 1);
	if (data.full == SEM_FAILED) {
        perror("sem_open full");
        exit(EXIT_FAILURE);
    }
	data.print = sem_open("Print", O_CREAT, 0666, 1);
	if (data.print == SEM_FAILED) {
        perror("sem_open print");
        exit(EXIT_FAILURE);
    }
	data.total_meal = 0;
	return (data);
}

void	ft_philo_gen(t_data data)
{
	int	i;
	
	i = 0;
	while(i < data.var.nbr_of_philo)
	{
		data.diner[i].pid = fork();
		if (data.diner[i].pid == -1)
		{
			printf("error");
			exit(EXIT_FAILURE);
		}
		else if (data.diner[i].pid == 0)
		{
			printf("philo[%d] is asleep\n", i);
			if(i % 2 == 0)
				sleep(4);
			if(i % 2 == 1)
				sleep(100);
			printf("philo[%d] is awake\n", i);
			exit(0);
		}
		printf("philo[%d] = %d\n", i, data.diner[i].pid);
		// printf("%d\n",getpid());
		i++;
	}
	printf("%d\n",getpid());
}
