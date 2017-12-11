/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 14:17:50 by rheukelm          #+#    #+#             */
/*   Updated: 2017/06/27 14:17:52 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <math.h>
# include <stdio.h>

typedef struct			s_var
{
	int					i;
	int					lines;
	int					length;
	int					zoom;
	int					**tab;
	double				x;
	double				x1;
	double				x2;
	double				y;
	double				y1;
	double				y2;
	void				*mlx;
	void				*win;
}						t_var;

int				**ft_newtab(char *buf, int lines, int length);
char			*ft_error_check(char *buf, int *length);
int				ft_start(char *buf, int lines, int length);
int				ft_call(t_var *f);
int				ft_expose_hook(t_var *f);
int				ft_key_hook(int keycode, t_var *f);

#endif