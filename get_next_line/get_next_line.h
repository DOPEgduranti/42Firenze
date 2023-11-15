/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gduranti <gduranti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:40:32 by gduranti          #+#    #+#             */
/*   Updated: 2023/11/06 12:45:42 by gduranti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef int	t_bool;

char	*get_next_line(int fd);
char	*ft_readbuff(char *sta_str, int fd);
size_t	ft_strlen(char *str);
t_bool	ft_feedline(char *s);
char	*ft_strjoin(char *sta_str, char *buf);
char	*ft_dstset(char *sta_str);
char	*ft_stastrset(char *sta_str);
void	*ft_calloc(size_t nmemb, size_t size);

#endif