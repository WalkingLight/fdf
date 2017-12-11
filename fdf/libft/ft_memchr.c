/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/08 16:15:37 by rheukelm          #+#    #+#             */
/*   Updated: 2017/06/08 16:33:53 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	c2;
	int				i;

	i = 0;
	c2 = (unsigned char)c;
	str = (unsigned char *)s;
	while (n--)
	{
		if (str[i] == c2)
			return (str + i);
		i++;
	}
	return (NULL);
}
