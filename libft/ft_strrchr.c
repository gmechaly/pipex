/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:59:48 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:22:28 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	int		i;

	a = c;
	i = ft_strlen((char *)s);
	while (i >= 0 && s[i] != a)
		i--;
	if (a != '\0' && i == -1)
		return (NULL);
	else
		return ((char *)&s[i]);
}

/*#include <stdio.h>

int main(void)
{
	printf("%s", ft_strrchr("teste", 'x'));
	return (0);
}
*/