/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:58:55 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:21:35 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*uchar_s1;
	unsigned char	*uchar_s2;

	i = 0;
	if (n == 0)
		return (0);
	uchar_s1 = (unsigned char *) s1;
	uchar_s2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (uchar_s1[i] == uchar_s2[i] && i < n - 1)
		i++;
	return (uchar_s1[i] - uchar_s2[i]);
}

/*#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	int	i;

	i = memcmp((const void *)argv[1], (const void *)argv[2], 8);
	if (argc != 3)
		return (0);
	else
	{
		printf("%d, %d", ft_memcmp((const void *)argv[1], \
		(const void *)argv[2], 8), i);
		return (0);
	}
}
*/