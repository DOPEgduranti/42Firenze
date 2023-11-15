/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:51:09 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/10 10:59:43 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <ctype.h>
#include <unistd.h>

int	main(void)
{
	char	c = 'h';
	char	r0 = toupper(c);
	char	r1 = ft_toupper(c);

	write(1, &r0, 1);
	write(1, &r1, 1);
	return (0);
}*/
