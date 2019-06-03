/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:10:12 by kchong            #+#    #+#             */
/*   Updated: 2019/06/03 15:33:15 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include "libft/libft.h"

# define BUFF_SIZE 100

typedef struct		s_gnl
{
	char			*bufsave;
	char			*ptr;
	char			*temp;
	char			buff[BUFF_SIZE + 1];
	int				blen;
	int				rret;
	int				call;
	int				len;
}					t_gnl;

int					get_next_line(const int fd, char **line);
void				ft_processbuf(t_gnl *gnl, char **line);

#endif
