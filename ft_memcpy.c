/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:53:31 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 04:22:47 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memcpy - Copies n bytes from memory area src to memory area dest
 *
 * This function copies n bytes from memory area src to memory area dest.
 * The memory areas must not overlap. For overlapping memory blocks, 
 * use ft_memmove instead.
 *
 * @param dest  Pointer to the destination array where content will be copied
 * @param src   Pointer to the source of data to be copied
 * @param n     Number of bytes to copy
 * @return      A pointer to dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
