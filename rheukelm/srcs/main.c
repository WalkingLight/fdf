/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 10:33:00 by rheukelm          #+#    #+#             */
/*   Updated: 2017/06/27 10:33:02 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				**ft_newtab(char *buf, int lines, int length)
{
	int		i;
	int		k;
	int		j;
	int		**tab;

	k = 0;
	j = 0;
	if (!(tab = (int **)malloc(sizeof(int *) * lines)))
		return (NULL);
	while (buf[k] != '\0' && j < lines)
	{
		i = 0;
		if (!(tab[j] = (int *)malloc(sizeof(int) * length)))
			return (NULL);
		while (buf[k] != '\n' && buf[k] != '\0' && j < lines)
		{
			tab[j][i++] = ft_atoi_count(buf, &k);
			while (buf[k] == ' ')
				k++;
		}
		k++;
		j++;
	}
	return (tab);
}

static int		ft_initialise(char *argv, int argc, int *fd)
{
	if (argc != 2)
	{
		ft_putstr_fd("usage: ./FdF [input_file]\n", 2);
		return (-1);
	}
	if (BUFF_SIZE < 1)
	{
		ft_putstr_fd("error: BUFF_SIZE must be greater than 0\n", 2);
		return (-1);
	}
	if ((*fd = open(argv, O_RDONLY)) == -1)
	{
		ft_putstr_fd("error: cannot open input file\n", 2);
		return (-1);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	char	*line;
	char	*buf;
	int		fd;
	int		lines;
	int		length;

	lines = 0;
	buf = ft_strnew(1);
	if (ft_initialise(argv[1], argc, &fd) == -1)
		return (0);
	while (get_next_line(fd, &line) > 0 && lines++ > -1)
		buf = ft_strjoin(ft_strjoin(buf, line), "\n");
	if (get_next_line(fd, &line) != 0)
	{
		ft_putstr_fd("error: get_next_line returned -1\n", 2);
		free(buf);
		return (0);
	}
	if (ft_error_check(buf, &length) != NULL)
		ft_start(buf, lines, length);
	if (close(fd) == -1)
		ft_putstr_fd("error: cannot close input file", 2);
	return (0);
}
