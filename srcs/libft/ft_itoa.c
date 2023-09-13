/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjamim <rbenjamim@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 09:57:39 by rbenjamim         #+#    #+#             */
/*   Updated: 2023/04/21 10:06:49 by rbenjamim        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_number(char *str, long n, int len)
{
	while (n > 0)
	{
		str[len - 1] = (n % 10) + 48;
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len_n;
	long	nbr;

	nbr = n;
	len_n = ft_len(n);
	str = (char *)malloc(len_n + 1);
	if (!str)
		return (0);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	if (nbr == 0)
	{
		str[0] = '0';
		str[len_n] = '\0';
		return (str);
	}
	str[len_n] = '\0';
	return (ft_number(str, nbr, len_n));
}
