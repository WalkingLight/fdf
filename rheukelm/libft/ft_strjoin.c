/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheukelm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:28:18 by rheukelm          #+#    #+#             */
/*   Updated: 2017/05/30 17:37:26 by rheukelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp1;
	char	*temp2;

	if (!s1 || !s2)
		return (NULL);
	temp1 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!temp1)
		return (NULL);
	temp2 = temp1;
	while (*s1 != '\0')
		*temp2++ = *s1++;
	while (*s2 != '\0')
		*temp2++ = *s2++;
	*temp2 = '\0';
	return (temp1);
}
