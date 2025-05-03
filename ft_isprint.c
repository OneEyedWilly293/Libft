/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:58:41 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 03:39:47 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isprint - Checks if a character is printable
 *
 * This function determines whether the passed character is printable,
 * which means it occupies a printing position on a display (between
 * ASCII values 32 and 126 inclusive).
 *
 * @param c: The character to check (passed as an int)
 * @return 1 if the character is printable, 0 otherwise
 */
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
