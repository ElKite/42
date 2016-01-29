/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:12:23 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/29 14:52:36 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	ft_putnspace(int i)
{
	while (i >= 0)
	{
		ft_putchar(' ');
		i--;
	}
}

void	ft_display_rights(mode_t st_mode)
{
	ft_putchar((st_mode & S_IRUSR) ? 'r' : '-');
    ft_putchar((st_mode & S_IWUSR) ? 'w' : '-');
	if (st_mode & S_ISUID)
		ft_putchar((st_mode & S_IXUSR) ? 's' : 'S');
	else
		ft_putchar((st_mode & S_IXUSR) ? 'x' : '-');
    ft_putchar((st_mode & S_IRGRP) ? 'r' : '-');
    ft_putchar((st_mode & S_IWGRP) ? 'w' : '-');
	if (st_mode & S_ISGID)
		ft_putchar((st_mode & S_IXGRP) ? 's' : 'S');
	else
		ft_putchar((st_mode & S_IXGRP) ? 'x' : '-');
    ft_putchar((st_mode & S_IROTH) ? 'r' : '-');
    ft_putchar((st_mode & S_IWOTH) ? 'w' : '-');
	if (st_mode & S_ISVTX)
		ft_putchar((st_mode & S_IXOTH) ? 't' : 'T');
	else
		ft_putchar((st_mode & S_IXOTH) ? 'x' : '-');
}

void	ft_link_size(struct stat *stat, t_path *path)
{
	struct passwd	*pass;
	struct group	*name;

	pass = getpwuid(stat->st_uid);
	name = getgrgid(stat->st_gid);
	if (ft_strlen(ft_itoa(stat->st_nlink)) > path->manage->links)
		path->manage->links = ft_strlen(ft_itoa(stat->st_nlink)) + 2;
	if (ft_strlen(pass->pw_name) > path->manage->owner)
		path->manage->owner = ft_strlen(pass->pw_name);
	if (ft_strlen(name->gr_name) > path->manage->groups)
		path->manage->groups = ft_strlen(name->gr_name) + 1;
	if (ft_strlen(ft_itoa(stat->st_size)) > path->manage->size)
		path->manage->size = ft_strlen(ft_itoa(stat->st_size)) + 1;
	path->manage->sizeblock += stat->st_blocks;
}

void	show_link(char *name, t_filew *file)
{
	char	result[256];
	int		ret;

	ret = readlink(ft_strjoins(name, "/", file->name), result, 256);
	result[ret] = 0;
	ft_putstr(" -> ");
	ft_putendl(result);
}

void	count_sizes(t_env *env, t_path *path)
{
	t_filew	*tmp;
//	dprintf(1, "TEST\n");
	if (env->format_out == TRUE)
	{
		tmp = path->files;
		while (tmp != NULL)
		{
			ft_link_size(tmp->stat, path);
			tmp = tmp->next;
		}
	}
}
