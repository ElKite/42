/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 15:50:52 by vtarreau          #+#    #+#             */
/*   Updated: 2015/04/02 16:09:30 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void		yolo(char **s, int i, char ***env)
{
	char *tmp;

	tmp = ft_strsub(s[i], 0, ft_char_position(s[i], '='));
	if (get_env(tmp, *env) == NULL)
		ft_add_str_to_tab(env, s[i]);
	else
	{
		tmp = ft_strjoin(tmp, "=");
		ft_replace_str_in_tab(env, ft_string_position(*env, tmp), s[i]);
	}
	free(tmp);
}

void			env_cmd(char **s, char **env)
{
	char		**path;
	int			i;
	char		*tmp;
	struct stat	yolo;

	i = -1;
	path = ft_strsplit(get_env("PATH", env), ':');
	check_cmd(s, env);
	while (path && path[++i])
	{
		tmp = ft_strjoin(path[i], ft_strjoin("/", s[0]));
		if (lstat(tmp, &yolo) == 0)
		{
			if (!yolo.st_mode & S_IXUSR)
				(ft_putstr_fd("Permission denied\n", 2), exit(0));
			else
				execve(tmp, s, env);
		}
		free(tmp);
	}
	ft_putstr_fd("Command not found\n", 2);
	exit(0);
}

void			add_var(char **s, char ***env)
{
	int		i;

	i = 0;
	if (ft_strcmp(s[1], "-i") == 0)
		i++;
	while (s[++i])
	{
		if (ft_strchr(s[i], '='))
			yolo(s, i, env);
		else
		{
			if (fork() == 0)
				env_cmd(ft_tabception(s, i, ft_tablen(s)), *env);
			wait(NULL);
			break ;
		}
	}
}

void			display_env(char **env)
{
	int i;

	i = -1;
	if (env)
		while (env[++i])
			ft_putendl(env[i]);
}

int				build_env(char **s, char **env)
{
	char		**tmp;
	int			i;
	int			f;

	i = 0;
	f = 1;
	tmp = env;
	if (s[1] && ft_strcmp(s[1], "-i") == 0)
	{
		tmp = NULL;
		i += 1;
	}
	if (s[0] && !s[1])
		return (display_env(tmp), 1);
	while (s[++i])
		if (ft_strchr(s[i], '=') == NULL)
			f = 0;
	add_var(s, &tmp);
	if (f)
		display_env(tmp);
	return (1);
}
