/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:08:02 by sgauguet          #+#    #+#             */
/*   Updated: 2019/06/26 13:03:10 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	inspect_file() {



	return 0;
}

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

int	main(int argc, char **argv)
{
	if (argc > 1) {
		list_repository(argv[1]);
		ft_printf("%s\n", "Ok");
	}
	return (1);
}
