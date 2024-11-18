/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafael <rafael@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:05:54 by rafael            #+#    #+#             */
/*   Updated: 2024/11/18 12:29:36 by rafael           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			bytes_read;

	line = NULL;
	bytes_read = 1;
	while (bytes_read > 0)
	{
		line = ft_joinmod(line, buffer);
		if (!line)
			return (NULL);
		if (*line != '\0' && line[ft_strlen(line) - 1] == '\n')
			break ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read >= 0)
			buffer[bytes_read] = '\0';
		if ((bytes_read == 0 && *line == '\0') || bytes_read < 0)
		{
			*buffer = '\0';
			free(line);
			return (NULL);
		}
	}
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("!%s!\n", line);
	line = get_next_line(-1);
	printf("!%s!\n", line);
	line = get_next_line(fd);
	printf("!%s!\n", line);
	line = get_next_line(fd);
	printf("!%s!\n", line);
	line = get_next_line(fd);


	char buffer[1024+1];
	int read_bytes;
	buffer[1024] = '\0';
	while(buffer[0] != 'E' && buffer[1] != '\n')
	{
		printf("Quer uma nova linha, de enter to Exit (E\n):");
		read_bytes = read(0,buffer,1024);
		if(buffer[0] == 'E' && buffer[1] == '\n')
			break;
		printf("%s", get_next_line(fd));
	}

	return (0);


}
*/


