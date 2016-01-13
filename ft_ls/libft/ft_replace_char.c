/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 12:04:48 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/13 11:39:15 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_replace_char(char *s, char old, char new)
{
	int i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == old)
			s[i] = new;
	}
	return (s);
}
