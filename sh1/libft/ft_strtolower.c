/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtolower.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 13:29:21 by vtarreau          #+#    #+#             */
/*   Updated: 2015/02/06 12:15:53 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strtolower(char *s)
{
	int i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		s[i] = ft_tolower(s[i]);
	return (s);
}
