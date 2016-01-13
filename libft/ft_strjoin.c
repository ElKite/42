/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/24 12:08:25 by vtarreau          #+#    #+#             */
/*   Updated: 2014/12/20 12:04:00 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;

	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s3 = NULL;
	if (s1 && s2)
	{
		s3 = (char*)malloc(sizeof(char) * (ft_strlen(s1)
											+ ft_strlen(s2)) + 1);
		ft_strcpy(s3, s1);
		ft_strcat(s3, s2);
	}
	return (s3);
}
