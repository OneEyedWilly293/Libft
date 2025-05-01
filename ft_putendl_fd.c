/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:55:09 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/01 22:27:01 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* This function writes the string s to the file descriptor fd followed by a
 * '\n' to make a new line. It uses ft_putstr_fd to write the string and
 * ft_putchar_fd to write the newline character.
 *
 * Parameters:
 * s - The string to be written to the file descriptor
 * fd - The file descriptor to write to (e.g., 1 for standard output)
 *
 * Return value: None
 */

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
