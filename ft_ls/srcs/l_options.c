/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_options.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:11:08 by vtarreau          #+#    #+#             */
/*   Updated: 2016/02/01 12:18:04 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	ft_display_types_and_rights(mode_t st_mode, nlink_t st_nlink, int i)
{
	if ((S_ISFIFO(st_mode)))
		ft_putchar('p');
	else if ((S_ISCHR(st_mode)))
		ft_putchar('c');
	else if ((S_ISDIR(st_mode)))
		ft_putchar('d');
	else if ((S_ISBLK(st_mode)))
		ft_putchar('b');
	else if ((S_ISREG(st_mode)))
		ft_putchar('-');
	else if ((S_ISLNK(st_mode)))
		ft_putchar('l');
	else if ((S_ISSOCK(st_mode)))
		ft_putchar('s');
	ft_display_rights(st_mode);
	ft_putnspace(i - ft_strlen(ft_itoa(st_nlink)));
	ft_putstr(ft_itoa(st_nlink));
}

void	ft_display_owner_and_group(struct stat *stat, t_manage *m)
{
	struct passwd	*pass;
	struct group	*name;

	if (getpwuid(stat->st_uid))
	{
		pass = getpwuid(stat->st_uid);
		ft_putnspace(m->owner - ft_strlen(pass->pw_name));
		ft_putstr(pass->pw_name);
	}
	if (getgrgid(stat->st_gid))
	{
		name = getgrgid(stat->st_gid);
		ft_putnspace(m->groups - ft_strlen(name->gr_name));
		ft_putstr(name->gr_name);
	}
}
void	ft_display_size_and_major(struct stat *stat, t_manage *m)
{
	if (S_ISBLK(stat->st_mode) || S_ISCHR(stat->st_mode))
	{
		ft_putchar(' ');
		ft_putstr(ft_itoa(major(stat->st_rdev)));
		ft_putstr(", ");
		ft_putstr(ft_itoa(minor(stat->st_rdev)));
		ft_putchar('\t');
	}
	else 
	{
		ft_putnspace(m->size - ft_strlen(ft_itoa(stat->st_size)));
		ft_putstr(ft_itoa(stat->st_size));
	}
}

void	ft_display_time(const time_t mtime)
{
	char *date;
	char *tmp;
	char *tmp2;
	
	date = ft_strdup(ctime(&mtime));
	tmp = ft_strsub(date, 4, 7);
	if (time(0) - mtime >= 15724800 || time(0) < mtime)
	{
		tmp2 = ft_strsub(date, 20, 4);
		tmp2 = ft_strjoin(ft_strdup(" "), tmp2);
		tmp2 = ft_strjoin(tmp2, ft_strdup(" "));
		date = ft_strjoin(tmp, tmp2);
		date = ft_strjoin(ft_strdup(" "), date);
	}
	else
	{
		tmp2 = ft_strsub(date,  11, 5 );
		tmp2 = ft_strjoin(tmp2, ft_strdup(" "));
		date = ft_strjoin(tmp, tmp2);
		date = ft_strjoin(ft_strdup(" "), date);
	}
	ft_putstr(date);
}

void	display_files_l(t_filew *file, t_manage *manage, char *name)
{
	ft_display_types_and_rights(file->stat->st_mode, file->stat->st_nlink,
								manage->links);
	ft_display_owner_and_group(file->stat, manage);
	ft_display_size_and_major(file->stat, manage);
	ft_display_time(file->stat->st_mtime);
	ft_putstr(file->name);
	if (S_ISLNK(file->stat->st_mode))
	{
		show_link(name, file);
/*		char *ret = (char*)malloc((sizeof(char) * 128));
		readlink(name, ret, 128);
		dprintf(1, "TEST %s", ret);*/
	}
	else
		ft_putchar('\n');
}
