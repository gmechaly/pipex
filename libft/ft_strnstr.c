/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 17:06:42 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:22:24 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	lil_len;

	i = 0;
	lil_len = (size_t) ft_strlen((char *)little);
	if (lil_len == 0)
		return ((char *) big);
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && \
		i + j < len && big[i + j] && little[j])
			j++;
		if (j == lil_len)
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	else
		printf("%s\n", ft_strnstr(argv[1], argv[2], 14));
	return (0);
}
*/