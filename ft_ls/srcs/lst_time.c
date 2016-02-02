/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:46:21 by vtarreau          #+#    #+#             */
/*   Updated: 2016/02/02 15:52:04 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_sort_time_path(t_path *lst)
{
	t_path	*tmp;

	tmp = lst->paths;
	while (tmp && tmp->next != NULL)
	{
		if (tmp->stat->st_mtime < tmp->next->stat->st_mtime)
		{
			ft_swap_path(tmp, tmp->next);
			tmp = lst->paths;
			continue ;
		}
		tmp = tmp->next;
	}
}

void		ft_sort_time_files(t_filew *lst)
{
	t_filew *tmp;
	int		flag;

	flag = 1;
	if (!lst || !lst->next)
		return ;
	while (flag)
	{
		tmp = lst;
		flag = 0;
		while (tmp->next)
		{
			if (tmp->stat->st_mtime < tmp->next->stat->st_mtime)
			{
				ft_swap(tmp, tmp->next);
				flag = 1;
			}
			tmp = tmp->next;
		}
	}
}
