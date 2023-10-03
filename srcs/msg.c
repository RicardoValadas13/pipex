/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardovaladas <ricardovaladas@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:09:14 by ricardovala       #+#    #+#             */
/*   Updated: 2023/10/03 11:11:00 by ricardovala      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include "../srcs/libft/libft.h"

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