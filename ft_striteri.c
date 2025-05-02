/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:12:06 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/02 15:29:21 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies a function to each character of a string with its index
//   @s: The string to iterate over (must be modifiable, not a string literal)
//   @f: The function to apply, which takes the 
//		character's index and a pointer to the character
//
//   Description:
//   This function iterates through the string @s, and for each character,
//   calls the function @f, passing the index of the character and a pointer
//   to the character itself. The function @f can modify the character in place.
//   Iteration stops at the null terminator.
//   If @s or @f is NULL, the function does nothing.
//
//   Return: None (void)

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
