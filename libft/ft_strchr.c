/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:26:53 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:22:00 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	a;
	size_t	i;

	a = c;
	i = 0;
	while (s[i] && s[i] != a)
		i++;
	if (a != '\0' && i == ft_strlen(s))
		return (NULL);
	else
		return ((char *)&s[i]);
}

/*#include <stdio.h>

int main(void)
{
	printf("%s", ft_strchr("sap=rlip0pette", '\0'));
	return (0);
}
*/