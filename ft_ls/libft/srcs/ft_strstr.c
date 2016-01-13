/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 14:38:27 by vtarreau          #+#    #+#             */
/*   Updated: 2015/01/13 12:11:16 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	if (ft_strcmp(s2, "") == 0)
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		while (s1[i + j] && s1[i + j] == s2[j])
			j++;
		if (s2[j] == '\0')
			return ((char*)&s1[i]);
		i++;
	}
	return (0);
}
