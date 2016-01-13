/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 15:18:08 by vtarreau          #+#    #+#             */
/*   Updated: 2014/11/13 15:33:38 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, char const *src, size_t n)
{
	size_t i;

	i = 0;
	while (i != n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
