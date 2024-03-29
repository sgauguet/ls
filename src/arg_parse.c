/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:41:39 by sgauguet          #+#    #+#             */
/*   Updated: 2019/08/30 11:46:09 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	arg_delete(t_arg *args)
{
	t_file *tmp;
	t_file *elem;

	tmp = args->files;
	while (tmp)
	{
		elem = tmp;
		tmp = tmp->next;
		free(elem);
	}
	tmp = args->directories;
	while (tmp)
	{
		elem = tmp;
		tmp = tmp->next;
		free(elem);
	}
	return ;
}

void	print_files(t_arg *args)
{
	t_file *tmp;

	tmp = args->files;
	ft_printf("---FILES ---\n");
	while (tmp)
	{
		ft_printf("%s\n", tmp->filename);
		tmp = tmp->next;
	}
	tmp = args->directories;
	ft_printf("---DIRECTORIES ---\n");
	while (tmp)
	{
		ft_printf("%s\n", tmp->filename);
		tmp = tmp->next;
	}
}

t_file	*create_file(const char *filename)
{
	t_file *new;

	new = NULL;
	if (!(new = (t_file *)malloc(sizeof(t_file))))
	{
		return (NULL);
	}
	ft_bzero(new->filename, NAME_MAX);
	ft_bzero(new->filepath, PATH_MAX);
	ft_bzero(new->realpath, PATH_MAX);
	ft_strncpy(new->filename, filename, ft_strlen(filename));
	if (lstat(filename, &new->stats) != 0)
	{
		ft_printf("ls: %s: %s\n", filename, strerror(errno));
		free(new);
		return (NULL);
	}
	return (new);
}

int		insert_file(t_arg *args, t_file *new)
{
	if (((new->stats.st_mode & S_IFMT) == S_IFDIR
		|| (new->stats.st_mode & S_IFMT) == S_IFLNK) && !(args->options & op_d))
	{
		new->next = args->directories;
		args->directories = new;
		args->count_dir = args->count_dir + 1;
		return (0);
	}
	new->next = args->files;
	args->files = new;
	return (0);
}

int		arg_parse(const char *filename, t_arg *args)
{
	t_file *new;

	args->count_arg = args->count_arg + 1;
	if (filename == NULL || ft_strlen(filename) == 0)
		return (1);
	if (!(new = create_file(filename)))
		return (1);
	insert_file(args, new);
	return (0);
}
