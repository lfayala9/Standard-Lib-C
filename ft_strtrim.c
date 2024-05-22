/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 11:33:57 by layala-s          #+#    #+#             */
/*   Updated: 2024/05/22 14:30:18 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*new_str;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	if (set == NULL)
		return (ft_strdup(s1));
	while (ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[end]) && end > start)
		end--;
	if (end < start)
		return (ft_strdup(""));
	len = (end - start) + 1;
	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_memcpy(new_str, &s1[start], len);
	new_str[len] = '\0';
	return (new_str);
}
