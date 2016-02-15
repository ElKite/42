/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 13:49:57 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/23 14:30:34 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcpy(char **tab)
{
	char	**res;
	int		i;
	int		j;

	i = -1;
	res = (char**)malloc(sizeof(char*) * (ft_tablen(tab) + 1));
	while (tab[++i])
	{
		res[i] = (char*)malloc(sizeof(char) * (ft_strlen(tab[i]) + 1));
		j = -1;
		while (tab[i][++j])
			res[i][j] = tab[i][j];
		res[i][j] = 0;
	}
	res[i] = NULL;
	return (res);
}
