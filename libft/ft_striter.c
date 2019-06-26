/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/02 21:50:41 by sgauguet          #+#    #+#             */
/*   Updated: 2017/01/29 15:17:27 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	size_t i;

	if (!s || !f)
		return ;
	i = 0;
	while (i < ft_strlen(s))
	{
		f(&s[i]);
		i++;
	}
}