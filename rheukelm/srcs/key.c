/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 17:23:18 by rheukelm          #+#    #+#             */
/*   Updated: 2017/06/30 17:23:21 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_expose_hook(t_var *f)
{
	ft_call(f);
	return (0);
}

int			ft_key_hook(int keycode, t_var *f)
{
	if (keycode == 53)
	{
		mlx_clear_window(f->mlx, f->win);
		exit(0);
	}
	return (0);
}
