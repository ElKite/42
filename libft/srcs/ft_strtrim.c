/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 16:34:51 by vtarreau          #+#    #+#             */
/*   Updated: 2014/11/13 15:35:59 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	char	*s1;

	i = 0;
	s1 = NULL;
	if (s)
	{
		j = ft_strlen(s);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		while ((s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
				&& j > i)
			j--;
		s1 = ft_strsub(s, i, j - i);
	}
	return (s1);
}
