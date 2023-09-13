/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjamim <rbenjamim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:41:30 by rbenjami          #+#    #+#             */
/*   Updated: 2023/04/21 09:45:42 by rbenjamim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str3;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str3)
		return (NULL);
	while (*s1)
	{
		str3[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		str3[i] = *s2;
		i++;
		s2++;
	}
	str3[i] = '\0';
	return (str3);
}

/* #include <stdio.h>
int	main(void)
{
  const char str1[6] = "OLA A";
  const char str2[6] = "TODOS";
  printf("Result: %s\n", ft_strjoin(str1, str2));
} */