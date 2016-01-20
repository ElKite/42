/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:05:30 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/20 11:53:57 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_path		*ft_newpath(char *name)
{
	t_path *path = NULL;

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

void		ft_addpath(t_env *env, char *name)
{
	t_path *path;
	t_path *tmp;

	path = ft_newpath(name);
	if (env->paths == NULL)
		env->paths = path;
	else
	{
		tmp = env->paths;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = path;
	}
}
