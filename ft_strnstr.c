/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:15:48 by layala-s          #+#    #+#             */
/*   Updated: 2024/03/25 15:26:12 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *great, char *find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*temp;

	i = 0;
	if (find[0] == '\0')
	{
		return ((char *)great);
	}
	while (great[i] && i < len)
	{
		temp = great + i;
		j = 0;
		while (temp[j] == find[j] && temp[j] != '\0' && (i + j) < len)
		{
			j++;
		}
		if (find[j] == '\0')
		{
			return (temp);
		}
		i++;
	}
	return (NULL);
}
