/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_repository.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 12:23:34 by sgauguet          #+#    #+#             */
/*   Updated: 2019/06/27 12:23:37 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int remove_first_elem_list(t_file **list)
{
	t_file *tmp;

	tmp = *list;
	if (tmp == NULL)
		return 1;
	*list = (*list)->next;
	free(tmp);
	return (0);
}

int	concat_lists(t_file *sublist, t_file **list) 
{
	t_file *tmp;

	if (sublist == NULL)
		return 1;
	tmp = sublist;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *list;
	*list = sublist;
	return (0);
}

int recursive(t_arg *args, t_file **list)
{
	t_file *content;

	if (*list) {
		if (ft_strcmp((*list)->filename, ".") && ft_strcmp((*list)->filename, "..")) 
		{
			content = get_repository_content((*list)->filepath);
			sort_list(args, &content);
			print_content(args, &content);
			delete_content(&content, 0);
			remove_first_elem_list(list);
			concat_lists(content, list);
		}
	}
	if (*list != NULL)
		recursive(args, list);
	return 0;
}

int list_repository(t_arg *args) {
	t_file *tmp;
	t_file *content;

	if (args->files && args->files->next) {
		while (!alphabetical_order(&(args->files)))
			;
	}
	tmp = args->files;
	while (tmp) {
		ft_printf("%s\n", tmp->filename);
		tmp = tmp->next;
	}
	tmp = args->directories;
	content = NULL;
	while (tmp) {
		content = get_repository_content(tmp->filename);
		sort_list(args, &content);
		print_content(args, &content);
		if (args->options & op_R) {
			delete_content(&content, 0);
			recursive(args, &content);
		}
		delete_content(&content, 1);
		tmp = tmp->next;
	}
	return 0;
}