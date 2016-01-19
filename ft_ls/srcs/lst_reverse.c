/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:07:19 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/19 15:16:14 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

t_filew	*ft_reverse(t_filew *llist)
{
	t_filew *tmp1;
	t_filew *tmp2;
	t_filew *list;

	list = llist;
	if (list != NULL)
	{
		tmp1 = list->next;
		list->next = NULL;
		while (tmp1 != NULL)
		{
			tmp2 = tmp1->next;
			tmp1->next = list;
			list = tmp1;
			tmp1 = tmp2;
		}
	}
	return (list);
}
