/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   haben.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:19:53 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/14 13:30:43 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

# ifndef BUFFER_SIZE
# define  BUFFER_SIZE 42
#endif

char *get_next_line(int fd)
{
	char c;
	char *buf;
	int rbytes = 0;
	int index = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * 1000000);
	if (!buf)
		return (NULL);
	rbytes = read(fd, &c, 1);
	while (rbytes > 0)
	{
		buf[index++] = c;
		if (c == '\n')
			break ;
		rbytes = read(fd, &c ,1);	
	}
	if (rbytes == -1)
		return (free(buf), NULL);
	buf[index] = '\0';
	return (buf);
}

int main(void)
{
	int fd = open("get_next_line.c", O_RDONLY);
	char *line;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		printf("%s", line);
		free(line);
	}
	close(fd);
}