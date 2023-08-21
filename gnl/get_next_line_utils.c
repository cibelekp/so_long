/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 18:26:04 by ckojima-          #+#    #+#             */
/*   Updated: 2023/08/21 17:38:26 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero_gnl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		str[i++] = '\0';
}

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

// check newline, copy and clean stash
int	newline(char *stash)
{
	int	i;
	int	j;
	int	is_newline;

	i = 0;
	j = 0;
	is_newline = 0;
	while (stash[i])
	{
		if (is_newline)
			stash[j++] = stash[i];
		if (stash[i] == '\n')
			is_newline = 1;
		stash[i++] = '\0';
	}
	return (is_newline);
}

// joinline
char	*joinline(char *stored, char *stash)
{
	int		i;
	int		j;
	char	*full_line;

	full_line = malloc(ft_strlen_gnl(stored) + ft_strlen_gnl(stash) + 1);
	if (!full_line)
		return (NULL);
	i = 0;
	j = 0;
	while (stored && stored[i])
		full_line[j++] = stored[i++];
	if (stored)
		free (stored);
	i = 0;
	while (stash && stash[i])
	{
		full_line[j] = stash[i];
		j++;
		if (stash[i] == '\n')
			break ;
		i++;
	}
	full_line[j] = '\0';
	return (full_line);
}
