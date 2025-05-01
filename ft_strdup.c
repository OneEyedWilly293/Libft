/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 15:02:20 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/01 22:22:53 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * ft_strdup - Duplicates a string
 * @s: The string to duplicate
 *
 * Description: This function allocates memory for a new string which is
 * a duplicate of the string s. Memory for the new string is obtained with
 * malloc, and can be freed with free.
 *
 * Return: A pointer to the duplicated string, or NULL if insufficient memory
 * was available
 */

char	*ft_strdup(const char *s1)
{
	char	*dup;
	int		len;
	int		i;

	len = 0;
	while (s1[len])
		len++;
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
