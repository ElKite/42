/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 13:48:58 by vtarreau          #+#    #+#             */
/*   Updated: 2015/01/13 12:13:16 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*s1;

	i = 0;
	if (!s)
		return (0);
	if (len > ft_strlen(s))
		return (0);
	s1 = (char*)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	while (i < len && s[start])
	{
		s1[i] = s[start];
		i++;
		start++;
	}
	s1[i] = '\0';
	return (s1);
}
