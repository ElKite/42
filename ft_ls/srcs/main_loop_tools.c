/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 12:28:40 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/26 17:27:05 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	sort_both(t_env *env, t_path *path)
{
	if (env->sort_time == TRUE)
	{
		dprintf(1, "TOTOTOTOTOT\n");
		ft_sort_time_files(path->files);
		ft_sort_time_path(path);
	}
	else
	{
		ft_sort_ascii(path->files);
		ft_sort_ascii_path(path);
	}
	if (env->reverse == TRUE)
	{
		path->files = ft_reverse_files(path->files);
		path = ft_reverse_path(path);
	}
}

void	add_files_and_dir(t_env *env, t_path *path, struct dirent *file)
{
	if (!ft_is_hidden(env, file->d_name))
	{
		if (file->d_type == DT_DIR && env->recursive == TRUE)
			if (!ft_is_dot_dotdot(env, file->d_type, file->d_name))
				ft_addpath_path(path, ft_strjoins(path->name, "/", file->d_name));
		ft_addfile(path, file);
	}
}

void	display_files(t_path *path)
{
	dprintf(1, "\033[1;31m%s\033[1;0m:\n", path->name);
	while (path->files != NULL)
	{
		ft_putendl(path->files->name);
		path->files = path->files->next;
	}
	ft_putchar('\n');
}
