/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 09:06:33 by vtarreau          #+#    #+#             */
/*   Updated: 2014/11/13 15:19:23 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	char	*ft_itoatool(int n, int sign, char *nbr, int i)
{
	int j;

	j = 0;
	if (sign)
	{
		nbr[j] = '-';
		j++;
	}
	while (i > 0)
	{
		nbr[j] = ((n / i) % 10 + 48);
		i /= 10;
		j++;
	}
	nbr[j] = '\0';
	return (nbr);
}

char			*ft_itoa(int n)
{
	int		i;
	char	*nbr;
	int		sign;

	sign = 0;
	i = 1;
	nbr = NULL;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	while ((n / i) > 9)
		i *= 10;
	nbr = (char*)malloc(sizeof(char*) * (i + 1 + sign));
	if (n == -2147483648)
		nbr = ft_strcpy(nbr, "-2147483648");
	else
		nbr = ft_itoatool(n, sign, nbr, i);
	return (nbr);
}
