/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_repository.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:04:35 by sgauguet          #+#    #+#             */
/*   Updated: 2019/08/30 12:04:57 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	count_directories(t_file **list)
{
	t_file *tmp;

	tmp = *list;
	while (tmp) {
		if ((tmp->stats.st_mode & S_IFMT) == S_IFDIR)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	remove_first_elem_list(t_file **list)
{
	t_file *tmp;

	tmp = *list;
	if (tmp == NULL)
		return (1);
	*list = (*list)->next;
	free(tmp);
	return (0);
}

int	concat_lists(t_file *sublist, t_file **list)
{
	t_file *tmp;

	if (sublist == NULL)
		return (1);
	tmp = sublist;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *list;
	*list = sublist;
	return (0);
}

int	recursive(t_arg *args, t_file **list)
{
	t_file *content;

	if (*list)
	{
		if (ft_strcmp((*list)->filename, ".")
				&& ft_strcmp((*list)->filename, ".."))
		{
			content = get_repository_content((*list)->filepath);
			sort_list(args, &content);
			print_content(args, &content);
			delete_content(&content, 0);
			remove_first_elem_list(list);
			concat_lists(content, list);
		}
		else
			remove_first_elem_list(list);
	}
	if (count_directories(list)) {
		recursive(args, list);
	}
	return (0);
}

int	list_repository(t_arg *args)
{
	t_file *tmp;
	t_file *content;

	if (args->files && args->files->next)
	{
		while (!alphabetical_order(&(args->files)))
			;
	}
	if (args->directories && args->directories->next)
	{
		while (!alphabetical_order(&(args->directories)))
			;
	}
	tmp = args->files;
	sort_list(args, &tmp);
	while (tmp)
	{
		if (args->options & op_l)
			print_details(tmp);
		else
			ft_printf("%s\n", tmp->filename);
		tmp = tmp->next;
	}
	tmp = args->directories;
	sort_list(args, &tmp);
	if (args->files && args->directories && !(args->options & op_d))
		ft_printf("\n");
	while (tmp)
	{
		content = get_repository_content(tmp->filename);
		if (content) {
			sort_list(args, &content);
			print_content(args, &content);
			if (args->options & op_R)
			{
				delete_content(&content, 0);
				recursive(args, &content);
			}
			delete_content(&content, 1);
		}
		else
			ft_printf("ls: %s: %s\n", tmp->filename, strerror(errno));
		tmp = tmp->next;
	}
	return (0);
}
