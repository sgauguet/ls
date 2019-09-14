/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:10:02 by sgauguet          #+#    #+#             */
/*   Updated: 2019/09/10 10:31:45 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <errno.h>

typedef struct dirent	t_dirent;
typedef struct stat		t_stat;
typedef struct group	t_group;
typedef struct passwd  	t_pwd;

typedef enum		e_options {
	op_l = 1, op_R = 2, op_a = 4, op_r = 8, op_t = 16, op_u = 32,
	op_f = 64, op_g = 128, op_d = 256
}					t_options;

typedef struct		s_file {
	char			filename[NAME_MAX];
	char			filepath[PATH_MAX];
	char			realpath[PATH_MAX];
	unsigned char	type;
	t_stat			stats;
	struct s_file	*next;
}					t_file;

typedef struct		s_arg {
	t_file	*files;
	t_file	*directories;
	int		options;
	int 	nb;
	int 	print;
}					t_arg;

/*
** print_list.c
*/

int					print_hidden_files(t_file *content);
int					print_colors(t_file *content);
int					print_details(t_file *content);
int					print_content(t_arg *args, t_file **content);

/*
** list_repository.c
*/

int					remove_first_elem_list(t_file **list);
int					concat_lists(t_file *sublist, t_file **list);
int					recursive(t_arg *args, t_file **list);
int					list_repository(t_arg *args);

/*
** inspect_file.c
*/

int					extract_content(t_file *elem, t_file **list);
int					delete_content(t_file **content, int all);
int					add_content(const char *filename, const char *realpath, const char *path,
					t_file **content, unsigned char type);
t_file				*get_repository_content(const char *filename);

/*
** opt_parse.c
*/

int					ft_pow(int n);
int					opt_valid(char opt);
void				opt_print(int options);
int					opt_parse(char *argv, t_arg *args);

/*
** arg_parse.c
*/

void				arg_delete(t_arg *args);
void				print_files(t_arg *args);
t_file				*create_file(const char *filename);
int					insert_file(t_arg *args, t_file *new);
int					arg_parse(const char *filename, t_arg *args);

/*
** sort.c
*/

int					access_time_order(t_file **list);
int					modification_time_order(t_file **list);
int					reverse_order(t_file **list);
t_file				*alphabetical_order(t_file **list);
int					sort_list(t_arg *args, t_file **list);

#endif
