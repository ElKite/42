/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_options.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:11:08 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/27 17:16:41 by vtarreau         ###   ########.fr       */
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
	ft_putchar((st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((st_mode & S_IXOTH) ? 'x' : '-');
//check socket etc
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
	ft_putnspace(m->size - ft_strlen(ft_itoa(stat->st_size)));
	ft_putstr(ft_itoa(stat->st_size));
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

void	display_files_l(t_filew *file, t_manage *manage)
{
	ft_display_types_and_rights(file->stat->st_mode, file->stat->st_nlink,
								manage->links);
	ft_display_owner_and_group(file->stat, manage);
	ft_display_time(file->stat->st_mtime);
	ft_putendl(file->name);
}
