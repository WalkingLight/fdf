/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 11:30:00 by rheukelm          #+#    #+#             */
/*   Updated: 2017/06/09 11:55:35 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		size;

	i = 0;
	size = 0;
	while (s1[size])
		size++;
	while (i < n && s2[i])
	{
		s1[size] = s2[i];
		size++;
		i++;
	}
	s1[size] = '\0';
	return (s1);
}
