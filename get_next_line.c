/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:43:03 by eslamber          #+#    #+#             */
/*   Updated: 2022/12/08 11:41:40 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*buff[BUFFER_SIZE];
	char		*line;
	ssize_t		ret_read;

	ret_read = read(fd, buff, BUFFER_SIZE);
	if (ret_read <= 0)
		return (0);
	printf("test = %zd\n", ret_read);
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	test;

	printf("%s\n", argv[1]);
	fd = open(argv[1], O_RDWR);
	get_next_line(fd);
	close(fd);
	printf("AAA\n");
	return (0);
}
