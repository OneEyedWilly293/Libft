/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 19:49:21 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/01 22:45:58 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_strlcat - concatenates strings with size limitation
 * @dst: destination string buffer
 * @src: source string to append
 * @size: size of the destination buffer
 *
 * This function appends the null-terminated string src to the end of dst.
 * It will append at most size - strlen(dst) - 1 bytes, and then null-terminate.
 * 
 * Return: The total length of the string it tried to create
 *         (initial length of dst plus length of src)
 */

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	src_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	while (src[src_len])
		src_len++;
	if (dst_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] && (dst_len + i) < (size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
