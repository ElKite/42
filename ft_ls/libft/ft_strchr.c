/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:40:49 by vtarreau          #+#    #+#             */
/*   Updated: 2014/11/11 15:58:23 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s1, int c)
{
	unsigned int i;

	i = 0;
	while (i <= ft_strlen(s1))
	{
		if (s1[i] == c)
			return ((char*)&s1[i]);
		i++;
	}
	return (0);
}
