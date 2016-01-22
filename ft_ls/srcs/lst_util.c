/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:05:30 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/22 17:47:54 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_path		*ft_newpath(char *name)
{
	t_path *path;

	if ((path = (t_path*)malloc(sizeof(t_path))) == NULL)
		return (NULL);
	path->name = name;
	path->files = NULL;
	path->paths = NULL;
	path->next = NULL;
	return (path);
}

t_filew		*ft_newfile(struct dirent *dirent)
{
	t_filew	*f;

	if ((f = (t_filew*)malloc(sizeof(t_filew))) == NULL)
		return (NULL);
	f->name = ft_strdup(dirent->d_name);
	f->type = dirent->d_type;
	//f->stat = lstat(f->name, 
	f->next = NULL;
	return (f);
}

void		ft_addfile(t_path *path, struct dirent *dirent)
{
	t_filew *file;
	t_filew *tmp;

	file = ft_newfile(dirent);
	if (!path->files)
		path->files = file;
	else
	{
		tmp = path->files;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = file;
	}
}

void		ft_addpath_env(t_env *env, char *name)
{
	t_path *path;
	t_path *tmp;
	
	path = ft_newpath(name);
	if (env->args == NULL)
		env->args = path;
	else
	{
		tmp = env->args;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = path;
	}
}
void		ft_addpath_path(t_path *path, char *name)
{
	t_path *new;
	t_path *tmp;

	new = ft_newpath(name);
	if (path->paths == NULL)
		path->paths = new;
	else
	{
		tmp = path->paths;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}
