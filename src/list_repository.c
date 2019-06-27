/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_repository.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:23:34 by sgauguet          #+#    #+#             */
/*   Updated: 2019/06/27 12:23:37 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	list_repository(const char * filename)
{
	void *dirp;
	t_dirent *dp;

	if (!(dirp = opendir(filename)))
		return 1;
	while ((dp = readdir(dirp)) != NULL) {
		ft_printf("%s\n", dp->d_name);
	}
	(void)closedir(dirp);
	return 0;
}
