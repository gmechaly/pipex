/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:18:44 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:22:30 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int	isset(const char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_set_strlen(char *str, char *set)
{
	int	i;
	int	start;

	i = 0;
	while (isset(str[i], set))
		i++;
	start = i;
	while (str[i])
		i++;
	if (i == start)
		return (0);
	while (isset(str[i - 1], set))
		i--;
	return (i - start);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*dst;
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	len = ft_set_strlen((char *)s1, (char *)set);
	dst = (char *)malloc(sizeof(char) * (len + 1));
	if (dst == NULL)
		return (NULL);
	if (len == 0)
	{
		dst[0] = '\0';
		return (dst);
	}
	while (isset(s1[i], set))
		i++;
	while (s1[i])
		dst[j++] = s1[i++];
	while (isset(dst[j - 1], set))
		j--;
	dst[j] = '\0';
	return (dst);
}

/*#include <stdio.h>

int main (void)
{
	printf("%s\n", ft_strtrim(argv[1], argv[2]));
	return (0);
}
*/