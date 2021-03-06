/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 11:51:17 by vtarreau          #+#    #+#             */
/*   Updated: 2016/02/04 16:26:48 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		check_exist(char *path, t_env *env)
{
	struct stat	*stat;

	if ((stat = malloc(sizeof(struct stat))) == NULL)
		return (-1);
	if (lstat(path, stat) == -1)
	{
		perror(path);
		free(stat);
		return (-1);
	}
	else if (S_ISDIR(stat->st_mode))
	{
		free(stat);
		return (1);
	}
	else if (S_ISLNK(stat->st_mode))
	{
		free(stat);
		if (env->format_out == TRUE)
			return (0);
		else
			return (1);
	}
	return (0);
}

void	addfile_toenv(t_env *env, char *path)
{
	t_filew	*tmp;
	t_filew	*new;

	if ((new = malloc(sizeof(t_filew))) == NULL)
		return ;
	new->name = ft_strdup(path);
	if ((new->stat = malloc(sizeof(struct stat))) == NULL)
		return ;
	lstat(path, new->stat);
	new->next = NULL;
	if (env->files == NULL)
		env->files = new;
	else
	{
		tmp = env->files;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	main_ls(t_env *env, t_path *path)
{
	struct dirent	*tmp;
	DIR				*dir;

	if ((dir = opendir(path->name)) == NULL)
	{
		perror(path->name);
		return ;
	}
	while ((tmp = readdir(dir)) != NULL)
		add_files_and_dir(env, path, tmp);
	sort_both(env, path);
	count_sizes(env, path);
	display_files(env, path);
	if (env->recursive == TRUE)
		while (path->paths != NULL)
		{
			main_ls(env, path->paths);
			path->paths = path->paths->next;
		}
	closedir(dir);
}

void	display_only_files(t_filew *file, t_env *env)
{
	t_manage *manage;

	if (env->format_out == TRUE)
	{
		manage = (t_manage*)malloc(sizeof(t_manage));
		manage->links = 1;
		manage->owner = 0;
		manage->groups = 0;
		manage->size = 0;
		manage->sizeblock = 0;
		display_files_l(file, manage, file->name);
	}
	else
		ft_putendl(file->name);
}

void	ft_ls(t_env *env)
{
	if (env->args != NULL && (env->args->next != NULL ||
						env->recursive == TRUE))
		env->show_dirname = TRUE;
	if (env->files != NULL)
	{
		if (env->sort_time == TRUE)
			ft_sort_time_files(env->files);
		else
			ft_sort_ascii(env->files);
		if (env->reverse == TRUE)
			ft_reverse_files(env->files);
	}
	while (env->files != NULL)
	{
		display_only_files(env->files, env);
		env->files = env->files->next;
		if (env->files == NULL)
			ft_putchar('\n');
	}
	while (env->args != NULL)
	{
		main_ls(env, env->args);
		env->args = env->args->next;
	}
}
