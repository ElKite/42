/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/16 15:26:24 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/16 18:02:29 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	maxint(char *s, char *max)
{
	int		i;
	int		j;

	j = -1;
	i = 0;
	while (s[i] == '0')
		i++;
	if ((int)ft_strlen(s) - i > 10)
		return (0);
	if ((int)ft_strlen(s) - i < 10)
		return (1);
	while (max[++j])
	{
		if (s[i] > max[j])
			return (0);
		i++;
	}
	return (1);
}

static int	minint(char *s, char *min)
{
	int		i;
	int		j;

	j = -1;
	i = 1;
	while (s[i] == '0')
		i++;
	if ((int)ft_strlen(s) - i > 10)
		return (0);
	if ((int)ft_strlen(s) - i < 10)
		return (1);
	while (min[++j])
	{
		if (s[i] > min[j])
			return (0);
		i++;
	}
	return (1);
}

int			ft_isint(char *s)
{
	char	*min;
	char	*max;

	min = ft_strdup("2147483648");
	max = ft_strdup("2147483647");
	if (ft_strcmp(s, "") == 0)
		return (0);
	if (s[0] == '-')
	{
		if (minint(s, min) == 0)
			return (0);
	}
	else
	{
		if (maxint(s, max) == 0)
			return (0);
	}
	free(min);
	free(max);
	return (1);
}
