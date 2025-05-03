/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:39:37 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 04:23:41 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_memmove - Copies n bytes from memory area src to memory area dst.
 * The memory areas may overlap.
 *
 * Description:
 * This function copies n bytes from memory area src to memory area dst.
 * Unlike memcpy, memmove handles overlapping memory regions correctly.
 * If src and dst overlap, the copy is done in a non-destructive manner.
 * The function first checks if the memory areas overlap and determines
 * the direction of copying to avoid data corruption.
 *
 * @param dst: Pointer to the destination memory area
 * @param src: Pointer to the source memory area
 * @param n: Number of bytes to copy
 *
 * @returns The original value of dst
 */
void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		d += n - 1;
		s += n - 1;
		while (n--)
			*d-- = *s--;
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dst);
}
