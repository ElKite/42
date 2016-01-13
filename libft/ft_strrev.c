/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 17:14:24 by vtarreau          #+#    #+#             */
/*   Updated: 2015/02/19 09:48:34 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strrev(char *s)
{
	int		i;
	char	*s1;
	int		len;

	i = 0;
	s1 = NULL;
	len = ft_strlen(s);
	if (s)
	{
		s1 = (char*)malloc(sizeof(char) * (len + 1));
		while (len > 0)
		{
			s1[i] = s[len - 1];
			len--;
			i++;
		}
		s1[i] = '\0';
	}
	return (s1);
}
