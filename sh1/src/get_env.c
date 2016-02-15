/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 15:42:17 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/31 16:11:24 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

char		*get_env(char *s, char **env)
{
	int		i;
	char	*res;

	i = -1;
	res = NULL;
	if (!env)
		return (NULL);
	while (env[++i])
	{
		res = ft_strstr(env[i], s);
		if (res != NULL)
			if (res[ft_strlen(s)] == '=')
				return (res + ft_strlen(s) + 1);
		res = NULL;
	}
	return (res);
}
