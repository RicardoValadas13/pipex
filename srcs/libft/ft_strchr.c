/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:24:19 by rbenjami          #+#    #+#             */
/*   Updated: 2023/10/04 12:30:11 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	d;

	d = c;
	while (s && *s)
	{
		if (*s == d)
			return ((char *)s);
		s++;
	}
	if (s && *s == d)
		return ((char *)s);
	return (NULL);
}
