/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 17:11:36 by vtarreau          #+#    #+#             */
/*   Updated: 2015/01/12 15:33:44 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*st1;
	unsigned char		*st2;

	i = 0;
	if (!s1 || !s2)
		return (0);
	st1 = (unsigned char*)s1;
	st2 = (unsigned char*)s2;
	while (i < n)
	{
		if (st1[i] == st2[i])
			i++;
		else
			return (st1[i] - st2[i]);
	}
	return (0);
}
