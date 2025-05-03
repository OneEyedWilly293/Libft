/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 14:49:36 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 17:09:35 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates and returns a copy of 's1' with characters
 * specified in 'set' removed from the beginning and end of the string.
 *
 * This function creates a new string by trimming all characters found in 'set'
 * from the beginning and end of string 's1'. The trimming continues until a
 * character not in 'set' is found. Characters in the middle of the string
 * are not affected, even if they appear in 'set'.
 *
 * @param s1: The string to be trimmed
 * @param set: The reference set of characters to trim
 *
 * @return
 *   The trimmed string with new memory allocation
 *   NULL if the allocation fails or if 's1' is NULL
 *   A duplicate of 's1' if 'set' is NULL
 *
 * @note Memory:
 *   The returned string is allocated with malloc() and must be freed by
 * 		the caller
 *
 * @note Edge cases:
 *   - If all characters in 's1' are in 'set', returns an empty string
 *   - If 'set' is empty, returns a duplicate of 's1'
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, start, end - start));
}
