/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:51:32 by rheukelm          #+#    #+#             */
/*   Updated: 2017/06/27 15:51:34 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_isvalid(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '-' && (buf[i + 1] < '0' || buf[i + 1] > '9'))
		{
			ft_putstr_fd("error: '-' must be followed by a digit", 2);
			return (-1);
		}
		if (buf[i] != '-' && buf[i] != ' ' && buf[i] != '\n'\
			&& !(buf[i] >= '0' && buf[i] <= '9'))
		{
			ft_putstr_fd("error: bad character in file\n", 2);
			return (-1);
		}
		i++;
	}
	return (1);
}

static int		ft_length_check(char *buf)
{
	t_var	v;

	v.i = 0;
	v.length = -1;
	while (buf[v.i] != '\0')
	{
		v.lines = 0;
		while (buf[v.i] != ' ')
			v.i++;
		while (buf[v.i] != '\n' && buf[v.i] != '\0')
		{
			while (buf[v.i] == ' ' && buf[v.i] != '\n' && buf[v.i] != '\0')
				v.i++;
			if (buf[v.i] != '\n' && buf[v.i] != '\0')
				v.lines++;
			while (buf[v.i] != ' ' && buf[v.i] != '\n' && buf[v.i] != '\0')
				v.i++;
		}
		if (v.length == -1)
			v.length = v.lines;
		else if (v.lines != v.length)
			return (-1);
		v.i++;
	}
	return (v.length);
}

char			*ft_error_check(char *buf, int *length)
{
	int		i;

	i = 0;
	if (buf[0] == '\0')
	{
		ft_putstr_fd("error: file is empty\n", 2);
		return (NULL);
	}
	while (buf[i] != '\0')
		i++;
	buf[i - 1] = '\0';
	if (ft_isvalid(buf) == -1)
		return (NULL);
	if ((*length = ft_length_check(buf)) == -1)
	{
		ft_putstr_fd("error: lines of file are not the same length\n", 2);
		return (NULL);
	}
	return (buf);
}
