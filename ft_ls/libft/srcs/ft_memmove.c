/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:33:13 by vtarreau          #+#    #+#             */
/*   Updated: 2014/11/13 15:26:28 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char const	*source;
	char		*dest;

	i = 0;
	dest = (char*)dst;
	source = (char*)src;
	if (source < dest)
	{
		while (i++ < len)
			dest[len - i] = source[len - i];
	}
	else
		ft_memcpy(dest, source, len);
	return (dst);
}
