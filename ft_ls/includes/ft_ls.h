/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:05:00 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/14 17:46:14 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0

typedef struct		s_path
{
	char			*name;
	struct s_path	*next;
	struct s_filew	*files;
}					t_path;

typedef struct		s_filew
{
	char			*name;
	int				type;
	struct stat		stat;
	struct s_filew	*next;
}					t_filew;

typedef struct		s_env
{
	t_path			*paths;

	int				show_dot;
	int				recursive;
	int				sort_time;
	int				reverse;
	int				format_out;
}					t_env;

int			parse(t_env *env, int size, char **args);
void		exit_clean(int error, char *msg, t_env *env);

void		ft_addpath(t_env *env, char *name);
void		ft_addfile(t_path *path, struct dirent *file);

void		compute_dir(t_env *env, t_path *path);
void		compute_dirs(t_env *env);
void		show_dir(t_env *env, t_path *path);
void		show_dirs(t_env *env);

int			ft_is_hidden(t_env *env, char *name);
int			ft_is_dot_dotdot(t_env *env, int type, char *name);
t_filew		*ft_sort_ascii(t_filew *path);

# endif
