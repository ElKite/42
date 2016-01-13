/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:59:38 by vtarreau          #+#    #+#             */
/*   Updated: 2015/01/12 17:25:37 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = ft_strlen(s);
	if (!c)
		return ((char*)&s[ft_strlen(s)]);
	while (i > 0)
	{
		--i;
		if (s[i] == c)
			return ((char*)&s[i]);
	}
	return (0);
}
