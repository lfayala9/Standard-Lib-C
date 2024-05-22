/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: layala-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 13:41:44 by layala-s          #+#    #+#             */
/*   Updated: 2024/04/04 13:41:49 by layala-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	counter_num(long num)
{
	int	count;

	if (num == 0)
		return (1);
	count = 0;
	if (num < 0)
	{
		count = 1;
		num *= -1;
	}
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	len;
	long	temp;
	char	*result;

	len = counter_num(n);
	temp = n;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (NULL);
	if (n < 0)
		temp *= -1;
	result[len] = '\0';
	if (temp == 0)
		result[0] = '0';
	else
	{
		while (len--, temp != 0)
		{
			result[len] = '0' + (temp % 10);
			temp /= 10;
		}
		if (n < 0)
			result[len] = '-';
	}
	return (result);
}
