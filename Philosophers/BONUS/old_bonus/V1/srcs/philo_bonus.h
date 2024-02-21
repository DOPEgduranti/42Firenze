/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 09:34:53 by gduranti          #+#    #+#             */
/*   Updated: 2024/02/01 13:20:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef enum e_bool
{
	FALSE,
	TRUE,
	ERROR = -1
}	t_bool;

enum e_print
{
	P_THINK,
	P_FORK,
	P_EAT,
	P_SLEEP,
	P_DEATH,
	P_FINISH
};

typedef struct s_var
{
	int				nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nbr_time_philo_eat;
}	t_var;

typedef struct s_diner
{
	pid_t		pid;
	int 		status;
	pid_t 		finished_pid;
	int			mealgot;
	t_var		var;
}	t_diner;

typedef struct s_data
{
	t_diner	*diner;
	sem_t	*chopstick;
	sem_t	*print;
	sem_t	*full;
	int		total_meal;
	t_var	var;
}	t_data;

//time_utils_bonus.c
long	ft_get_time(void);
void	ft_usleep(long time);
//philo_utils_bonus.c
int		ft_atoi(const char *nptr);
// void	ft_exit(t_diner **diner, t_bool status);
// void	ft_mutprint(t_diner *diner, int action);
//input_bonus.c
t_var	ft_var_set(int ac, char **av);
t_bool	ft_inputcheck(t_var var);
t_data	ft_datagen(int ac, char **av);
void	ft_philo_gen(t_data data);
//error_bonus.c
t_bool	ft_malloc_err(void *ptr);
t_bool	ft_argc_err(int argc);
void	ft_sem_err(t_data data, int i);
// t_bool	ft_muterr(int info, t_diner **diner);
// t_bool	ft_threrr(int info, t_diner **diner);
//philo_end_bonus.c
int ft_wait(t_data data);

#endif