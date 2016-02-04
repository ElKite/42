/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_char_at_postion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 14:43:52 by vtarreau          #+#    #+#             */
/*   Updated: 2016/02/04 15:04:06 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_char_at_position(char *s, char c, int l)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == c && i == l)
			return (1);
	}
	return (0);
}
