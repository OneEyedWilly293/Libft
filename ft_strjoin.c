/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:38:27 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 05:10:29 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates and returns a new string which is the result of concatenating
 * the prefix string 's1' and the suffix string 's2'.
 *
 * @param s1: The prefix string (first string to concatenate)
 * @param s2: The suffix string (second string to concatenate)
 *
 * @returns
 *   A newly allocated string containing the concatenation of s1 and s2
 *   NULL if the memory allocation fails
 *
 * @note
 * The caller is responsible for freeing the memory allocated by this function
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!result)
		return (NULL);
	ft_memcpy(result, s1, len1);
	ft_memcpy(result + len1, s2, len2 + 1);
	return (result);
}
