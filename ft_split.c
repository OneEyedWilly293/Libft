/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:42:03 by jgueon            #+#    #+#             */
/*   Updated: 2025/04/17 18:12:49 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_delim(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int	count_words(char *str)
{
	int	count;
	int in_word;

	count = 0;
	in_word = 1;
	while(*str)
	{
		if(!is_delim(*str) && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if(is_delim(*str))
		{
			in_word = 0;
		}
		str++;
	}
	return (count);
}

char *get_word(char *str)
{
	char	*word;
	int	i;
	int len;

	len = 0;
	while(str[len] && !is_delim(str[len]))
	{
		len++;
	}
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while(i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char **ft_split(char *str)
{
	int count;
	int	i;
	int	index;
	char **result;

	count = word_count(str);
	result = (char **)malloc((count + 1) * sizeof(char *));
	if(!result)
		return (NULL);
	index = 0;
	while(*str)
	{
		while (is_delim(*str))
			str++;

		if(*str)
		{
			result[index] = get_word(str);
			if(!result[index])
			{
				i = 0;
				while(i < index)
				{
					free(result[i]);
					i++;
				}
				free(result);
				return (NULL);
			}
			index++;
			while(*str && !is_delim(*str))
				str++;
		}
	}
	result[index] = NULL;
	return (result);
}
