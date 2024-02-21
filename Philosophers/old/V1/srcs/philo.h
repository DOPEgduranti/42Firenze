/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:35:45 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/17 11:47:15 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# define NUMBER_OF_PHILO 5
# define TIME_TO_DIE 2000
# define TIME_TO_EAT 1000
# define TIME_TO_SLEEP 1000

typedef enum e_bool
{
	FALSE,
	TRUE,
	ERROR = -1
}	t_bool;

typedef struct s_diner
{
	int				tag;
	pthread_t		id_philo;
	pthread_mutex_t	id_fork;
	t_bool			free_fork;
	struct s_diner	*next;
}	t_diner;

typedef struct s_table
{
	int		nbr_fork;
	int		nbr_of_philo;
	int		time_to_die;
	int 	time_to_eat;
	int		time_to_sleep;
	int 	nbr_time_philo_eat;
	t_diner	*diner;
}	t_table;

int		ft_atoi(const char *nptr);
t_table	*ft_table_set(int argc, char **argv);

t_diner	*ft_dinernew(t_table **table);
void	ft_dinerclear(t_diner **lst);
void	ft_dineradd_back(t_diner **lst, t_diner *new);
void	ft_dineradd_last(t_diner **lst, t_diner *new);
t_diner	*ft_dinerlast(t_diner **diner);

t_bool	ft_malloc_err(void *ptr);
t_diner	*ft_diner_set(t_table **table);
t_bool	ft_argc_err(int argc);

void	*ft_think(void *table);

#endif