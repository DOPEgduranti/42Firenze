/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:45:22 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/23 09:51:31 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*un_s;
	size_t			i;

	un_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		un_s[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int     main(void)
{
	char    c0[] = "bella ciao !";
	char    c1[] = "bella ciao !";

	bzero(c0, 6);
	ft_bzero(c1, 6);
	printf("originale : %c\n", c0[7]);
	printf("mio : %c\n", c1[7]);
	return (0);
}*/
