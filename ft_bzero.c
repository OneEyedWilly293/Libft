/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:47:47 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 00:37:37 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_bzero - This function writes n zeroed bytes to the string s.
 * If n is zero, ft_bzero does nothing.
 *
 * The function doesn't return any value (void)
 *
 * @param s: A pointer to the memory area to be filled with zeros
 * @param n: The number of bytes to be set to zero
 */
void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
