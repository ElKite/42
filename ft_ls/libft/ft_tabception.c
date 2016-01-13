/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabception.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 17:08:39 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/26 12:49:05 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabception(char **tab, int start, int end)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	if (tab == NULL || end == 0)
		return (NULL);
	i = start - 1;
	k = 0;
	res = (char**)malloc(sizeof(char*) * (end - start + 1));
	while (++i < end)
	{
		j = -1;
		res[k] = (char*)malloc(sizeof(char) * (ft_strlen(tab[i]) + 1));
		while (tab[i][++j])
			res[k][j] = tab[i][j];
		res[k][j] = 0;
		k++;
	}
	res[k] = NULL;
	return (res);
}
