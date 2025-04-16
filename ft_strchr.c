/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 20:13:33 by jgueon            #+#    #+#             */
/*   Updated: 2025/04/16 20:15:15 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strchr(const char *s, int c)
{
	int		i;
	char	*temp;

	temp = (char *)s;
	i = ft_strlen(temp);
	temp += i;
	while (i >= 0)
	{
		if (*temp == (char)c)
			return (temp);
		temp--;
		i--;
	}
	return (NULL);
}
