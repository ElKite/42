/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/30 14:28:31 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/31 16:10:47 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

void		set_env(char ***env, char *s1, char *s2)
{
	char	*tmp;
	int		pos;

	pos = ft_string_position(*env, s1);
	if (get_env(s1, *env))
	{
		tmp = ft_strjoin(s1, "=");
		tmp = ft_strjoin(tmp, s2);
		ft_replace_str_in_tab(env, pos, tmp);
	}
	else
	{
		tmp = ft_strjoin(s1, "=");
		tmp = ft_strjoin(tmp, s2);
		ft_add_str_to_tab(env, tmp);
	}
	free(tmp);
}
