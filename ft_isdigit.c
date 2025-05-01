/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 14:29:19 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/01 21:59:20 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_isdigit - Checks if a character is a digit (0-9)
 * 
 * This function determines whether the passed character is a decimal digit
 * character. Decimal digits are: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9.
 *
 * @param c: The character to be checked
 * @return: Non-zero value (1) if c is a digit, zero (0) otherwise
 */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
