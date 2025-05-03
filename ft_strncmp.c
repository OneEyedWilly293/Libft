/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:54:12 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 05:18:22 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compares two strings up to n characters
 *
 * This function compares the two strings s1 and s2 lexicographically,
 * but at most n characters are compared. It returns an integer less than,
 * equal to, or greater than zero if s1 is found, respectively, 
 * to be less than, equal to, or greater than s2.
 *
 * @param s1: The first string to compare
 * @param s2: The second string to compare
 * @param n: The maximum number of characters to compare
 *
 * @return An integer less than, equal to, or greater than zero if s1 is found,
 *          respectively, to be less than, equal to, or greater than s2
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - ((unsigned char)s2[i]));
}
