/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:14:24 by gduranti          #+#    #+#             */
/*   Updated: 2024/01/19 09:37:33 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	ft_malloc_err(void *ptr)
{
	if (!ptr)
	{
		write(2, "Error: Unexpected malloc behaviour", 34);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_argc_err(int argc)
{
	if (argc != 5 && argc != 6)
	{
		write(2, "Error: Wrong input", 18);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_muterr(int info, t_diner **diner)
{
	if (info == 0)
		return (FALSE);
	write(2, "Error: mutex init failed", 24);
	ft_dinerclear(diner);
	return (TRUE);
}

t_bool	ft_threrr(int info, t_diner **diner)
{
	if (info == 0)
		return (FALSE);
	write(2, "Error: thread can't be created", 30);
	ft_dinerclear(diner);
	return (TRUE);
}
