/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 15:31:05 by vtarreau          #+#    #+#             */
/*   Updated: 2015/04/02 15:57:37 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void	check_cmd(char **s, char **env)
{
	struct stat yolo;

	if (ft_strchr(s[0], '/'))
	{
		if (lstat(s[0], &yolo) == 0)
		{
			if (access(s[0], X_OK) == -1)
			{
				ft_putstr_fd("Permission denied\n", 2);
				exit(0);
			}
			else
			{
				execve(s[0], s, env);
				ft_putstr_fd("Execve error\n", 2);
			}
		}
		ft_putstr_fd("Command not found\n", 2);
		exit(0);
	}
}

void	cmd(char **s, char **env)
{
	char		**path;
	int			i;
	char		*tmp;
	struct stat	yolo;

	i = -1;
	path = ft_strsplit(get_env("PATH", env), ':');
	check_cmd(s, env);
	while (path[++i])
	{
		tmp = ft_strjoin(path[i], ft_strjoin("/", s[0]));
		if (lstat(tmp, &yolo) == 0)
		{
			if (!yolo.st_mode & S_IXUSR)
				ft_putstr_fd("Permission denied\n", 2);
			else
				execve(tmp, s, env);
			ft_putstr_fd("Execve error\n", 2);
		}
		free(tmp);
	}
	ft_putstr_fd("Command not found\n", 2);
	exit(0);
}
