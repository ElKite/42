/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:05:41 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/22 14:15:06 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		parse_arg(t_env *env, char *arg)
{
	size_t		i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == 'l')
			env->format_out = TRUE;
		else if (arg[i] == 'R')
			env->recursive = TRUE;
		else if (arg[i] == 'a')
			env->show_dot = TRUE;
		else if (arg[i] == 'r')
			env->reverse = TRUE;
		else if (arg[i] == 't')
			env->sort_time = TRUE;
		else
			exit_clean(1, "illegal option", env);
		i++;
	}
}


int			parse(t_env *env, int size, char **args)
{
	int		i;

	i = 0;
	env->recursive = FALSE;
	env->sort_time = FALSE;
	env->show_dot = FALSE;
	env->reverse = FALSE;
	env->format_out = FALSE;
	env->args = NULL;
	while (++i < size)
	{
		if (!ft_strchr(args[i], '-'))
			ft_addpath_env(env, args[i]);
		else
			parse_arg(env, args[i] + 1);
	}
	if (env->args == NULL)
		ft_addpath_env(env, ".");
	return (TRUE);
}
