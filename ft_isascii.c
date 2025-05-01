/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:43:26 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/01 22:02:28 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isascii - Checks if a character is a valid ASCII character
 *
 * This function tests whether the given integer value represents a character
 * in the ASCII character set (0-127).
 *
 * @c: The character to check, represented as an integer
 *
 * Return: 1 (true) if the character is in the ASCII range, 0 (false) otherwise
 */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
