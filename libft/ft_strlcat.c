/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 16:22:30 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:22:11 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	result;

	i = ft_strlen((char *)dst);
	j = ft_strlen((char *)src);
	if (dstsize <= i)
		return (dstsize + j);
	result = i + j;
	j = 0;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (result);
}

/*#include <stdio.h>
int	main(int argc, char **argv)
{
	char *dst;
	//size_t dstsize;
	
	if (argc != 3)
		return (0);
	dst = argv[1];
	//dstsize = ft_strlen(dst) + ft_strlen(argv[2]);
	const char *src = argv[2];
	printf("%d\n%s\n", (int) ft_strlcat(dst, src, 13), dst);
	return (0);
}
*/