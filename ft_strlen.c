/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:48:02 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/01 22:03:47 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ft_strlen - calculates the length of a string
 *
 * This function counts the number of characters in a string until
 * it reaches the null terminator '\0'.
 *
 * @param s: The string whose length is to be calculated
 * @return: The number of characters in the string (excluding the null terminator)
 */

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	return (length);
}
