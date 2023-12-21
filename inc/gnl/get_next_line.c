/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlumibao <mlumibao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 21:04:15 by mlumibao          #+#    #+#             */
/*   Updated: 2023/12/21 16:38:30 by mlumibao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*mbuf(char	*line)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	if (!line[0])
	{
		free(line);
		return (NULL);
	}
	while (line[i] && line[i] != '\n')
		i++;
	tmp = malloc(sizeof(char) * (ft_strlen_gnl(line) - i + 1));
	if (!tmp)
		return (NULL);
	if (line[i] == '\n')
		i++;
	j = 0;
	while (line[i])
		tmp[j++] = line[i++];
	tmp[j] = '\0';
	free (line);
	return (tmp);
}

char	*cutline(char	*line)
{
	char	*tmp;
	int		i;

	i = 0;
	if (line[0] == '\0')
		return (0);
	while (line[i] && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		tmp[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		tmp[i] = line[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*rngline(int fd, char *str)
{
	char		*buf;
	ssize_t		rbytes;

	buf = malloc(sizeof(char) * ((unsigned int)BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rbytes = 1;
	while (!ft_strchr_gnl(str, '\n') && rbytes != 0)
	{
		rbytes = read(fd, buf, BUFFER_SIZE);
		if (rbytes == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[rbytes] = '\0';
		str = ft_strjoin_gnl(str, buf);
	}
	free (buf);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*tmp;
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = rngline(fd, buf);
	if (!buf)
		return (NULL);
	tmp = cutline(buf);
	buf = mbuf(buf);
	return (tmp);
}

/* #include <stdio.h>
#include <fcntl.h>

int main()
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	fd = open("test.c", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		printf("%s", str);
	}
	close(fd);
}
 */