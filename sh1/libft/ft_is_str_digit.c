/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_str_digit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 14:40:26 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/21 14:41:59 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_str_digit(char *s)
{
	int i;

	i = -1;
	while (s[++i])
		if (ft_isdigit(s[i]) == 0)
			return (0);
	return (1);
}
