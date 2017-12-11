/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:37:24 by rheukelm          #+#    #+#             */
/*   Updated: 2017/06/27 15:37:26 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_draw_line(t_var *f)
{
	double	tx;
	float	dx;
	float	dy;

	tx = 0;
	dx = f->x2 - f->x1;
	dy = f->y2 - f->y1;
	while (tx <= 1)
	{
		f->x = f->x1 + (dx * tx);
		f->y = f->y1 + (dy * tx);
		mlx_pixel_put(f->mlx, f->win, f->x, f->y, 0x00FFFFFF);
		tx += 1 / sqrt((dx * dx) + (dy * dy));
	}
}

static void	ft_horizontal(t_var *f, int j, int i)
{
	f->x1 = 60 + (i * f->zoom) + (j * f->zoom);
	f->x2 = 60 + ((i + 1) * f->zoom) + (j * f->zoom);
	f->y1 = ((800 + (j * f->zoom)) / 2) - (((i * f->zoom)
				+ (2 * f->tab[j][i])) / 2);
	f->y2 = ((800 + (j * f->zoom)) / 2) - ((((i + 1) * f->zoom)
				+ (2 * f->tab[j][i + 1])) / 2);
	ft_draw_line(f);
}

static void	ft_vertical(t_var *f, int j, int i)
{
	f->x1 = 60 + (i * f->zoom) + (j * f->zoom);
	f->x2 = 60 + (i * f->zoom) + ((j + 1) * f->zoom);
	f->y1 = ((800 + (j * f->zoom)) / 2) - (((i * f->zoom)
				+ (2 * f->tab[j][i])) / 2);
	f->y2 = ((800 + ((j + 1) * f->zoom)) / 2) - (((i * f->zoom)
				+ (2 * f->tab[j + 1][i])) / 2);
	ft_draw_line(f);
}

int			ft_call(t_var *f)
{
	int		i;
	int		j;

	j = 0;
	while (j < f->lines)
	{
		i = 0;
		while (i < f->length)
			ft_horizontal(f, j, i++);
		j++;
	}
	j = 0;
	while (j < f->lines - 1)
	{
		i = 0;
		while (i < f->length + 1)
			ft_vertical(f, j, i++);
		j++;
	}
	return (0);
}

int			ft_start(char *buf, int lines, int length)
{
	t_var	f;

	f.tab = ft_newtab(buf, lines, length);
	f.lines = lines;
	f.length = length;
	if (f.lines >= f.length)
		f.zoom = 400 / f.lines;
	else
		f.zoom = 400 / f.length;
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, 800, 800, "fdf");
	mlx_expose_hook(f.win, &ft_expose_hook, &f);
	mlx_key_hook(f.win, &ft_key_hook, &f);
	mlx_loop(f.mlx);
	return (0);
}
