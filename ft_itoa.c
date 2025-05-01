/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:47:47 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/01 22:40:10 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * ft_numlen - Calculate the number of digits in an integer
 * @n: The integer to calculate length for
 *
 * This helper function determines how many characters we need
 * to allocate for our string (including the sign for negatives).
 *
 * Return: The number of digits (plus sign if negative)
 */

static size_t	ft_numlen(int n)
{
	size_t	len;
	long	num;

	len = 0;
	num = n;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	num;
	int		is_neg;

	len = ft_numlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	is_neg = (n < 0);
	num = n;
	if (is_neg)
		num *= -1;
	if (n == 0)
		str[0] = '0';
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (is_neg)
		str[0] = '-';
	return (str);
}
