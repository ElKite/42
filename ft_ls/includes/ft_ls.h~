/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:05:00 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/29 16:49:19 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <stdio.h>
# include <time.h>

# define TRUE 1
# define FALSE 0

typedef struct		s_path
{
	char			*name;
	struct s_path	*next;
	struct s_filew	*files;
	struct s_path	*paths;
	struct stat		*stat;
	struct s_manage *manage;
}					t_path;

typedef struct		s_filew
{
	char			*name;
	int				type;
	struct stat		*stat;
	struct s_filew	*next;
}					t_filew;

typedef struct		s_manage
{
	size_t			links;
	size_t			owner;
	size_t			groups;
	size_t			size;
	int				sizeblock;
}					t_manage;

typedef struct		s_env
{
	t_path			*args;
	t_filew			*files;

	int				show_dot;
	int				recursive;
	int				sort_time;
	int				reverse;
	int				format_out;
	int				show_dirname;
}					t_env;

void		parse(t_env *env, int size, char **args);
void		exit_clean(int error, char *msg, t_env *env);

void		ft_addpath_env(t_env *env, char *name);
void		ft_addpath_path(t_path *path, char *name);
void		ft_addfile(t_path *path, struct dirent *file);

//void		compute_dir(t_env *env, t_path *path);
//void		compute_dirs(t_env *env);
//void		show_dir(t_env *env, t_path *path);
//void		display(t_env *env, t_path *path);

void		ft_ls(t_env *env);
void		main_ls(t_env *env, t_path *path);
void		sort_both(t_env *env, t_path *path);
void		add_files_and_dir(t_env *env, t_path *path, struct dirent *file);
void		display_files(t_env *env, t_path *path);
void		display_files_l(t_filew *file, t_manage *manage, char *name);
void		count_sizes(t_env *env, t_path *path);
void		ft_display_rights(mode_t st_mode);
void		show_link(char *name, t_filew *file);
int			check_exist(char *path);
void		addfile_toenv(t_env *env, char *path);

void		ft_sort_time_path(t_path *lst);
void		ft_sort_time_files(t_filew *files);

void		ft_putnspace(int i);
int			ft_is_hidden(t_env *env, char *name);
int			ft_is_dot_dotdot(t_env *env, int type, char *name);
t_filew		*ft_sort_ascii(t_filew *path);
void		ft_sort_ascii_path(t_path *path);
void		ft_swap_path(t_path *cur, t_path *next);
void		ft_swap(t_filew *cur, t_filew *next);
t_filew		*ft_reverse_files(t_filew *files);
t_path		*ft_reverse_path(t_path *path);
char		*ft_strjoins(char *s1, char *s2, char *s3);

# endif
