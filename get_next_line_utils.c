/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:32:45 by rafael            #+#    #+#             */
/*   Updated: 2024/11/20 09:07:52 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	getlen(char *str)
{
	size_t	i;

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

char	*ft_joinmod(char *line, char *buf)
{
	char	*aux;
	size_t	len_buf;
	size_t	i;
	size_t	len_line;

	len_buf = getlen(buf);
	len_line = ft_strlen(line);
	aux = (char *)malloc(sizeof(char) * (len_line) + len_buf + 1);
	if (!aux)
		return (free(line), NULL);
	i = -1;
	while (++i < len_line)
		aux[i] = line[i];
	i--;
	while (++i - len_line < len_buf)
		aux[i] = buf[(i) - len_line];
	if (buf[i - len_line] == '\n')
		aux[i] = '\n';
	aux[len_line + len_buf] = '\0';
	i = -1;
	while (++i < (ft_strlen(buf) - len_buf))
		buf[i] = buf[len_buf + i];
	buf[ft_strlen(buf) - len_buf] = '\0';
	buf[i] = '\0';
	return (free(line), aux);
}
