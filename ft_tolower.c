/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:06:53 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 05:46:42 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts an uppercase letter to the corresponding lowercase letter
 *
 * This function takes an integer representing a character and converts it to
 * lowercase if it's an uppercase letter (A-Z). If the character is not an
 * uppercase letter, it returns the character unchanged.
 *
 * @param c: The character to convert
 *
 * @return  The lowercase equivalent if c is an uppercase letter, otherwise c
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}
