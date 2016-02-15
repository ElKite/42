/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_str_to_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 14:01:40 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/27 14:42:20 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_str_to_tab(char ***tab, char *s)
{
	char	**res;
	int		i;

	i = -1;
	res = (char**)malloc(sizeof(char*) * (ft_tablen(*tab) + 2));
	if (*tab)
	{
		while ((*tab)[++i])
			res[i] = ft_strdup((*tab)[i]);
	}
	else
		i++;
	res[i] = ft_strdup(s);
	res[i + 1] = NULL;
	*tab = res;
}
