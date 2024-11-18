/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:32:45 by rafael            #+#    #+#             */
/*   Updated: 2024/11/18 11:51:42 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strchr(const char *s, int c)
{
	int	i;

	if ((char)c == 0)
		return (ft_strlen(s) - 1);
	i = 0;
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i])
		return (i);
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (dest == NULL || size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*
** It calculate the length of the received string
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_joinmod(char *line, char *buffer)
{
	char	*aux;
	int		pos;

	if (line == NULL)
	{
		line = (char *)malloc(sizeof(char));
		*line = '\0';
	}
	aux = malloc((ft_strlen(line) + ft_strlen(buffer) + 1) * sizeof(char));
	ft_strlcpy(aux, line, ft_strlen(line) + 1);
	if (buffer[ft_strchr(buffer, '\n')] == '\n')
		ft_strlcpy(aux + ft_strlen(line), buffer, ft_strchr(buffer, '\n') + 2);
	else
		ft_strlcpy(aux + ft_strlen(line), buffer, ft_strlen(buffer) + 1);
	free(line);
	pos = ft_strchr(buffer, '\n');
	if (buffer[pos] == '\n')
		ft_strlcpy(buffer, (buffer + pos + 1), ft_strlen(buffer) - pos + 1);
	else
		*buffer = '\0';
	return (aux);
}
