/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:08:02 by sgauguet          #+#    #+#             */
/*   Updated: 2019/08/30 11:51:28 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		is_flag(char *argv)
{
	if (ft_strlen(argv) == 2 && argv[0] == '-' && argv[1] == '-')
		return (1);
	if (ft_strlen(argv) > 1 && argv[0] == '-')
		return (2);
	return (0);
}

void	init_args(t_arg *args)
{
	args->files = NULL;
	args->directories = NULL;
	args->options = 0;
	args->print = 0;
	args->nb = -1;
}

int		main(int argc, char **argv)
{
	t_arg args;

	init_args(&args);
	while (argc--)
	{
		argv++;
		if (is_flag(*argv))
			opt_parse(*argv, &args);
		else
			arg_parse(*argv, &args);
	}
	if (args.nb == 0)
		arg_parse(".", &args);
	list_repository(&args);
	arg_delete(&args);
	return (1);
}
