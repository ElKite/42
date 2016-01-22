/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 11:51:17 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/22 17:47:48 by vtarreau         ###   ########.fr       */
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
	while ((tmp = readdir(dir)) != NULL)
		add_files_and_dir(env, path, tmp);
	sort_both(env, path);
	display_files(path);
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
	while (env->args != NULL)
	{
		main_ls(env, env->args);
		env->args = env->args->next;
	}
}
