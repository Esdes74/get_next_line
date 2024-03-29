/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:27:34 by eslamber          #+#    #+#             */
/*   Updated: 2022/12/16 23:41:07 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	max(size_t x, size_t y)
{
	if (x > y)
		return (x);
	return (y);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_strlcat(char *dest, const char *src, size_t n)
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

char	*ft_strdup(const char *src)
{
	char	*new;
	size_t	len;
	size_t	len_cpy;
	size_t	n;

	len = ft_strlen(src) + 1;
	new = (char *) malloc(sizeof(char) * len);
	if (new == 0)
		return (0);
	len_cpy = 0;
	n = ft_strlen(src) + 1;
	while (len_cpy < n - 1 && src[len_cpy] != '\0' && n != 0)
	{
		new[len_cpy] = src[len_cpy];
		len_cpy++;
	}
	if (n != 0)
		new[len_cpy] = '\0';
	return (new);
}

int	ft_in(char src, char *test, size_t n)
{
	size_t	ind;

	ind = 0;
	while (test[ind] != '\0' && ind < n)
	{
		if (test[ind] == src)
			return (1);
		ind++;
	}
	return (0);
}
