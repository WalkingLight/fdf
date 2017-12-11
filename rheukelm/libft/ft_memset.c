/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/31 15:01:46 by rheukelm          #+#    #+#             */
/*   Updated: 2017/05/31 15:04:45 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	if (len == 0)
		return (b);
	str = (unsigned char *)b;
	while (len--)
	{
		*str = (unsigned char)c;
		if (len)
			str++;
	}
	return (b);
}
