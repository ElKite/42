/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:32:17 by vtarreau          #+#    #+#             */
/*   Updated: 2014/11/13 15:34:33 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1)
	{
		if (!s2)
			return ((char*)s1);
		while (s1[i] && i < n)
		{
			j = 0;
			while (s1[i + j] && (i + j) < n && s1[i + j] == s2[j])
				j++;
			if (s2[j] == '\0')
				return ((char*)&s1[i]);
			i++;
		}
	}
	return (0);
}
