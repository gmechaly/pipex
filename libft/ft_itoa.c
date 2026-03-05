/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 18:55:50 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:21:09 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	ft_count_size(int nbr)
{
	int	count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		count++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

static char	ft_negnb(long int *n)
{
	*n = -*n;
	return ('-');
}

char	*ft_itoa(int n)
{
	char		*result;
	int			size;
	long int	nbr;

	size = ft_count_size(n);
	nbr = n;
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	if (nbr == 0)
		result[0] = '0';
	else if (nbr < 0)
		result[0] = ft_negnb(&nbr);
	result[size] = '\0';
	while (nbr != 0)
	{
		result[size - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		size--;
	}
	return (result);
}

/*#include <stdio.h>

int main (void)
{
	printf("%s", ft_itoa(-2147483648));
	return (0);
}
*/