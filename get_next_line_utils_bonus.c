/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherbet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:28:16 by aherbet           #+#    #+#             */
/*   Updated: 2022/12/23 03:43:24 by aherbet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*cs;
	size_t	size_m;
	char	*copy;
	size_t	i;

	cs = (char *)s;
	size_m = ft_strlen(s);
	copy = (char *)malloc(((size_m +1) * sizeof(char)));
	if (copy == NULL)
		return (NULL);
	if (copy != NULL)
	{
		i = 0;
		while (cs[i])
		{
			copy[i] = cs[i];
			i++;
		}
		copy[i] = '\0';
	}
	return (copy);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*joint;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	joint = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (joint == NULL)
		return (NULL);
	while (s1[i])
	{
		joint[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		joint[i + j] = s2[j];
		j++;
	}
	joint[i + j] = '\0';
	free(s1);
	return (joint);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*cs;

	i = 0;
	cs = (char *)s;
	if (c == 0)
		return (cs + ft_strlen(s));
	while (cs[i] && c != 0)
	{
		if (cs[i] == (unsigned char)c)
			return (cs + i);
		i++;
	}
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*cs;
	char	*dest;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	cs = (char *)s;
	dest = malloc((len * sizeof(char)) + 1);
	if (dest == NULL)
		return (NULL);
	if (dest != NULL)
	{
		while (i < len && cs[i] != '\0')
		{
			dest[i] = cs[i + start];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
