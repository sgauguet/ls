/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:51:42 by sgauguet          #+#    #+#             */
/*   Updated: 2019/08/30 11:55:15 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	print_hidden_files(t_file *content)
{
	if (!content || content->hidden == 0)
		return (0);
	return (1);
}

int	print_colors(t_file *content)
{
	if (content->type == DT_DIR)
		ft_printf("\033[0;33m");
	else if (content->type == DT_LNK)
		ft_printf("\033[1;31m");
	else if (content->type == DT_REG)
		ft_printf("\033[1;33m");
	return (0);
}

int	print_details(t_arg *args, t_file *content)
{
	char	access[11];
	char	time[50];
	char	linkname[PATH_MAX];
	t_group	*group;
	t_pwd	*pwd;

	get_access(content, access);
	if (S_ISLNK(content->stats.st_mode))
	{
		ft_bzero(linkname, PATH_MAX);
		readlink(content->filepath, linkname, PATH_MAX);
	}
	ft_strncpy(time, ctime(&content->stats.st_mtime), 50);
	time[ft_strlen(time) - 1] = '\0';
	format_time(content, time);
	pwd = getpwuid(content->stats.st_uid);
	group = getgrgid(content->stats.st_gid);
	(args->options & op_g) ? print_colors(content) : 0;
	ft_printf("%s  %2d %s  %s %5d %s %s", access, content->stats.st_nlink,
		pwd->pw_name, group->gr_name, content->stats.st_size,
		time, content->filename);
	(access[0] == 'l') ? ft_printf(" -> %s\n", linkname) : ft_printf("\n");
	if (args->options & op_g)
		ft_printf("\033[0m");
	return (0);
}

int	print_total(t_arg *args, t_file *start, t_file **content)
{
	int total;

	total = 0;
	if (args->print == 1)
		ft_printf("\n");
	if (*content && (((args->options & op_R) && args->print)
		|| (args->files && args->directories) || (args->directories
			&& args->directories->next) || ((args->options & op_r)
			&& args->count_dir > 2)))
		ft_printf("%s:\n", (*content)->realpath);
	while (start)
	{
		if (start->hidden == 0 || args->options & op_a)
			total += start->stats.st_blocks;
		start = start->next;
	}
	if (args->options & op_l)
		ft_printf("total %d\n", total);
	return (0);
}

int	print_content(t_arg *args, t_file **content)
{
	t_file *start;

	start = *content;
	if (content == NULL)
		return (1);
	print_total(args, start, content);
	start = *content;
	while (*content)
	{
		if (args->options & op_l && (!print_hidden_files(*content)
			|| (args->options & op_a)))
			print_details(args, *content);
		else if (!print_hidden_files(*content) || (args->options & op_a))
		{
			if (args->options & op_g)
				print_colors(*content);
			ft_printf("%s\n", (*content)->filename);
			if (args->options & op_g)
				ft_printf("\033[0m");
		}
		*content = (*content)->next;
	}
	*content = start;
	args->print = 1;
	return (0);
}
