/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 11:51:17 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/29 16:53:47 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

int		check_exist(char *path)
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
	free(stat);
	return (0);
}

void	addfile_toenv(t_env *env, char *path)
{
	t_filew	*tmp;
	t_filew	*new;
	int		i;
	char	**tab;

	if ((new = malloc(sizeof(t_filew))) == NULL)
		return ;
	tab = ft_strsplit(path, '/');
	i = 0;
	while (tab[i])
		i++;
	new->name = ft_strdup(tab[i - 1]);
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

void	main_ls(t_env *env,t_path *path)
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

void	ft_ls(t_env	*env)
{
	if (env->args != NULL && (env->args->next != NULL || env->recursive == TRUE))
		env->show_dirname = TRUE;
	//show files
	// & sort
	while (env->args != NULL)
	{
		main_ls(env, env->args);
		env->args = env->args->next;
	}
}
