/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 14:46:42 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/26 15:22:37 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

int			ft_is_hidden(t_env *env, char *name)
{
	if (env->show_dot == FALSE)
		if (name[0] == '.' && name[1] != '/')
			return (1);
	return (0);
}

int			ft_is_dot_dotdot(t_env *env, int type, char *name)
{
	if (env->recursive == TRUE && type == DT_DIR && env->show_dot == TRUE)
	{
		if (ft_strcmp(name, ".") == 0 || ft_strcmp(name, "..") == 0)
			return (1);
	}
	return (0);
}

void		ft_swap(t_filew *cur, t_filew *next)
{
	void		*swap;
	int			tmp;
	struct stat *tmpp;

	swap = cur->name;
	cur->name = next->name;
	next->name = swap;
	tmp = cur->type;
	cur->type = next->type;
	next->type = tmp;
	tmpp = cur->stat;
	cur->stat = next->stat;
	next->stat = tmpp;
}

t_filew		*ft_sort_ascii(t_filew *lst)
{
	t_filew	*tmp;
	int	flag;

	flag = 1;
	if (!lst || !lst->next)
		return NULL;
	while (flag)
	{
		tmp = lst;
		flag = 0;
		while (tmp->next)
		{
			if (ft_strcmp(tmp->name, tmp->next->name) > 0)
			{
				ft_swap(tmp, tmp->next);
				flag = 1;
			}
			tmp = tmp->next;
		}
	}
	return lst;
}
