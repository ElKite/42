/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:04:53 by vtarreau          #+#    #+#             */
/*   Updated: 2014/11/13 15:20:19 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*s;
	size_t	i;

	s = NULL;
	s = malloc(size);
	if (s)
	{
		i = 0;
		while (i < size)
		{
			s[i] = '\0';
			i++;
		}
	}
	return (s);
}
