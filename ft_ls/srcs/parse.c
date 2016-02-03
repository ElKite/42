/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:05:41 by vtarreau          #+#    #+#             */
/*   Updated: 2016/02/03 15:03:38 by vtarreau         ###   ########.fr       */
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
			exit_clean(1, &arg[i], env);
		i++;
	}
}

static void	init(t_env *env)
{
	env->recursive = FALSE;
	env->sort_time = FALSE;
	env->show_dot = FALSE;
	env->reverse = FALSE;
	env->format_out = FALSE;
	env->show_dirname = FALSE;
	env->args = NULL;
	env->files = NULL;
}

static void	check(t_env *env, int j, int ret)
{
	if (env->args == NULL && env->files == NULL && ret != -1)
		ft_addpath_env(env, ".");
	if (j > 1)
		env->show_dirname = TRUE;
}

void		parse(t_env *env, int size, char **args)
{
	int		i;
	int		j;
	int		flag;
	int		ret;

	init(env);
	i = 0;
	j = 0;
	flag = 0;
	while (++i < size)
	{
		if (args[i][0] == '-' && flag == 0)
			parse_arg(env, args[i] + 1);
		else
		{
			j++;
			flag = 1;
			ret = check_exist(args[i], env);
			if (ret == 1)
				ft_addpath_env(env, args[i]);
			else if (ret == 0)
				addfile_toenv(env, args[i]);
		}
	}
	check(env, j, ret);
}
