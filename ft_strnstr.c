/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 00:07:53 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 05:20:26 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 *  @brief Locate a substring in a string, searching
 *				only the first 'len' characters
 *
 * @param haystack: The string to be searched
 * @param needle: The substring to search for
 * @param len: The maximum number of characters to search in haystack
 *
 * @return If @needle is empty, returns @haystack
 *    If @needle is found, returns pointer to first occurrence in @haystack
 *    If @needle is not found or search exceeds @len, returns NULL
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while (needle[j] != '\0' && i + j < len
				&& haystack[i + j] == needle[j])
				j++;
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
