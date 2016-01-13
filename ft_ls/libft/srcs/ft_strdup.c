/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:03:40 by vtarreau          #+#    #+#             */
/*   Updated: 2014/11/13 15:31:24 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s2 = NULL;
	while (s1[j] != '\0')
		j++;
	if (s1 != NULL)
		s2 = malloc(sizeof(char*) * (j + 1));
	if (s2 != NULL)
	{
		while (s1[i] != 0)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
	}
	return (s2);
}
