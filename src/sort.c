
#include "ft_ls.h"

int	access_time_order(t_file **list)
{
	t_file *prev;
	t_file *next;
	t_file *tmp;

	prev = NULL;
	next = (*list) ? (*list)->next : NULL;
	tmp = *list;
	while (tmp && next) {
		if ((tmp->stats.st_atime) < (next->stats.st_atime)) {
			tmp->next = next->next;
			next->next = tmp;
			if (prev) {
				prev->next = next;
			}
			else {
				*list = next;
			}
			access_time_order(list);
		}
		prev = tmp;
		tmp = next;
		next = next->next;
	}
	return (0);
}

int modification_time_order(t_file **list) {
	t_file *prev;
	t_file *next;
	t_file *tmp;

	prev = NULL;
	next = (*list) ? (*list)->next : NULL;
	tmp = *list;
	while (tmp && next) {
		if ((tmp->stats.st_mtime) < (next->stats.st_mtime)) {
			tmp->next = next->next;
			next->next = tmp;
			if (prev) {
				prev->next = next;
			}
			else {
				*list = next;
			}
			modification_time_order(list);
		}
		prev = tmp;
		tmp = next;
		next = next->next;
	}
	return (0);
}

int	reverse_order(t_file **list)
{
	t_file *newlist;
	t_file *tmp;

	newlist = NULL;
	tmp = *list;
	while (*list) {
		tmp = (*list)->next;
		(*list)->next = newlist;
		newlist = *list;
		*list = tmp;
	}
	*list = newlist;
	return (0);
}

t_file *alphabetical_order(t_file **list)
{
	t_file *prev;
	t_file *next;
	t_file *tmp;

	prev = NULL;
	next = (*list) ? (*list)->next : NULL;
	tmp = *list;
	while (tmp && next) {
		if (ft_strcasecmp(tmp->filename, next->filename) > 0) {
			tmp->next = next->next;
			next->next = tmp;
			if (prev) {
				prev->next = next;
			}
			else {
				*list = next;
			}
			return(NULL);
		}
		prev = tmp;
		tmp = next;
		next = next->next;
	}
	return (*list);
}

int sort_list(t_arg *args, t_file **list)
{
	if (args->options & op_r)
		reverse_order(list);
	if (args->options & op_t)
		modification_time_order(list);
	if (args->options & op_u)
		access_time_order(list);
	return (0);
}