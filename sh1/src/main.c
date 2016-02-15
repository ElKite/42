/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 14:15:59 by vtarreau          #+#    #+#             */
/*   Updated: 2015/04/02 14:53:39 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void		shell_level(char ***env)
{
	int		res;
	char	*tmp;

	if (get_env("SHLVL", *env))
	{
		res = ft_atoi(get_env("SHLVL", *env)) + 1;
		tmp = ft_strjoin("SHLVL=", ft_itoa(res));
		ft_replace_str_in_tab(env, ft_string_position(*env, "SHLVL="), tmp);
		free(tmp);
	}
	else
	{
		res = 1;
		ft_add_str_to_tab(env, ft_strjoin("SHLVL=", ft_itoa(res)));
	}
}

int				is_buildin(char **s, char ***env)
{
	int f;

	f = 0;
	if (ft_strcmp(s[0], "env") == 0)
		f = build_env(s, *env);
	if (ft_strcmp(s[0], "setenv") == 0)
		f = build_setenv(s, env);
	else if (ft_strcmp(s[0], "unsetenv") == 0)
		f = build_unsetenv(s, env);
	else if (ft_strcmp(s[0], "exit") == 0)
		f = build_exit(s);
	else if (ft_strcmp(s[0], "cd") == 0)
		f = build_cd(s, env);
	return (f);
}

int				main(int argc, char **argv, char **envp)
{
	char	*line;
	char	**tab;
	char	**env;

	(signal(SIGINT, SIG_IGN), signal(SIGTSTP, SIG_IGN));
	env = ft_tabcpy(envp);
	shell_level(&env);
	while ((ft_putstr("\033[1;31m$> \033[1;0m"), 42))
	{
		get_next_line(0, &line);
		line = ft_replace_char(line, '\t', ' ');
		if (ft_strlen(line))
		{
			tab = ft_strsplit(line, ' ');
			if (tab[0] != NULL)
				if (!is_buildin(tab, &env) && fork() == 0)
				{
					signal(SIGINT, SIG_DFL);
					cmd(tab, env);
				}
			free(line);
		}
		wait(NULL);
	}
	return ((void)argc, (void)argv, 0);
}
