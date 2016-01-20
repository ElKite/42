/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 11:51:17 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/20 17:17:13 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	main_ls(t_env *env,t_path *path)
{
	struct dirent	*tmp;
	DIR				*dir;

	if ((dir = opendir(path->name)) == NULL)
	{
		perror(path->name);
		return ;
	}
	while (path != NULL)
	{
		dprintf(1, " -- %s -- \n", path->name);
		while ((tmp = readdir(dir)) != NULL)
			add_files_and_dir(env, path, tmp);
		sort_both(env, path);
		display_files(path);
		while (path->paths != NULL)
		{
			if (env->recursive == TRUE)
				main_ls(env, path->paths);
			path->paths = path->paths->next;
		}
			path = path->next;
			closedir(dir);
	}
}

void	ft_ls(t_env	*env)
{
	main_ls(env, env->path);
}
