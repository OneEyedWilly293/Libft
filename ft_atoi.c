/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:09:29 by jgueon            #+#    #+#             */
/*   Updated: 2025/05/03 03:40:25 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This function converts the initial portion of the string pointed to by str
 * to an integer representation. It skips all white-space characters at the
 * beginning, takes an optional plus or minus sign followed by as many digits
 * as possible, and interprets them as a numerical value.
 * ft_atoi - Converts a string to an integer
 *
 * @param str: The string to be converted
 * @return The converted integer value
 */
int	ft_atoi(const char *str)
{
	int		sign;
	int		result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
