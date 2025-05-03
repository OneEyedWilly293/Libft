/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:55:09 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 18:27:12 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function writes the string s to the file descriptor fd followed by a
 * '\n' to make a new line. It uses ft_putstr_fd to write the string and
 * ft_putchar_fd to write the newline character.
 *
 * @param s - The string to be written to the file descriptor
 * @param fd - The file descriptor to write to (e.g., 1 for standard output)
 *
 * @return None
 */
void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
