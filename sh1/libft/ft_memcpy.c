/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 12:56:07 by vtarreau          #+#    #+#             */
/*   Updated: 2015/01/10 12:10:01 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	if (!dst || !src)
		return (0);
	s2 = (unsigned char*)dst;
	s1 = (unsigned char*)src;
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	return (dst);
}
