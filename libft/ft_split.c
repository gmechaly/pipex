/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:01:46 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/26 16:36:39 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static size_t	issep(char s, char c)
{
	if (s == c || s == '\0')
		return (1);
	return (0);
}

static char	ft_count_string(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && issep(str[i], c))
		i++;
	while (str[i])
	{
		if (issep(str[i], c) == 0 && issep(str[i + 1], c) == 1)
			count++;
		i++;
	}
	return (count);
}

static char	*ft_strncdup(char const *src, char c)
{
	char	*dest;
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (issep(src[len], c) == 0)
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char	**alloc_fail(char **result, int iword)
{
	int	i;

	i = 0;
	while (i < iword)
	{
		if (result[i])
			free (result[i]);
		i++;
	}
	free (result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		iword;

	i = 0;
	iword = 0;
	result = (char **)malloc(sizeof(char *) * (ft_count_string(s, c) + 1));
	if (result == NULL)
		return (NULL);
	while (s[i])
	{
		if (issep(s[i], c) == 0)
		{
			result[iword] = ft_strncdup(&s[i], c);
			if (result[iword] == NULL)
				return (alloc_fail(result, iword));
			i = i + ft_strlen(result[iword]);
			iword++;
		}
		else
			i++;
	}
	result[iword] = NULL;
	return (result);
}

/*#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	char	**dest;

	i = 0;
	if (argc != 3)
		return (0);
	else
	{
		dest = ft_split(argv[1], argv[2][0]);
		while (dest[i])
		{
			printf("%s\n", dest[i]);
			i++;
		}
		while (i >= 0)
		{
			//free(dest[i]);
			i--;
		}
		free(dest);
	}
	return (0);
}
*/