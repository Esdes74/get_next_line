/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:17:30 by eslamber          #+#    #+#             */
/*   Updated: 2022/12/08 13:19:53 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
