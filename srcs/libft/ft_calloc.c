/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjamim <rbenjamim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:13:47 by rbenjami          #+#    #+#             */
/*   Updated: 2023/04/21 10:03:37 by rbenjamim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned long int	i;
	unsigned long int	l_size;
	unsigned long int	l_type;
	char				*memory;

	i = 0;
	l_type = size;
	l_size = nmemb;
	memory = malloc(l_size * l_type);
	if (!memory)
		return (NULL);
	while (i < (l_size * l_type))
	{
		memory[i] = '\0';
		i++;
	}
	return (memory);
}
