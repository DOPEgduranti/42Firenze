/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 10:40:59 by gduranti          #+#    #+#             */
/*   Updated: 2023/10/18 16:41:32 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_mtxsize(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
			i--;
		}
		if (s[i] == '\0')
			return (count);
		i++;
	}
	return (count);
}

static char	*ft_row(char const *s, size_t start, size_t end)
{
	size_t	i;
	char	*row;

	i = 0;
	row = (char *)malloc((end - start + 1) * sizeof(char));
	if (!row)
		return (NULL);
	while (start < end)
	{
		row[i] = s[start];
		start++;
		i++;
	}
	row[i] = '\0';
	return (row);
}

static void	ft_mtxdel(char ***mtx)
{
	size_t	i;

	i = 0;
	while ((*mtx)[i])
	{
		free((*mtx)[i]);
		i++;
	}
	free(*mtx);
	mtx = NULL;
}

static char	**ft_mtxalloc(char const *s, char c, size_t *start, size_t *end)
{
	size_t	i;
	char	**mtx;

	i = 0;
	mtx = (char **)malloc((ft_mtxsize(s, c) + 1) * sizeof(char *));
	if (!mtx)
		return (NULL);
	while (i < (ft_mtxsize(s, c)))
	{
		while (s[*start] && s[*start] == c)
			(*start)++;
		*end = *start;
		while (s[*end] && s[*end] != c)
			(*end)++;
		mtx[i] = ft_row(s, *start, *end);
		if (!mtx[i])
		{
			ft_mtxdel(&mtx);
			return (NULL);
		}
		*start = *end;
		i++;
	}
	mtx[i] = NULL;
	return (mtx);
}

char	**ft_split(char const *s, char c)
{
	char	**mtx;
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	mtx = ft_mtxalloc(s, c, &start, &end);
	return (mtx);
}
/*
#include <stdio.h>
int	main(void)
{
	char	**mtx = ft_split(" caro amico ti sctivo ! ", ' ');
	size_t	i = 0;

	while (mtx[i])
	{
		printf("mtx[%ld] : %s\n", i, mtx[i]);
		i++;
	}
	return (0);
}*/
