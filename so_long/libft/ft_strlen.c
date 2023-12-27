/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:22:28 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/09 11:35:58 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
        char    c[] = "bella ciao !";

        printf("originale : %ld\n", strlen(c));
        printf("mio : %ld\n", ft_strlen(c));
        return (0);
}*/
