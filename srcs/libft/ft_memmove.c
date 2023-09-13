/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjamim <rbenjamim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:40:48 by rbenjami          #+#    #+#             */
/*   Updated: 2023/04/21 09:53:55 by rbenjamim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;

	s = (char *)src;
	d = (char *)dest;
	if (dest == src)
		return (dest);
	if (!dest && !src)
		return (0);
	if (dest > src)
		while (n--)
			d[n] = s[n];
	else
		ft_memcpy(d, s, n);
	return (d);
}
