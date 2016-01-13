/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/15 13:27:28 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/13 11:41:07 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtoupper(char *s)
{
	int i;

	i = -1;
	if (!s)
		return (0);
	while (s[++i])
		s[i] = ft_toupper(s[i]);
	return (s);
}
