/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:46:45 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 04:31:12 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putstr_fd - Outputs the string 's' to the specified file descriptor.
 *
 * This function writes each character of the string 's' to the file
 * descriptor 'fd' using the write function. It continues until it
 * reaches the null terminator of the string.
 *
 * If 's' is NULL, the function safely returns without doing anything.
 *
 * @param s: The string to output.
 * @param fd: The file descriptor on which to write.
 *
 * @return None
 */
void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
