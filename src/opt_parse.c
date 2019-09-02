/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:12:55 by sgauguet          #+#    #+#             */
/*   Updated: 2019/08/30 12:04:24 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_pow(int n)
{
	int i;
	int result;

	i = 0;
	result = 1;
	while (i < n)
	{
		result *= 2;
		i++;
	}
	return (result);
}

int		opt_valid(char opt)
{
	char	*opt_valid;
	int		i;

	opt_valid = "lRartufgd";
	i = 0;
	while (opt_valid[i] != '\0')
	{
		if (opt_valid[i] == opt)
			return (i);
		i++;
	}
	return (-1);
}

void	opt_print(int options)
{
	ft_printf("op_l %d\n", options & op_l);
	ft_printf("op_R %d\n", options & op_R);
	ft_printf("op_a %d\n", options & op_a);
	ft_printf("op_r %d\n", options & op_r);
	ft_printf("op_t %d\n", options & op_t);
	ft_printf("op_u %d\n", options & op_u);
	ft_printf("op_f %d\n", options & op_f);
	ft_printf("op_g %d\n", options & op_g);
	ft_printf("op_d %d\n", options & op_d);
}

int		opt_parse(char *argv, t_arg *args)
{
	unsigned int	i;
	int				op;

	i = 1;
	op = 0;
	if (ft_strlen(argv) < 2 || argv[0] != '-')
		return (0);
	while (i < ft_strlen(argv))
	{
		if ((op = opt_valid(argv[i])) == -1)
		{
			ft_printf("Invalid option -- %c\n", argv[i]);
			exit(1);
		}
		args->options |= ft_pow(op);
		i++;
	}
	//opt_print(options);
	return (args->options);
}
