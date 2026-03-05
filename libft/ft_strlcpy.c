/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:53:23 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:22:14 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static void	ft_strfill1(char *src, char *dst, size_t i)
{
	dst[i % 10] = src[i];
}

static void	ft_strfill2(char *src, char *dst, size_t i)
{
	dst[i] = src[i % 10];
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	temp[10];
	char	*char_src;

	i = 0;
	j = 0;
	char_src = (char *) src;
	if (size == 0)
		return (ft_strlen((char *)src));
	while (char_src[i] && i < size - 1)
	{
		while (i % 10 < 9 && i < size - 1 && char_src[i])
			ft_strfill1(char_src, temp, i++);
		if (i < size - 1 && char_src[i])
			ft_strfill1(char_src, temp, i++);
		while (j % 10 < 9 && j < size - 1 && char_src[j])
			ft_strfill2(temp, dst, j++);
		if (j < size - 1 && char_src[j])
			ft_strfill2(temp, dst, j++);
	}
	dst[i] = '\0';
	return (ft_strlen((char *)src));
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	dest[2254];

	printf("%d\n", (int) ft_strlcpy(dest, "lorem ipsum dolor sit amet", 15));
	write(1, dest, 15);
	return (0);
}
*/