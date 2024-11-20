/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:32:45 by rafael            #+#    #+#             */
/*   Updated: 2024/11/20 00:00:31 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	getendposline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] != '\n')
		return (ft_strlen(str));
	return (++i);
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

char	*ft_joinmod(char *line, char *buf, size_t s_line)
{
	char	*aux;
	size_t	pos;
	size_t	i;

	aux = (char *)malloc(sizeof(char) * (s_line) + getendposline(buf) + 1);
	if (!aux)
		return (free(line), NULL);
	i = -1;
	while (++i < s_line)
		aux[i] = line[i];
	i--;
	while (++i - s_line < ft_strlen(buf) && buf[i - s_line] != '\n')
		aux[i] = buf[(i) - s_line];
	if (buf[i - s_line] == '\n')
		aux[i] = '\n';
	aux[s_line + getendposline(buf)] = '\0';
	pos = getendposline(buf);
	i = -1;
	while (++i < (ft_strlen(buf) - pos))
		buf[i] = buf[pos + i];
	buf[ft_strlen(buf) - pos] = '\0';
	if (ft_strlen(aux) > 0 && aux[ft_strlen(aux) - 1] != '\n')
		*buf = '\0';
	free(line);
	return (aux);
}
