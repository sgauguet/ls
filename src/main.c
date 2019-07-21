/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:08:02 by sgauguet          #+#    #+#             */
/*   Updated: 2019/06/27 12:45:26 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int is_flag(char *argv) {
	if (ft_strlen(argv) > 2 && argv[0] == '-' && argv[1] == '-')
		return 1;
	if (ft_strlen(argv) > 1 && argv[0] == '-')
		return 2;
	return 0;
}

void init_args(t_arg *args) {
	args->files = NULL;
	args->directories = NULL;
	args->options = 0;
}

int	main(int argc, char **argv)
{
	t_arg args;

	init_args(&args);
	while (argc--) {
		argv++;
		if (is_flag(*argv))
			args.options = opt_parse(*argv, args.options);
		else
			arg_parse(*argv, &args);
	}
	if (args.files == NULL && args.directories == NULL)
		arg_parse(".", &args);
	list_repository(&args);
	arg_delete(&args);
	//print_files(&args);
	//ft_printf("options : %d\n", args.options);
	return (1);
}
