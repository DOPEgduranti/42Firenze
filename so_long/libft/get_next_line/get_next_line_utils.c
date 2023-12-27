/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:56:02 by gduranti          #+#    #+#             */
/*   Updated: 2023/12/04 16:09:36 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_bool	ft_feedline(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (FALSE);
	while (s[i])
	{
		if (s[i] == '\n')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*ft_newstrjoin(char *sta_str, char *buff)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!buff)
		return (NULL);
	if (!sta_str)
		sta_str = ft_calloc(1, sizeof(char));
	if (!sta_str)
		return (NULL);
	res = ft_calloc((ft_strlen(sta_str) + ft_strlen(buff) + 1), sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	if (sta_str)
		while (sta_str[++i] != '\0')
			res[i] = sta_str[i];
	while (buff[j] != '\0')
		res[i++] = buff[j++];
	res[ft_strlen(sta_str) + ft_strlen(buff)] = '\0';
	free(sta_str);
	return (res);
}
