/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:13:33 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/01 22:46:22 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
** ft_strchr - locates the first occurrence of a character in a string
**
** Description:
** This function searches for the first occurrence of the character 'c'
** (converted to a char) in the string pointed to by 's'. The terminating
** null byte is considered part of the string, so if 'c' is '\0', the function
** locates the terminating '\0'.
**
** Parameters:
** s - The string to be scanned
** c - The character to be located
**
** Return:
** A pointer to the first occurrence of the character c in the string s,
** or NULL if the character is not found.
*/

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
