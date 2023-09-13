/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:43:25 by rbenjami          #+#    #+#             */
/*   Updated: 2023/04/20 12:32:04 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*little)
		return ((char *)big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len)
		{
			if (little[j + 1] == '\0')
				return ((char *)(big + i));
			j++;
		}
		i++;
	}
	return (0);
}

/* #include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
    const char *largestring = "Foo Bar Baz";
    const char *smallstring = "Bar";

    printf("Original: %s\n", strnstr(largestring, smallstring, 5));
    printf("Replicated: %s\n", ft_strnstr(largestring, smallstring, 5));
} */