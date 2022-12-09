/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:17:30 by eslamber          #+#    #+#             */
/*   Updated: 2022/12/08 13:58:46 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	max(size_t x, size_t y)
{
	if (x > y)
		return (x);
	return (y);
}

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_d;
	size_t	len;
	size_t	save_len_d;

	if ((src == 0 || dest == 0) && n == 0)
		return (0);
	len_d = ft_strlen(dest);
	save_len_d = len_d;
	if (n != 0)
	{
		len = 0;
		while (src[len] != '\0' && len_d < n - 1)
		{
			dest[len_d] = src[len];
			len_d++;
			len++;
		}
	}
	else
		return (ft_strlen(src));
	dest[len_d] = '\0';
	if (n < save_len_d)
		return (n + ft_strlen(src));
	return (max(len_d, save_len_d + ft_strlen(src)));
}

char	*ft_strjoin(char *dest, char *src)
{
	size_t	len_tot;
	char	*new;

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

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	len;
	size_t	len_test;
	size_t	i;

	if (!little[0])
		return ((char *)big);
	len = 0;
	len_test = 0;
	while (big[len] != '\0' && len < n && n != 0)
	{
		i = len;
		len_test = 0;
		while (big[i] == little[len_test] && big[i] != '\0' && i < n)
		{
			i++;
			len_test++;
		}
		if (little[len_test] == '\0')
			return ((char *) big + len);
		len++;
	}
	return (0);
}
