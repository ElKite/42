/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 11:16:55 by vtarreau          #+#    #+#             */
/*   Updated: 2014/11/13 15:33:01 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = -1;
	while (s1[i])
		i++;
	while ((s2[++j]) && (j < n))
		s1[i + j] = s2[j];
	s1[i + j] = '\0';
	return (s1);
}
