/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 08:42:45 by vtarreau          #+#    #+#             */
/*   Updated: 2015/01/10 12:09:32 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	int i;
	int nbr;
	int signe;

	i = 0;
	nbr = 0;
	signe = 1;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\f') || (str[i]
							== '\r') || (str[i] == '\v') || (str[i] == ' '))
		++i;
	if (str[i] == '+')
		++i;
	else if (str[i] == '-')
	{
		signe = -1;
		++i;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nbr = nbr * 10 + (str[i] - 48);
		++i;
	}
	return (nbr * signe);
}
