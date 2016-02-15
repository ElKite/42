/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 15:53:01 by vtarreau          #+#    #+#             */
/*   Updated: 2015/01/12 17:45:28 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list *ft_lstnew(void const *content, size_t content_size)
{
	t_list *list1;

	list1 = (t_list*)ft_memalloc(sizeof(t_list));
	if (content && content != NULL)
	{
		list1->content = ft_memalloc(content_size);
		ft_memcpy(list1->content, content, content_size);
		list1->content_size = content_size;
		list1->next = NULL;
	}
	if (!content || content == NULL)
	{
		list1->content = NULL;
		list1->content_size = 0;
		list1->next = NULL;
	}
	return (list1);
}
