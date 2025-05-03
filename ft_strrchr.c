/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:07:13 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 05:21:40 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locates the last occurrence of character 'c' in the string 's'
 *
 * This function searches for the last occurrence of the character 'c'
 * (converted to a char) in the string pointed to by 's'. The terminating
 * null character is considered part of the string, so if 'c' is '\0',
 * the function returns a pointer to the null terminator of 's'.
 *
 * @param s - The string to search in
 * @param c - The character to search for
 *
 * @return
 * A pointer to the last occurrence of the character 'c' in the string 's',
 * or NULL if the character is not found.
 */
char	*ft_strrchr(const char *s, int c)
{
	const char	*last_occurrence;
	char		ch;
	int			i;

	last_occurrence = NULL;
	ch = (char)c;
	i = 0;
	while (s[i])
		i++;
	if (ch == '\0')
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
