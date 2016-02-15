/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 12:22:10 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/31 16:05:21 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

static void		build_setenv_bis(char **s, char ***env)
{
	char	*tmp;

	if (ft_tablen(s) == 2 && ft_strchr(s[1], '=') == 0)
	{
		tmp = ft_strjoin(s[1], "=");
		ft_add_str_to_tab(env, tmp);
		free(tmp);
	}
	else if (ft_tablen(s) == 3 && ft_strchr(s[1], '=') == 0 &&
			ft_strchr(s[2], '=') == 0)
	{
		tmp = ft_strjoin(s[1], "=");
		tmp = ft_strjoin(tmp, s[2]);
		ft_add_str_to_tab(env, tmp);
		free(tmp);
	}
}

static	void	display_setenv(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		ft_putendl(env[i]);
}

int				build_setenv(char **s, char ***env)
{
	char	*tmp;

	if (ft_tablen(s) == 1)
		return (display_setenv(*env), 1);
	if (ft_tablen(s) > 3)
		return (ft_putendl_fd("setenv: Too many arguments", 2), 1);
	if ((s[1] && ft_strchr(s[1], '=')) || (s[2] && ft_strchr(s[2], '=')))
		return (ft_putendl_fd("setenv: Synthax error", 2), 1);
	if (get_env(s[1], *env) == NULL)
		build_setenv_bis(s, env);
	else if (get_env(s[1], *env))
	{
		tmp = ft_strjoin(s[1], "=");
		tmp = ft_strjoin(tmp, s[2]);
		ft_replace_str_in_tab(env, ft_string_position(*env, s[1]), tmp);
		free(tmp);
	}
	return (1);
}
