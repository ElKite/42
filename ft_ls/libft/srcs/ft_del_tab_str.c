/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_tab_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 13:49:12 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/24 14:35:58 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_del_tab_str(char ***tab, int pos)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = -1;
	k = 0;
	res = (char**)malloc(sizeof(char*) * (ft_tablen(*tab)));
	while ((*tab)[++i])
		if (i != pos)
		{
			j = -1;
			res[k] = (char*)malloc(sizeof(char) * (ft_strlen((*tab)[i]) + 1));
			while ((*tab)[i][++j])
				res[k][j] = (*tab)[i][j];
			res[k][j] = 0;
			k++;
		}
	res[i] = NULL;
	ft_memdel((void**)tab);
	*tab = res;
}
