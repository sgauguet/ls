/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:05:02 by sgauguet          #+#    #+#             */
/*   Updated: 2019/08/30 12:09:20 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		extract_content(t_file *elem, t_file **list)
{
	t_file *tmp;

	tmp = *list;
	if (*list == NULL)
	{
		*list = elem;
		elem->next = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		elem->next = NULL;
	}
	return (0);
}

int		delete_content(t_file **content, int all)
{
	t_file *list;
	t_file *tmp;

	list = NULL;
	while (*content)
	{
		tmp = *content;
		*content = (*content)->next;
		if ((tmp->stats.st_mode & S_IFMT) != S_IFDIR || all)
			free(tmp);
		else
			extract_content(tmp, &list);
	}
	*content = list;
	return (0);
}

int		add_content(t_dirent *dp, const char *realpath, const char *filepath,
		t_file **content)
{
	t_file *new;
	t_file *tmp;

	if (!(new = create_file(filepath)))
		return (1);
	ft_bzero(new->filename, NAME_MAX);
	ft_strncpy(new->filename, dp->d_name, ft_strlen(dp->d_name));
	ft_strncpy(new->filepath, filepath, ft_strlen(filepath));
	ft_strncpy(new->realpath, realpath, ft_strlen(realpath));
	new->type = dp->d_type;
	new->hidden = (ft_strlen(dp->d_name) && dp->d_name[0] == '.') ? 1 : 0;
	new->next = NULL;
	tmp = *content;
	if (!tmp)
		*content = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}

t_file	*get_repository_content(const char *filepath)
{
	void		*dirp;
	t_dirent	*dp;
	t_file		*content;
	char		path[4096];

	if (!(dirp = opendir(filepath)))
		return (NULL);
	content = NULL;
	while ((dp = readdir(dirp)) != NULL)
	{
		ft_bzero(path, 4096);
		ft_strncpy(path, filepath, ft_strlen(filepath));
		if (path[ft_strlen(path) - 1] != '/')
			ft_strcat(path, "/");
		ft_strcat(path, dp->d_name);
		add_content(dp, filepath, path, &content);
	}
	(void)closedir(dirp);
	while (!alphabetical_order(&content))
		;
	return (content);
}
