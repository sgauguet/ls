/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:12:55 by sgauguet          #+#    #+#             */
/*   Updated: 2019/06/26 13:16:51 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

int opt_parse(char *argv, t_options *op) {
	int i;

	i = 0;
	if (ft_strlen(argv) < 2 || argv[0] != '-')
		return 1;
	while (i < ft_strlen(argv)) {
		i++;
	}
	return 0;
}
