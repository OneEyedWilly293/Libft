/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:39:06 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/01 22:07:20 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
 * ft_memset - fills memory with a constant byte
 * 
 * This function fills the first 'n' bytes of the memory area
 * pointed to by 's' with the constant byte 'c'.
 *
 * @s: pointer to the memory area to be filled
 * @c: the constant byte to fill the memory with
 * @n: number of bytes to fill
 *
 * Return: a pointer to the memory area 's'
 */

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
