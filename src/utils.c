/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:04:14 by sgauguet          #+#    #+#             */
/*   Updated: 2019/09/18 10:04:16 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	count_directories(t_file **list)
{
	t_file *tmp;

	tmp = *list;
	while (tmp)
	{
		if ((tmp->stats.st_mode & S_IFMT) == S_IFDIR)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	get_access(t_file *content, char access[11])
{
	access[0] = (S_ISDIR(content->stats.st_mode)) ? 'd' : '-';
	if (S_ISLNK(content->stats.st_mode))
		access[0] = 'l';
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
	return (0);
}

int	format_time(t_file *content, char newtime[50])
{
	char	copy[50];
	int		i;
	int		end;

	ft_strcpy(copy, newtime);
	ft_bzero(newtime, 50);
	i = 3;
	if (((unsigned int)time(NULL) - (unsigned int)content->stats.st_mtime)
		< 15778800)
	{
		end = ft_strlen(copy) - 8;
		while (++i < end)
			newtime[i - 4] = copy[i];
	}
	else
	{
		end = 7;
		while (++i - 4 < end)
			newtime[i - 4] = copy[i];
		newtime[i - 4] = copy[ft_strlen(copy) - 4];
		newtime[i - 3] = copy[ft_strlen(copy) - 3];
		newtime[i - 2] = copy[ft_strlen(copy) - 2];
		newtime[i - 1] = copy[ft_strlen(copy) - 1];
	}
	return (0);
}
