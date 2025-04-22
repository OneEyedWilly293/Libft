/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:42:03 by jgueon            #+#    #+#             */
/*   Updated: 2025/04/22 16:10:34 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s1[i] && s[i] == c)
		i++;
	while (s[i])
	{
		count++;
		while (s1[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
	}
	return (count);
}

static int	word_length(char const *s, char c, int start)
{
	int len;

	len = 0;
	while (s[start + len] && s[start + len] != c)
		len++;
	return (len);
}

static char	*create_word(char const	*s, char c, int *start)
{
	int	len;
	char	*word;
	int	i;

	while (s[*start] && s[*start] == c)
		(*start)++;
	len = word_length(s, c, *start);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[*start + i];
		i++;
	}
	word[i] = '\0';
}

static void	free-array(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char **ft_split(char const *s, char c)
{
	char	**result;
	int	word_count;
	int	i;
	int start;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	start = 0;
	while (i < word_count)
	{
		result[i] = create_word(s, c, &start);
		if (!result)
		{
			free_array(result, i);
			return (NULL);
		}
		i++;
	}
	result[word_count] = NULL;
	return (result);
}
