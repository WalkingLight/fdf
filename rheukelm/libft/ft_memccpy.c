/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 15:53:46 by rheukelm          #+#    #+#             */
/*   Updated: 2017/06/09 14:39:47 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*csrc;
	char	*cdst;

	csrc = (char *)src;
	cdst = (char *)dst;
	while (n > 0 && *csrc != c)
	{
		*cdst++ = *csrc++;
		n--;
	}
	if (n > 0)
	{
		*cdst++ = *csrc++;
		return ((void *)cdst);
	}
	return (NULL);
}
