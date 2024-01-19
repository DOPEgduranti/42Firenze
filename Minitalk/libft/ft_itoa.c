/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 12:47:41 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/12 16:42:10 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_ndigits(long n)
{
	unsigned int	digits;

	digits = 1;
	if (n < 0)
		digits++;
	while (n / 10 != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

static void	ft_result(char *dst, long n, size_t *p_i)
{
	char	c;

	if (n < 10)
	{
		c = n + '0';
		n /= 10;
		dst[*p_i] = c;
		*p_i += 1;
	}
	if (n % 10 != 0 || n / 10 != 0)
	{
		c = (n % 10) + '0';
		n /= 10;
		ft_result(dst, n, p_i);
		dst[*p_i] = c;
		*p_i += 1;
	}
}

char	*ft_itoa(int n)
{
	char	*dst;
	size_t	i;
	long	l;

	i = 0;
	l = (long)n;
	dst = (char *)malloc((ft_ndigits(l) + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	if (l < 0)
	{
		dst[i] = '-';
		i++;
		l *= -1;
	}
	ft_result (dst, l, &i);
	dst[i] = '\0';
	return (dst);
}
/*
#include <stdio.h>
int	main(void)
{
	printf("%s\n", ft_itoa(400200));
	printf("%s\n", ft_itoa(-400200));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}*/
