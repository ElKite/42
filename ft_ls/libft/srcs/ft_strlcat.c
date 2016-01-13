/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 18:59:41 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/13 11:39:56 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t lendst;
	size_t lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	if (size <= lendst)
		return (size + lensrc);
	if (lensrc < size - lendst)
	{
		ft_memcpy(dst + lendst, src, lensrc);
		dst += lendst + lensrc;
	}
	else
	{
		ft_memcpy(dst + lendst, src, size - lendst - 1);
		dst += size - 1;
	}
	*dst = '\0';
	return (lensrc + lendst);
}
