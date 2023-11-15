/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 10:59:19 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/09 11:08:22 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (8);
	if (c >= 'a' && c <= 'z')
		return (8);
	if (c >= '0' && c <= '9')
		return (8);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
	char	c = '5';

	printf("originale : %d\n", isalnum(c));
	printf("mio : %d\n", ft_isalnum(c));
	return (0);
}*/
