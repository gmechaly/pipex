/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:18:24 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:22:21 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*#include<stdio.h>
#include<string.h>
int     main(void)
{
        char s1[] = "Test1";
        char s2[] = "OK";
        char s3[] = "Same";
        char s4[] = "Size";
        char s5[] = "Shorter";
        char s6[] = "ThanMyself";
        char s7[] = "ShorterTest";

        printf("%d, %d\n", ft_strncmp(s1, s2, 4), strncmp(s1, s2, 4));
        printf("%d, %d\n", ft_strncmp(s1, s2, 2), strncmp(s1, s2, 2));
        printf("%d, %d\n", ft_strncmp(s3, s4, 4), strncmp(s3, s4, 4));
        printf("%d, %d\n", ft_strncmp(s3, s4, 1), strncmp(s3, s4, 1));
        printf("%d, %d\n", ft_strncmp(s5, s6, 3), strncmp(s5, s6, 3));
        printf("%d, %d\n", ft_strncmp(s5, s5, 10), strncmp(s5, s5, 10));
        printf("%d, %d\n", ft_strncmp(s5, s5, 5), strncmp(s5, s5, 5));
        printf("%d, %d\n", ft_strncmp(s5, s7, 7), strncmp(s5, s7, 7));
        printf("%d, %d\n", ft_strncmp(s5, s7, 8), strncmp(s5, s7, 8));
        return (0);
}*/