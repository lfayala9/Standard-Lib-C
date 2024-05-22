/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:30:32 by layala-s          #+#    #+#             */
/*   Updated: 2024/04/02 14:30:35 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	counter_char(const char *string, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (string[i] != '\0')
	{
		if (string[i] == c)
			i++;
		else
		{
			count++;
			while (string[i] != '\0' && string[i] != c)
				i++;
		}
	}
	return (count);
}

static char	**cleaner(char **result)
{
	size_t	j;

	j = 0;
	while (result[j] != NULL)
	{
		free(result[j]);
		j++;
	}
	free(result);
	return (0);
}

static char	**filler(char const *s, char c, char **result)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			len = 0;
			while (s[i + len] != '\0' && s[i + len] != c)
				len++;
			result[j] = (char *)malloc(sizeof(char) * (len + 1));
			if (!result[j])
				return (cleaner(result));
			ft_memcpy(result[j], s + i, len);
			result[j][len] = '\0';
			j++;
			i += len;
		}
	}
	return (result[j] = 0, result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = (char **)malloc((counter_char(s, c) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result = filler(s, c, result);
	return (result);
}
