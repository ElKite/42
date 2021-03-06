/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 12:03:47 by vtarreau          #+#    #+#             */
/*   Updated: 2016/02/03 14:33:39 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	exit_clean(int error, char *reason, t_env *env)
{
	((void)env);
	if (error)
		ft_putstr("Illegal options : ");
	ft_putendl(reason);
	exit(0);
}

int		main(int argc, char **args)
{
	t_env	*env;

	if ((env = (t_env*)malloc(sizeof(t_env))) == NULL)
		exit_clean(1, "cant malloc struct", env);
	parse(env, argc, args);
	ft_ls(env);
	return (0);
}
