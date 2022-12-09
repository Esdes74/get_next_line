/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:43:03 by eslamber          #+#    #+#             */
/*   Updated: 2022/12/08 14:32:19 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

static void	is_end_line(char *line, char *buff, ssize_t ret_read)
{
	char	*end;

	if ((end = ft_strnstr(buff, "\n", BUFFER_SIZE)) == 0)
	{
		line = ft_strjoin(line, buff);
	}
	else
	{
		end[0] = '\0';
		line = ft_strjoin(line, buff);
		// printf("%s", line);
		line = ft_strjoin(line, "\n");
	}
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		ret_read;
	int			flag;

	flag = 0;
	ret_read = 1;
	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	line[0] = 0;
	while (ret_read > 0 && flag == 0)
	{
		ret_read = read(fd, buff, BUFFER_SIZE);
		buff[ret_read] = 0;
		if (ret_read <= 0 && !buff[0])
			return (0);
		line = ft_strjoin(line, buff);
		if (ft_strnstr(buff, "\n", BUFFER_SIZE) != 0)
			flag = 1;
	}
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	test;

	fd = open(argv[1], O_RDWR);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
