/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgueon <jgueon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 17:38:27 by jgueon            #+#    #+#             */
/*   Updated: 2025/04/20 17:44:26 by jgueon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strjoin(char const *s1, char const *s2)
{
    char    *new_str;
    size_t  s1_len;
    size_t  s2_len;

    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (ft_strdup(s2));
    if (!s2)
        return (ft_strdup(s1));
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
    if (!new_str)
        return (NULL);
    ft_strcpy(new_str, s1);
    ft_strcat(new_str, s2);
    return (new_str);
}
