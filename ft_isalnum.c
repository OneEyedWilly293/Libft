/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 19:43:08 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 04:13:47 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *	This function checks if the character is alphanumeric
 * (either a letter or a digit).
 *
 * @param c - The character to check (represented as an int)
 *
 * @return return value: Non-zero value (1) if c is alphanumeric,
 * 		zero (0) otherwise.
*/
int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90)
		|| (c >= 97 && c <= 122))
		return (1);
	return (0);
}
