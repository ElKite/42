/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 11:37:14 by vtarreau          #+#    #+#             */
/*   Updated: 2015/01/12 16:05:06 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *a;

	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		a = (*alst)->next;
		free(*alst);
		*alst = NULL;
		alst = &a;
	}
}
