/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtolower.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:46:24 by sgauguet          #+#    #+#             */
/*   Updated: 2017/01/23 17:52:00 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtolower(const char *src, char *dest)
{
	int i;

	i = 0;
	if (!src || !dest)
		return NULL;
	while (src[i] != '\0')
	{
		dest[i] = tolower(src[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}