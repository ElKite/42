/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 14:38:51 by vtarreau          #+#    #+#             */
/*   Updated: 2014/11/13 15:32:28 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s1;

	i = 0;
	s1 = NULL;
	if (s && f)
	{
		s1 = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
		while (s[i])
		{
			s1[i] = f(s[i]);
			i++;
		}
		s1[i] = '\0';
	}
	return (s1);
}
