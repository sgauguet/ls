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
	if (!content || !content->filename[0] || content->filename[0] != '.')
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

int	print_details(t_file *content)
{
	char	type[2];
	char	access[10];
	char	time[50];
	t_group	*group;

	ft_strncpy(type, "-", 2);
	ft_strncpy(access, "rwxrwxrwx", 10);
	ft_strncpy(time, ctime(&content->stats.st_mtime), 50);
	time[ft_strlen(time) - 1] = '\0';
	group = getgrgid(content->stats.st_gid);
	print_colors(content);
	ft_printf("%C%s %d %s %4d %s %s\n", content->type, access,
		content->stats.st_nlink, group->gr_name, content->stats.st_size,
		time, content->filename);
	ft_printf("\033[0m");
	return (0);
}

int	print_content(t_arg *args, t_file **content)
{
	t_file *start;

	start = *content;
	if (content == NULL)
		return (1);
	if (*content && ((args->options & op_R)
		|| (args->files && args->directories)
		|| (args->directories && args->directories->next)))
		ft_printf("%s:\n", (*content)->filepath);
	while (*content)
	{
		if (args->options & op_l && (!print_hidden_files(*content)
				|| (args->options & op_a)))
			print_details(*content);
		else if (!print_hidden_files(*content) || (args->options & op_a))
		{
			print_colors(*content);
			ft_printf("%s  ", (*content)->filename);
			ft_printf("\033[0m");
		}
		*content = (*content)->next;
	}
	ft_printf("\n\n");
	*content = start;
	return (0);
}
