/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:43:35 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 03:40:10 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isalpha - Checks if a character is an alphabetic character
 *
 * This function checks if the given character is an alphabetic character,
 * meaning it's either an uppercase letter (A-Z) or a lowercase letter (a-z).
 *
 * @param c: The character to check, represented as an int
 *
 * @return Returns 1 if the character is alphabetic, 0 otherwise
 */
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
