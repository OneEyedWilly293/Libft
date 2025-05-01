/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:16:11 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/01 22:41:21 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_substr - Extracts a substring from a string
 * @s: The source string from which to create the substring
 * @start: The starting index of the substring in the string 's'
 * @len: The maximum length of the substring
 *
 * This function allocates memory and returns a substring from the string 's'.
 * The substring begins at index 'start' and is of maximum size 'len'.
 * If 'start' is greater than the length of 's', an empty string is returned.
 * If 's' is NULL, NULL is returned.
 *
 * Return: The substring, or NULL if memory allocation fails
 */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && start + i < s_len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
