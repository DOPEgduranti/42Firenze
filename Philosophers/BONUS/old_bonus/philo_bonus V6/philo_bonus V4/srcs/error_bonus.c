/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:14:24 by gduranti          #+#    #+#             */
/*   Updated: 2024/02/02 15:16:08 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_bool	ft_malloc_err(void *ptr)
{
	if (!ptr)
	{
		write(2, "Error: Unexpected malloc behaviour\n", 35);
		exit(EXIT_FAILURE);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_argc_err(int argc)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "Error: Wrong input\n", 19);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_threrr(int info, t_data *data)
{
	if (info == 0)
		return (FALSE);
	write(2, "Error: thread can't be created\n", 31);
	ft_freedata(data);
	return (TRUE);
}

void	ft_sem_err(t_data *data, int i)
{
	if (i == 1 && data->chopstick == SEM_FAILED)
	{
		printf("error1");
		free(data->diner);
		free(data);
		exit(EXIT_FAILURE);
	}
	else if (i == 2 && data->full == SEM_FAILED)
	{
		printf("error2");
		sem_close(data->chopstick);
		free(data->diner);
		free(data);
		exit(EXIT_FAILURE);
	}
	else if (i == 3 && data->print == SEM_FAILED)
	{
		printf("error3");
		sem_close(data->full);
		sem_close(data->chopstick);
		free(data->diner);
		free(data);
		exit(EXIT_FAILURE);
	}
	else if (i == 4 && data->death == SEM_FAILED)
	{
		printf("error4");
		sem_close(data->full);
		sem_close(data->chopstick);
		sem_close(data->print);
		free(data->diner);
		free(data);
		exit(EXIT_FAILURE);
	}
	else if (i == 5 && data->death == SEM_FAILED)
	{
		printf("error5");
		sem_close(data->full);
		sem_close(data->chopstick);
		sem_close(data->print);
		sem_close(data->death);
		free(data->diner);
		free(data);
		exit(EXIT_FAILURE);
	}
}
