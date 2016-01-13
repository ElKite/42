/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_onespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/20 11:47:25 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/20 13:07:53 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_onespace(char const *s)
{
	int		i;
	int		j;
	char	*res;

	i = -1;
	j = 0;
	s = ft_strtrim(s);
	res = (char*)malloc(sizeof(char) * (ft_strlen(s)));
	while (s[++i])
	{
		while (s[i + 1] && s[i] == ' ' && s[i + 1] == ' ')
			i++;
		res[j] = s[i];
		j++;
	}
	res[j] = '\0';
	return (res);
}
