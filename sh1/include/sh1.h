/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh1.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 14:14:43 by vtarreau          #+#    #+#             */
/*   Updated: 2015/04/02 14:51:42 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH1_H
# define SH1_H
# include "libft.h"
# include <sys/wait.h>
# include <stdio.h>
# include <sys/stat.h>
# include "get_next_line.h"
# include <signal.h>

int		get_next_line(int f, char **line);
int		build_exit(char **s);
int		build_cd(char **s, char ***env);
int		build_setenv(char **s, char ***env);
int		build_unsetenv(char **s, char ***env);
int		build_env(char **s, char **env);
void	cmd(char **s, char **env);
char	*get_env(char *s, char **env);
void	display_env(char **env);
void	check_cmd(char **s, char **env);
void	set_env(char ***env, char *s1, char *s2);
int		is_buildin(char **s, char ***env);

#endif
