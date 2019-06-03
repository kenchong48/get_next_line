/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchong <kchong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:10:10 by kchong            #+#    #+#             */
/*   Updated: 2019/06/03 15:33:37 by kchong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_processbuf(t_gnl *gnl, char **line)
{
	gnl->call++;
	gnl->blen = ft_strlen(gnl->buff);
	gnl->temp = *line;
	gnl->ptr = ft_strchr(gnl->buff, '\n');
	ft_strdel(&gnl->bufsave);
	if (gnl->ptr == NULL)
		gnl->len = gnl->blen;
	else if (gnl->ptr != NULL)
	{
		gnl->len = (int)(gnl->ptr - gnl->buff);
		if (gnl->len < gnl->blen - 1)
			gnl->bufsave = ft_strsub(gnl->buff, gnl->len + 1, gnl->blen);
	}
	*line = ft_strnjoin(gnl->temp, gnl->buff, gnl->len);
	ft_strdel(&gnl->temp);
	ft_strclr(gnl->buff);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl		gnl[5000];

	if (fd < 0 || fd > 5000 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	gnl[fd].ptr = NULL;
	if (gnl[fd].bufsave != NULL && gnl[fd].call > 0)
	{
		ft_strcpy(gnl[fd].buff, gnl[fd].bufsave);
		ft_processbuf(&gnl[fd], line);
		if ((gnl[fd].ptr != NULL) || gnl[fd].rret < BUFF_SIZE)
			return (1);
	}
	while ((gnl[fd].rret = read(fd, gnl[fd].buff, BUFF_SIZE)) >= 0)
	{
		if (gnl[fd].rret == 0 && *line == NULL)
			return (0);
		ft_processbuf(&gnl[fd], line);
		if ((gnl[fd].ptr != NULL) || gnl[fd].rret < BUFF_SIZE)
			return (1);
	}
	return (-1);
}
