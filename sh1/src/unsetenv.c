/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 13:57:01 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/27 18:22:34 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		build_unsetenv(char **s, char ***env)
{
	int		i;

	i = 0;
	if (ft_tablen(s) == 1)
		return (ft_putendl("unsetenv: Too few arguments"), 1);
	while (s[++i])
	{
		if (get_env(s[i], *env))
			ft_del_tab_str(env, ft_string_position(*env, s[i]));
	}
	return (1);
}
