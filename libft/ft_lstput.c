/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 11:06:59 by vtarreau          #+#    #+#             */
/*   Updated: 2014/12/13 17:03:11 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_lstput(t_list *lst, void (*f)(const char *))
{
	while (lst)
	{
		f(((t_info*)(const char*)lst->content)->name);
		lst = lst->next;
	}
	return (0);
}
