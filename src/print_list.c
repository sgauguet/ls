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
	char	access[11];
	char	time[50];
	char	linkname[PATH_MAX];
	t_group	*group;
	t_pwd	*pwd;

	access[0] = (S_ISDIR(content->stats.st_mode)) ? 'd' : '-';
	if (S_ISLNK(content->stats.st_mode)) {
		access[0] = 'l';
		ft_bzero(linkname, PATH_MAX);
		readlink(content->filename, linkname, PATH_MAX);
	}
	else if (S_ISBLK(content->stats.st_mode))
		access[0] = 'b';
	else if (S_ISCHR(content->stats.st_mode))
		access[0] = 'c';
	else if (S_ISFIFO(content->stats.st_mode))
		access[0] = 'p';
	else if (S_ISSOCK(content->stats.st_mode))
		access[0] = 's';
    access[1] = (content->stats.st_mode & S_IRUSR) ? 'r' : '-';
    access[2] = (content->stats.st_mode & S_IWUSR) ? 'w' : '-';
    access[3] = (content->stats.st_mode & S_IXUSR) ? 'x' : '-';
    access[4] = (content->stats.st_mode & S_IRGRP) ? 'r' : '-';
    access[5] = (content->stats.st_mode & S_IWGRP) ? 'w' : '-';
    access[6] = (content->stats.st_mode & S_IXGRP) ? 'x' : '-';
    access[7] = (content->stats.st_mode & S_IROTH) ? 'r' : '-';
    access[8] = (content->stats.st_mode & S_IWOTH) ? 'w' : '-';
    access[9] = (content->stats.st_mode & S_IXOTH) ? 'x' : '-';
    access[10] = '\0';
	ft_strncpy(time, ctime(&content->stats.st_mtime), 50);
	time[ft_strlen(time) - 1] = '\0';
	pwd = getpwuid(content->stats.st_uid);
	group = getgrgid(content->stats.st_gid);
	//print_colors(content);
	ft_printf("%s %d %s %s %4d %s %s", access, content->stats.st_nlink, 
		pwd->pw_name, group->gr_name, content->stats.st_size,
		time, content->filename);
	(access[0] == 'l') ? ft_printf(" -> %s\n", linkname) : ft_printf("\n");
	//ft_printf("\033[0m");
	return (0);
}

int	print_content(t_arg *args, t_file **content)
{
	t_file *start;

	start = *content;
	if (content == NULL)
		return (1);
	if (args->print == 1)
		ft_printf("\n");
	if (*content && ((args->options & op_R)
		|| (args->files && args->directories)
		|| (args->directories && args->directories->next)))
		ft_printf("%s:\n", (*content)->realpath);
	while (*content)
	{
		if (args->options & op_l && (!print_hidden_files(*content)
				|| (args->options & op_a)))
			print_details(*content);
		else if (!print_hidden_files(*content) || (args->options & op_a))
		{
			//print_colors(*content);
			ft_printf("%s\n", (*content)->filename);
			//ft_printf("\033[0m");
		}
		*content = (*content)->next;
	}
	//ft_printf("\n");
	*content = start;
	args->print = 1;
	return (0);
}
