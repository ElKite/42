/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:28:40 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/21 12:57:26 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	sort_both(t_env *env, t_path *path)
{
	path->files = ft_sort_ascii(path->files);
	ft_sort_ascii_path(path);
	if (env->reverse == TRUE)
	{
		path->files = ft_reverse_files(path->files);
		path->paths = ft_reverse_path(path->paths);
	} else if (env->sort_time == TRUE)
	{
	}
}

void	add_files_and_dir(t_env *env, t_path *path, struct dirent *file)
{
	if (!ft_is_hidden(env, file->d_name))
	{
		if (file->d_type == DT_DIR)
			if (!ft_is_dot_dotdot(env, file->d_type, file->d_name))
				ft_addpath(env, ft_strjoins(path->name, "/", file->d_name));
		ft_addfile(path, file);
	}
}

void	display_files(t_path *path)
{
	while (path->files != NULL)
	{
		ft_putendl(path->files->name);
		path->files = path->files->next;
	}
	ft_putchar('\n');
}
