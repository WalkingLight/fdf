/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 14:04:49 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/04 13:40:33 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_hexa(char *buf, int i, int num, int start)
{
	if (buf[i - 1] < '0' || buf[i - 1] > '9')
		return (-1);
	i++;
	if (buf[i] != '0' || buf[i + 1] != 'x' || buf[num] != ' ')
		return (-1);
	i += 2;
	while (i < num)
	{
		if ((buf[i] < '0' || buf[i] > '9') && (buf[i] < 'A' || buf[i] > 'F'))
			return (-1);
		i++;
	}
	while (start < num)
	{
		buf[start] = ' ';
		start++;
	}
	return (1);
}

static int	ft_length_error(char *buf)
{
	t_var v;

	v.i = 0;
	v.length = -1;
	while (buf[v.i] != '\0')
	{
		v.l = 0;
		while (buf[v.i] == ' ')
			v.i++;
		while (buf[v.i] != '\n' && buf[v.i] != '\0')
		{
			while (buf[v.i] == ' ' && buf[v.i] != '\n' && buf[v.i] != '\0')
				v.i++;
			if (buf[v.i] != '\n' && buf[v.i] != '\0')
				v.l++;
			while (buf[v.i] != ' ' && buf[v.i] != '\n' && buf[v.i] != '\0')
				v.i++;
		}
		if (v.length == -1)
			v.length = v.l;
		else if (v.l != v.length)
			return (-1);
		v.i++;
	}
	return (v.length);
}

static int	ft_start_error(char *buf)
{
	int		i;

	i = 0;
	while (buf[i] != '\0')
	{
		if ((buf[i] < '0' || buf[i] > '9') && buf[i] != '-' && buf[i] != ' ')
		{
			ft_putstr_fd("error: lines must start by a digit or space\n", 2);
			return (-1);
		}
		while (buf[i] != '\n' && buf[i] != '\0')
			i++;
		i++;
	}
	return (1);
}

static int	ft_invalid(char *buf, int i)
{
	while (buf[i] != '\0')
	{
		if (buf[i] == '-' && (buf[i + 1] < '0' || buf[i + 1] > '9'))
		{
			ft_putstr_fd(
					"error: '-' must be followed only by a digit\n", 2);
			return (-1);
		}
		if (buf[i] != '-' && buf[i] != ' ' && buf[i] != '\n'\
			&& !(buf[i] >= '0' && buf[i] <= '9'))
		{
			if (buf[i] == ',' && ft_hexa(buf, i, i + 9, i) == -1)
			{
				ft_putstr_fd("error: hexadecimal error\n", 2);
				return (-1);
			}
			else
			{
				ft_putstr_fd("error: bad character in file\n", 2);
				return (-1);
			}
		}
		i++;
	}
	return (1);
}

char		*ft_endbuf(char *buf, int *length)
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
	if (ft_start_error(buf) == -1 || ft_invalid(buf, 0) == -1)
		return (NULL);
	if ((*length = ft_length_error(buf)) == -1)
	{
		ft_putstr_fd("error: lines of the file are not the same length\n", 2);
		return (NULL);
	}
	return (buf);
}
