/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:03:47 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/20 12:22:57 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	exit_clean(int error, char *reason, t_env *env)
{
	((void)env);
	if (error)
		ft_putstr("ERROR : ");
	ft_putendl(reason);
	exit(0);
}

int		main(int argc, char **args)
{
	t_env	*env;

	if ((env = (t_env*)malloc(sizeof(t_env))) == NULL)
		exit_clean(1, "cant malloc struct", env);
	if (!parse(env, argc, args))
		exit_clean(1, "parsing failed", env);
	//compute_dirs(env);
	ft_ls(env);
	return (0);
}
