/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:46:42 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/14 18:16:42 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

int		ft_is_hidden(t_env *env, char *name)
{
	if (env->show_dot == FALSE)
		if (name[0] == '.' && name[1] != '/')
			return (1);
	return (0);
}

int		ft_is_dot_dotdot(t_env *env, int type, char *name)
{
	if (env->recursive == TRUE && type == DT_DIR && env->show_dot == TRUE)
	{
		if (ft_strcmp(name, ".") == 0 || ft_strcmp(name, "..") == 0)
			return (1);
	}
	return (0);
}

t_filew	*ft_sort_ascii(t_filew *path)
{
	t_filew	*save;
	t_filew *tmp;

	save = path;
	return (path);
}
