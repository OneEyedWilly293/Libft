/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:55:26 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 18:08:40 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy string to a specific size
 *
 * This function copies up to size-1 characters from the NUL-terminated
 * string src to dst, NUL-terminating the result.
 *
 * @param dst - Destination string buffer
 * @param src - Source string to copy from
 * @param size - Size of the destination buffer
 *
 * @return
 * The total length of the string it tried to create (length of src)
 * If size is 0, src is not accessed and dst is not modified
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
