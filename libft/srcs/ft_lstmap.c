/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:54:12 by vtarreau          #+#    #+#             */
/*   Updated: 2015/01/12 16:43:09 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *result;
	t_list *temp;
	t_list *temp1;

	if (!lst || !f)
		return (NULL);
	temp1 = f(lst);
	result = ft_lstnew(temp1->content, temp1->content_size);
	if (result)
	{
		temp = result;
		lst = lst->next;
		while (lst)
		{
			temp1 = f(lst);
			temp->next = ft_lstnew(temp1->content, temp1->content_size);
			temp = temp->next;
			lst = lst->next;
		}
	}
	return (result);
}
