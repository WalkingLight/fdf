/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 14:22:59 by rheukelm          #+#    #+#             */
/*   Updated: 2017/06/08 15:51:38 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (!((int *)dst > (int *)src && (int *)src + len > (int *)dst))
		ft_memcpy(dst, (void *)src, len);
	else
	{
		i = len;
		while (i > 0)
		{
			i--;
			*((char *)dst + i) = *((char *)src + i);
		}
	}
	return (dst);
}
