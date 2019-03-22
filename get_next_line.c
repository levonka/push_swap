/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agottlie <agottlie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 12:25:29 by agottlie          #+#    #+#             */
/*   Updated: 2019/03/22 10:05:07 by agottlie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft/libft.h"
#include <stdio.h>

static int	ft_read_fd(const int fd, char **buff)
{
	int		ret;
	int		i;
	char	*joined_string;
	char	buff_read[BUFF_SIZE + 1];

	if (!(*buff))
		*buff = ft_strnew(BUFF_SIZE);
	ISMALLOC(buff);
	while ((ret = read(fd, buff_read, BUFF_SIZE)) > 0)
	{
		i = 0;
		buff_read[ret] = '\0';
		joined_string = ft_strjoin(*buff, buff_read);
		ISMALLOC(joined_string);
		ft_strdel(buff);
		*buff = joined_string;
		while (buff_read[i] != '\n' && buff_read[i] != '\0')
			i++;
		if (buff_read[i] != '\n' && i != BUFF_SIZE && buff_read[i - 1] != '\n'
			&& buff_read[i] != '\0')
			printerror(6);
		if (ft_strchr(*buff, '\n'))
			break ;
	}
	return (0);
}

static int	ft_solver(char **buff, char **line)
{
	char	*buff_tmp;
	size_t	i;

	i = 0;
	while ((*buff)[i] != '\n' && (*buff)[i] != '\0')
		i++;
	if (i == 0 && (*buff)[i] == '\0')
	{
		*line = ft_strdup("");
		ISMALLOC(line);
		return (0);
	}
	*line = ft_strsub((*buff), 0, i);
	ISMALLOC(line);
	if (i == ft_strlen((*buff)))
		buff_tmp = ft_strdup("");
	else
		buff_tmp = ft_strsub((*buff), i + 1, ft_strlen((*buff)));
	ISMALLOC(buff_tmp);
	ft_strdel(buff);
	(*buff) = buff_tmp;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	**buff;

	if (fd < 0 || read(fd, NULL, 0))
		return (-1);
	if (!buff)
		buff = (char **)malloc(sizeof(char *) * (LIMIT_FD));
	ISMALLOC(buff);
	if (ft_read_fd(fd, &buff[fd]) == -1)
		return (-1);
	ISMALLOC(buff[fd]);
	return (ft_solver(&buff[fd], line));
}
