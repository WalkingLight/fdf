/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsidler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 13:44:57 by fsidler           #+#    #+#             */
/*   Updated: 2016/03/04 13:34:12 by fsidler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <errno.h>
# include <mlx.h>

# define OP_COLOR 0x6CD2A6

typedef struct	s_var
{
	int			l;
	int			i;
	int			length;
	int			zoom;
	int			xmove;
	int			ymove;
	double		z;
	int			**tab;
	double		x;
	double		y;
	double		x0;
	double		x1;
	double		y0;
	double		y1;
	void		*mlx;
	void		*win;
}				t_var;

int				ft_call(t_var *f);
int				ft_expose_hook(t_var *f);
int				ft_key_hook(int keycode, t_var *f);
int				ft_init_struct(char *buf, int nbl, int nbi);
int				**ft_newtab(char *buf, int nbl, int nbi, int j);
char			*ft_endbuf(char *buf, int *length);

#endif
