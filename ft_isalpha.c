/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:43:35 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/01 21:57:41 by jgueon           ###   ########.fr       */
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
 * @return: Returns 1 if the character is alphabetic, 0 otherwise
 *
 * Note: This function mimics the behavior of the standard C library's isalpha()
 * function. The parameter is an int because the standard isalpha() function
 * can handle EOF (-1) and unsigned char values (0-255).
 */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

//return (((unsigned)c - 'A' < 26)|| ((unsigned)c - 'a' < 26));