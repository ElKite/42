/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 09:13:09 by vtarreau          #+#    #+#             */
/*   Updated: 2015/02/13 14:35:28 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushback(t_list *lst, t_list *new)
{
	t_list *save;

	if (!lst)
		return (0);
	save = lst;
	while (lst->next)
		lst = lst->next;
	lst->next = new;
	return (save);
}
