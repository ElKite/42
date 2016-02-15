/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 12:13:09 by vtarreau          #+#    #+#             */
/*   Updated: 2015/03/21 14:01:08 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define BUFF_SIZE 65

typedef struct			s_fd_list
{
	int					fd;
	char				*buffer;
	int					lline;
	struct s_fd_list	*next;
}						t_fd_list;

int						get_next_line(int const fd, char **line);
#endif
