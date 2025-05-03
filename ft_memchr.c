/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:35:20 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 04:12:47 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memchr - Searches for the first occurrence of a byte in a memory area
 *
 * Description:
 * This function scans the first 'n' bytes of the memory area pointed to by 's'
 * for the first occurrence of the byte 'c'. Both 'c' and the bytes of the
 * memory area are interpreted as unsigned char.
 *
 * @param s - Pointer to the memory area to be searched
 * @param c - The byte to search for (interpreted as an unsigned char)
 * @param n - Number of bytes to search
 *
 * @return
 * 	- A pointer to the matching byte if found.
 * @return
 *	- NULL if the byte doesn't occur in the given memory area
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			i;

	ptr = (unsigned char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == ch)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
