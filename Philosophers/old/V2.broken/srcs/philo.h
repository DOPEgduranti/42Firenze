/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:35:45 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/19 12:26:45 by gduranti         ###   ########.fr       */
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
#include <sys/types.h>

# define NUMBER_OF_PHILO 5
# define TIME_TO_DIE   10000000
# define TIME_TO_EAT   2000000
# define TIME_TO_SLEEP 1000000

typedef enum e_bool
{
	FALSE,
	TRUE,
	ERROR = -1
}	t_bool;

typedef struct s_var
{
	int				nbr_fork;
	int				nbr_of_philo;
	u_int64_t		time_to_die;
	u_int64_t		time_to_eat;
	u_int64_t		time_to_sleep;
	int 			nbr_time_philo_eat;
}	t_var;

typedef struct s_diner
{
	t_var			var;
	int				tag;
	pthread_t		id_philo;
	pthread_mutex_t	id_fork;
	t_bool			free_fork;
	u_int64_t		last_meal;
	u_int64_t		act_time;
	u_int64_t		start_time;
	struct s_diner	*next;
	int				meal_got;
}	t_diner;

//philo_utils.c
int			ft_atoi(const char *nptr);
void		ft_exit(t_diner **diner, t_bool status);
void		ft_takefork(t_diner *diner);
u_int64_t	ft_get_time(void);
int			ft_usleep(useconds_t time);
//input.c
t_var 		ft_var_set(int ac, char **av);
t_diner		*ft_diner_set(t_var var);
//error.c
t_bool		ft_malloc_err(void *ptr);
t_bool		ft_argc_err(int argc);
t_bool		ft_muterr(int info, t_diner **diner);
t_bool		ft_threrr(int info, t_diner **diner);
//list_utils.c
t_diner		*ft_dinernew(t_diner **diner, t_var var);
void		ft_dinerclear(t_diner **lst);
void		ft_dineradd_back(t_diner **lst, t_diner *new);
void		ft_dineradd_last(t_diner **lst, t_diner *new);
t_diner		*ft_dinerlast(t_diner **diner);
//actions.c
void		ft_sleep(t_diner *diner);
void		ft_eat(t_diner *diner);
void		*ft_think(void *diner1);
void		ft_begin(t_diner *diner);

#endif