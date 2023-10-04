/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbenjami <rbenjami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:09:14 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/04 12:31:18 by rbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

/**
 * @brief This function writes the err (2) the error msg
 * @param err The msg to be written
 */
int	error_msg(char *err)
{
	perror(err);
	exit(1);
}

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}