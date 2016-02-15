/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 14:28:54 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/26 17:37:44 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_tablen(char **tab)
{
	int i;

	i = -1;
	if (!tab)
		return (0);
	while (tab[++i])
		;
	return (i);
}
