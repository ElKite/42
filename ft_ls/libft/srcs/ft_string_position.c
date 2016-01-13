/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:05:37 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/23 17:35:34 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_string_position(char **tab, char *s)
{
	int i;

	i = -1;
	while (tab[++i])
		if (ft_strstr(tab[i], s))
			return (i);
	return (0);
}
