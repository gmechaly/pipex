/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 15:51:47 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/22 18:39:44 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	dst = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (dst == NULL)
		return (NULL);
	while (s1 != NULL && s1[i])
		dst[j++] = s1[i++];
	i = 0;
	while (s2 != NULL && s2[i])
		dst[j++] = s2[i++];
	dst[j] = '\0';
	return (dst);
}

/*#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 3)
		return (0);
	else
		printf("%s", ft_strjoin (argv[1], argv[2]));
	return (0);
}*/