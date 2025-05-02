/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:41:24 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/02 15:25:48 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_memcpy compares two blocks of memory byte by byte.
//    @ A pointer to the first memory block (str1)
//    @ A pointer to the second memory block (str2)
//    @ The number of bytes to compare (n)
//  memcmp will compare the first 'n' bytes of the
// 		memory areas pointed to by s1 and s2.
//  It compares each byte as an unsigned value.
//  Return value:
//   - Returns 0 if all n bytes are equal.
//   - Returns a negative value if the first byte that
//      differs in s1 is less than the corresponding byte in s2.
//   - Returns a positive value if the first byte that differs
//      in s1 is greater than the corresponding byte in s2.
//  memcmp does not stop at a null byte ('\0');
//    it always compares exactly n bytes.
//

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;
	size_t				i;

	s1 = (const unsigned char *)str1;
	s2 = (const unsigned char *)str2;
	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
