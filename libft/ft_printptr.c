/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 21:15:06 by gmechaly          #+#    #+#             */
/*   Updated: 2024/12/05 16:22:48 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_printhexa(unsigned long long n)
{
	char			*hexabase;
	int				mod;
	int				j;
	static int		i;

	j = i;
	hexabase = "0123456789abcdef";
	mod = n % 16;
	n = n / 16;
	if (n != 0)
		ft_printhexa(n);
	write (1, &hexabase[mod], 1);
	i++;
	return (i - j);
}

int	ft_printptr(void *ptr)
{
	int	i;

	if (ptr == NULL)
	{
		write (1, "(nil)", 5);
		return (5);
	}
	write (1, "0x", 2);
	i = 2 + ft_printhexa((long long)ptr);
	return (i);
}

/*#include <stdio.h>

int	main(void)
{
	long long *test = (long long *)malloc(sizeof(long long) * 5);

	*test = 0;
	printf("%p\n", &test);
	ft_printptr(&test);
	free (test);
	return (0);
}
*/