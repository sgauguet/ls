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
				&& ft_strcmp((*list)->filename, "..")
				&& ((*list)->hidden == 0 || args->options & op_a))
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
	if (count_directories(list))
		recursive(args, list);
	return (0);
}

int	list_files(t_arg *args)
{
	t_file *tmp;

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
	sort_list(args, &args->files);
	tmp = args->files;
	while (tmp)
	{
		if (args->options & op_l)
			print_details(args, tmp);
		else
			ft_printf("%s\n", tmp->filename);
		tmp = tmp->next;
	}
	if (args->files && args->directories && !(args->options & op_d))
		ft_printf("\n");
	return (0);
}

int	list_directories(t_arg *args)
{
	t_file *tmp;
	t_file *content;

	sort_list(args, &args->directories);
	tmp = args->directories;
	while (tmp)
	{
		content = get_repository_content(tmp->filename);
		if (content)
		{
			args->count_dir = args->count_dir + 1;
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
