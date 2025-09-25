/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 22:30:40 by codespace         #+#    #+#             */
/*   Updated: 2025/09/25 15:32:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
ft_strlen:
Counts the length os the strings 's' (excluding the null terminator).
Returns the number of characters.
*/
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*
ft_strchr:
Searches for the first occurrence of the character 'c' in the string 's'.
Returns a pointer to the character if found, or NULL otherwise.
*/
char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = 0;
	uc = (unsigned char)c;
	while (s[i] != '\0')
	{
		if (s[i] == uc)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if (uc == '\0')
	{
		return ((char *)&s[i]);
	}
	return (NULL);
}

/*
ft_strdup:
Allocates sufficient memory and creates a copy of the string 's1'.
Rturns a pointer to the newly allocated string, or NULL if allocation fails.
*/
char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	dup = (char *)malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*
ft_strjoin:
Concatenates 's1' and 's2' into a new string.
Allocates memory for the result and returns it.
Returns NULL if allocations fails.
*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

/*
ft_strlcpy:
Copies up to (size - 1) characters from the string 'origin' to 'dest', 
ensuring the result is null-terminated. Returns the length of 'origin'. 
This function helps prevent buffer overflows during string copy operations.
*/
size_t	ft_strlcpy(char *dest, const char *origin, size_t size)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (size > 0)
	{
		while (i < size - 1 && origin[i] != '\0')
		{
			dest[i] = origin[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (origin[count] != '\0')
		count++;
	return (count);
}
