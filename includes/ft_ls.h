/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgauguet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 14:20:04 by sgauguet          #+#    #+#             */
/*   Updated: 2019/06/26 13:03:02 by sgauguet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H

# define FT_LS_H

# include "../libft/libft.h"
# include <dirent.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <errno.h>

typedef struct dirent t_dirent;

typedef struct s_options {
	char op_l;
	char op_R;
	char op_a;
	char op_r;
	char op_t;
	char op_u;
	char op_f;
	char op_g;
	char op_d;
}

#endif
