/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcasecmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:34:56 by sgauguet          #+#    #+#             */
/*   Updated: 2019/08/30 11:38:04 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	free_copy(char *copy1, char *copy2)
{
	if (!copy1 || !copy2)
		return (1);
	free(copy1);
	free(copy2);
	return (0);
}

int	ft_strcasecmp(const char *s1, const char *s2)
{
	char	*copy1;
	char	*copy2;
	int		i;
	int		result;

	i = 0;
	copy1 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	copy2 = (char *)malloc(sizeof(char) * (ft_strlen(s2) + 1));
	if (!copy1 || !copy2)
		return (0);
	ft_strtolower(s1, copy1);
	ft_strtolower(s2, copy2);
	while (copy1[i] == copy2[i] && copy1[i] != '\0' && copy2[i] != '\0')
		i++;
	if ((unsigned char)copy1[i] == (unsigned char)copy2[i])
		result = 0;
	result = (unsigned char)copy1[i] - (unsigned char)copy2[i];
	free_copy(copy1, copy2);
	return (result);
}
