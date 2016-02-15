/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_str_in_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:18:51 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/27 13:46:00 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void		ft_replace_str_in_tab(char ***tab, int pos, char *s)
{
	char	**res;
	int		i;

	i = -1;
	res = (char**)malloc(sizeof(char*) * (ft_tablen(*tab) + 1));
	while ((*tab)[++i])
	{
		if (i == pos)
			res[i] = ft_strdup(s);
		else
			res[i] = ft_strdup((*tab)[i]);
	}
	res[i] = NULL;
	*tab = res;
}
