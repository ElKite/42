/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 18:05:53 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/30 14:49:29 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static	int		build_cd_tris(char **s, char ***env)
{
	char *buf;

	buf = NULL;
	if (ft_tablen(s) == 2 && access(s[1], F_OK) == -1)
		return (ft_putstr_fd("Path doesn't exist\n", 2), 1);
	if (ft_tablen(s) == 2 && access(s[1], X_OK) == 0)
	{
		set_env(env, "OLDPWD", getcwd(buf, 1024));
		chdir(s[1]);
		set_env(env, "PWD", getcwd(buf, 1024));
		return (1);
	}
	else if (ft_tablen(s) == 2 && access(s[1], X_OK) == -1)
		return (ft_putstr_fd("Access can not be granted\n", 2), 1);
	return (1);
}

static	void	build_cd_bis(char **s, char **env)
{
	char *tmp;

	if (ft_tablen(s) == 2)
	{
		if (s[1][0] == '~')
		{
			tmp = ft_strsub(s[1], 1, ft_strlen(s[1]));
			s[1] = ft_strjoin(get_env("HOME", env), tmp);
			free(tmp);
		}
		if (s[1][0] == '-')
			s[1] = get_env("OLDPWD", env);
	}
}

int				build_cd(char **s, char ***env)
{
	char	*buf;

	buf = NULL;
	if (ft_tablen(s) >= 3)
	{
		ft_putstr_fd("cd: Too many argmuments\n", 2);
		return (1);
	}
	if (ft_tablen(s) == 1)
	{
		set_env(env, "OLDPWD", getcwd(buf, 1024));
		chdir(get_env("HOME", *env));
		set_env(env, "PWD", getcwd(buf, 1024));
		return (1);
	}
	build_cd_bis(s, *env);
	return (build_cd_tris(s, env));
}
