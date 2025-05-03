/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:01:33 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 05:47:23 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts a lowercase letter to its uppercase equivalent
 *
 * This function takes a character as input and converts it to uppercase
 * if it's a lowercase letter (a-z). If the character is already uppercase
 * or is not a letter, it remains unchanged.
 *
 * @param c The character to be converted
 *
 * @return  The uppercase equivalent if c is a lowercase letter,
 *          otherwise c remains unchanged
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
