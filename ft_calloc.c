/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:17:48 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/02 17:46:52 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_calloc - Allocates memory for an array and initializes it to zero.
 *
 * @count: Number of elements to allocate.
 * @size: Size of each element in bytes.
 *
 * Return: Pointer to the allocated memory, or NULL if allocation fails.
 *
 * Description:
 * This function allocates memory for an array of 'count' elements,
 * each of 'size' bytes, and initializes all bytes in the allocated
 * memory to zero. It replicates the behavior of the standard C library
 * function calloc. If either 'count' or 'size' is zero, the function
 * returns a pointer that can safely be passed to free(). If the memory
 * allocation fails, it returns NULL.
 */

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;
	size_t	i;

	if (nmemb != 0 && size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
