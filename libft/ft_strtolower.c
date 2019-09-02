/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:22:17 by sgauguet          #+#    #+#             */
/*   Updated: 2019/08/30 11:24:18 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtolower(const char *src, char *dest)
{
	int i;

	i = 0;
	if (!src || !dest)
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = tolower(src[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
