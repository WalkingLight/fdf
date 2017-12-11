/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 17:13:00 by rheukelm          #+#    #+#             */
/*   Updated: 2017/06/20 10:00:33 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		read_to_data(int const fd, char **data)
{
	char	*buff;
	char	*new_str;
	int		read_bytes;

	if (!(buff = (char *)malloc(sizeof(*buff) * (BUFF_SIZE + 1))))
		return (-1);
	read_bytes = read(fd, buff, BUFF_SIZE);
	if (read_bytes > 0)
	{
		buff[read_bytes] = '\0';
		new_str = ft_strjoin(*data, buff);
		free(*data);
		*data = new_str;
	}
	free(buff);
	return (read_bytes);
}

int				get_next_line(int const fd, char **line)
{
	static char	*data = NULL;
	char		*bin;
	int			temp;

	if ((!data && (data = (char *)malloc(sizeof(*data))) == NULL) || !line
				|| fd < 0 || BUFF_SIZE < 0)
		return (-1);
	bin = ft_strchr(data, '\n');
	while (bin == NULL)
	{
		temp = read_to_data(fd, &data);
		if (temp == 0)
		{
			if (ft_strlen(data) == 0)
				return (0);
			data = ft_strjoin(data, "\n");
		}
		if (temp < 0)
			return (-1);
		else
			bin = ft_strchr(data, '\n');
	}
	*line = ft_strsub(data, 0, ft_strlen(data) - ft_strlen(bin));
	data = ft_strdup(bin + 1);
	return (1);
}
