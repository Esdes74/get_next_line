/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:44:57 by eslamber          #+#    #+#             */
/*   Updated: 2022/12/12 13:29:53 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Return first occurence of little
int		ft_in(char src, char *test, size_t n);

// Return new string what is src concatenated to dest
char	*ft_strdup(const char *dest);

// Return length of s
size_t	ft_strlen(const char *s);

// Concatenate src to end of dest
size_t	ft_strlcat(char *dest, const char *src, size_t n);

// Return the first line of file, caracteres after first line are kept
char	*get_next_line(int fd);
#endif
