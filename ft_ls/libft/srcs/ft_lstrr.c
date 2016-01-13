/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 09:31:54 by vtarreau          #+#    #+#             */
/*   Updated: 2015/02/19 09:33:58 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrr(t_list **lst)
{
	t_list *save;
	t_list *tmp;

	tmp = *lst;
	while ((*lst)->next->next)
		*lst = (*lst)->next;
	save = (*lst)->next;
	(*lst)->next = NULL;
	save->next = tmp;
	*lst = save;
}
