/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:43:03 by eslamber          #+#    #+#             */
/*   Updated: 2022/12/09 09:5 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

// static void	is_end_line(char *line, char *buff)
// {
// 	char	*end;

// 	end = ft_strnstr(buff, "\n", BUFFER_SIZE);
// 	if (end == 0)
// 	{
// 		line = ft_strjoin(line, buff);
// 	}
// 	else
// 	{
// 		end[0] = '\0';
// 		line = ft_strjoin(line, buff);
// 		line = ft_strjoin(line, "\n");
// 	}
// }

static char	*ft_strjoin(char *dest, char *src)
{
	size_t	len_tot;
	char	*new;

	if (dest == 0 && src == 0)
		return (NULL);
	if (dest == 0)
		return (ft_strdup(src));
	if (src == 0)
		return (ft_strdup(dest));
	len_tot = ft_strlen(dest) + ft_strlen(src) + 1;
	new = (char *) malloc(sizeof(char) * len_tot);
	if (new == 0)
		return (0);
	new[0] = '\0';
	ft_strlcat(new, dest, len_tot);
	ft_strlcat(new, src, len_tot);
	free(dest);
	return (new);
}

static void	treat(char *line, char *buff)
{
	size_t	ind;
	size_t	ind_buff;
	size_t	save_ind;

	ind = 0;
	while (line[ind] != '\0')
		if (line[ind++] == '\n')
			break ;
	ind_buff = 0;
	save_ind = ind;
	while (line[ind] != '\0' && ind_buff < BUFFER_SIZE)
		buff[ind_buff++] = line[ind++];
	ind = save_ind;
	while (line[ind] != '\0')
		line[ind++] = '\0';
	while (ind_buff < BUFFER_SIZE)
		buff[ind_buff++] = '\0';
}

static char	*read_line(char *line, char *buff, ssize_t ret, int fd)
{
	while (ft_in('\n', buff, BUFFER_SIZE) == 0 && \
	ft_in('\0', buff, BUFFER_SIZE) == 0 && ret != 0)
	{
		buff[ret] = 0;
		line = ft_strjoin(line, buff);
		if (!line)
			return (free(line), NULL);
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret <= 0 && !buff[0])
			return (free(line), buff[0] = 0, NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		read_ret;
	// int			flag;

	line = malloc(sizeof(char));
	if (!line)
		return (NULL);
	buff[BUFFER_SIZE] = 0;
	line[0] = 0;
	// flag = 0;
	if (buff[0] != 0)
	{
		line = ft_strjoin(line, buff);
		treat(line, buff);
		// flag = 1;
	}
	read_ret = read(fd, buff, BUFFER_SIZE);
	if (read_ret <= 0 && !buff[0])
		return (free(line), buff[0] = 0, NULL);
	line = read_line(line, buff, read_ret, fd);
	if (line == NULL)
		return (NULL);
	if (ft_in('\n', buff, BUFFER_SIZE) == 1 && line[0] == '\0')
		line = ft_strjoin(line, buff);
	// if (flag == 0)
	treat(line, buff);
	return (line);
}

// int	main(int argc, char **argv)
// {
// 	(void) argv;
// 	int	fd;
// 	int	test;

// 	fd = open("/Users/eslamber/francinette/temp/get_next_line/fsoares/multiple_nl.txt", O_RDWR);
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	printf("%s", get_next_line(fd));
// 	close(fd);
// 	return (0);
// }
