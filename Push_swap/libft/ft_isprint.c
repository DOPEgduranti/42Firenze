/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:16:17 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/09 11:27:59 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (16384);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int     main(void)
{
        char    c = ' ';

        printf("originale : %d\n", isprint(c));
        printf("mio : %d\n", ft_isprint(c));
        return (0);
}*/
