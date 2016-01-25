/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_reverse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 15:07:19 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/25 16:02:38 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

t_filew	*ft_reverse_files(t_filew *llist)
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

t_path	*ft_reverse_path(t_path *list)
{
	t_path*tmp;
	t_path*first;
	t_path*new;

	tmp = list->paths;
	first = NULL;
	while (tmp)
	{
		new = first;
		first = tmp;
		tmp = tmp->next;
		first->next = new;
	}
	list->paths = first;
	return first;
}

void	ft_swap_path(t_path	*cur, t_path *next)
{
	void			*swap;
	struct s_path	*swap_path;
	struct s_filew	*swap_files;

	swap = cur->name;
	cur->name = next->name;
	next->name = swap;
	swap_path = cur->paths;
	cur->paths = next->paths;
	next->paths = swap_path;
	swap_files = cur->files;
	cur->files = next->files;
	next->files = swap_files;
}


t_path		*ft_sort_ascii_path(t_path *lst)
{
	t_path	*tmp;
	
	if (!lst || !lst->next)
		return NULL;
	tmp = lst;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, tmp->next->name) > 0)
		{
			ft_swap_path(tmp, tmp->next);
			tmp = lst;
		}
		tmp = tmp->next;
	}
	return lst;
}
