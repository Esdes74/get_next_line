/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:43:03 by eslamber          #+#    #+#             */
/*   Updated: 2022/12/02 18:00:39 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*buff;
	char		*line;
	ssize_t		ret_read;

	ret_read = read(fd, buff, BUFFER_SIZE);
	if (ret_read >= 0)
		return (0);
	printf("test = %d\n", ret_read);
	return (line);
}

int	main(int argc, char **argv)
{
	int	fd;
	int	test;

	fd = open(argv[1], O_RDWR);
	get_next_line(fd);
	close(fd);
	printf("AAA\n");
	return (0);
}
/* #include <stdio.h> */

/* char	*get_next_line(int fd) */
/* { */
/* 	(void) fd; */

/* 	if (TEST == 5) */
/* 	{ */
/* 		printf("AAA\n"); */
/* 		return (0); */
/* 	} */
/* 	return (0); */
/* } */

/* int	main(void) */
/* { */
/* 	get_next_line(5); */
/* 	return (0); */
/* } */
