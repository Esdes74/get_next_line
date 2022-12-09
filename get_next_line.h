/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:44:57 by eslamber          #+#    #+#             */
/*   Updated: 2022/12/08 14:31:32 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

// Return first occurence of little
char	*ft_strnstr(const char *big, const char *little, size_t n);

// Return new string what is src concatenated to dest
char	*ft_strjoin(char *dest, char *src);

// Return the first line, the second line become the first line
char	*get_next_line(int fd);
#endif
