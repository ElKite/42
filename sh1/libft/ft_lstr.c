/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 09:35:13 by vtarreau          #+#    #+#             */
/*   Updated: 2015/02/19 09:36:19 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstr(t_list **lst)
{
	t_list *save;
	t_list *tmp;

	tmp = *lst;
	save = (*lst)->next;
	while ((*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = tmp;
	(*lst)->next->next = NULL;
	*lst = save;
}
