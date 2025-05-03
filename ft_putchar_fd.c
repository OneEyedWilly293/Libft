/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:24:35 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 04:26:47 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_putchar_fd - Outputs a character to the specified file descriptor
 *
 * This function writes the character 'c' to the specified file descriptor 'fd'
 * using the write system call. It doesn't return any value.
 *
 * Common file descriptors:
 * 0: Standard input (stdin)
 * 1: Standard output (stdout)
 * 2: Standard error (stderr)
 *
 * @param c: The character to output
 * @param fd: The file descriptor on which to write
 *
 * @return No return value.
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
