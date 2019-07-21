
#include "ft_ls.h"

int extract_content(t_file *elem, t_file **list) {
	t_file *tmp;

	tmp = *list;
	if (*list == NULL) {
		*list = elem;
		elem->next = NULL;
	}
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
		elem->next = NULL;
	}
	return (0);
}

int	delete_content(t_file **content, int all)
{
	t_file *list;
	t_file *tmp;

	list = NULL;
	while (*content)
	{
		tmp = (*content)->next;
		if (((*content)->stats.st_mode & S_IFMT) != S_IFDIR || all) {
			free(*content);
		}
		else if (!all) {
			extract_content(*content, &list);
		}
		*content = tmp;
	}
	*content = list;
	return (0);
}

int add_content(const char *filename, const char *filepath, t_file **content, unsigned char type)
{
	t_file *new;
	t_file *tmp;

	if (!(new = create_file(filepath)))
		return 1;
	ft_strncpy(new->filename, filename, 255);
	ft_strncpy(new->filepath, filepath, 4096);
	new->type = type;
	new->next = NULL;
	tmp = *content;
	if (!tmp)
		*content = new;
	else {
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (0);
}

t_file *get_repository_content(const char *filepath)
{
	void *dirp;
	t_dirent *dp;
	t_file *content;
	char path[4096];

	if (!(dirp = opendir(filepath)))
		return NULL;
	content = NULL;
	while ((dp = readdir(dirp)) != NULL) {
		//if (ft_strcmp(dp->d_name, ".") && ft_strcmp(dp->d_name, "..")) {
			ft_bzero(path, 4096);
			ft_strncpy(path, filepath, ft_strlen(filepath));
			if (path[ft_strlen(path) - 1] != '/')
				ft_strcat(path, "/");
			ft_strcat(path, dp->d_name);
			add_content(dp->d_name, path, &content, dp->d_type);
		//}
	}
	(void)closedir(dirp);
	return content;
}