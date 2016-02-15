/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:01:16 by vtarreau          #+#    #+#             */
/*   Updated: 2014/12/17 12:44:43 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putendl(char const *s)
{
	int i;

	i = -1;
	if (s)
	{
		while (s[++i] != '\0')
			write(1, &s[i], 1);
		write(1, "\n", 1);
	}
}