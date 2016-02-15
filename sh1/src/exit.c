/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/21 14:20:58 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/27 18:20:55 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh1.h"

int		build_exit(char **s)
{
	if (ft_tablen(s) > 2)
		return (ft_putstr_fd("exit: Too much arguments\n", 2), 1);
	if (s[1] && ft_is_str_digit(s[1]) == 0)
		return (ft_putstr_fd("exit: Only numerical arguments allowed", 2), 1);
	else
	{
		ft_putendl("exit");
		if (s[1])
			exit(ft_atoi(s[1]));
		else
			exit(0);
	}
}
