/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:46:04 by sgauguet          #+#    #+#             */
/*   Updated: 2017/01/29 15:20:33 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;

	if (s2[0] == '\0')
		return ((char*)s1);
	i = ft_strlen(s2);
	while (*s1 && len-- >= i)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, i) == 0)
			return ((char*)s1);
		++s1;
	}
	return (NULL);
}
