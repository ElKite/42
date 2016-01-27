/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_options.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 12:11:08 by vtarreau          #+#    #+#             */
/*   Updated: 2016/01/27 14:26:45 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_ls.h"

void	ft_display_types_and_rights(mode_t st_mode)
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
	char *ret;

	ret = ft_strnew(10);
	ret[0] = ((st_mode & S_IRUSR) ? 'r' : '-');
	ret[1] = ((st_mode & S_IWUSR) ? 'w' : '-');
	ret[2] = ((st_mode & S_IXUSR) ? 'x' : '-');
	ret[3] = ((st_mode & S_IRGRP) ? 'r' : '-');
	ret[4] = ((st_mode & S_IWGRP) ? 'w' : '-');
	ret[5] = ((st_mode & S_IXGRP) ? 'x' : '-');
	ret[6] = ((st_mode & S_IROTH) ? 'r' : '-');
	ret[7] = ((st_mode & S_IWOTH) ? 'w' : '-');
	ret[8] = ((st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr(ret);
	ft_strdel(&ret);
}


void	display_files_l(t_filew *file)
{
	if (file->stat == NULL)
		dprintf(1, "NULL\n");
	ft_display_types_and_rights(file->stat->st_mode);
	ft_putendl(file->name);
}
