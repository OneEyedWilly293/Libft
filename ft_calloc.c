/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 01:17:48 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/01 22:22:24 by jgueon           ###   ########.fr       */
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
	void	*array;

	array = malloc(nmemb * size);
	if (array == NULL)
		return (NULL);
	ft_bzero(array, (nmemb * size));
	return (array);
}
