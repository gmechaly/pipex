/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 20:07:04 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:22:34 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*new_str;

	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	while (s[start + i] && i < len)
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/*#include <stdio.h>

int	main(void)//int argc, char **argv)
{
	/___*unsigned int	start;
	size_t			len;

	if (argc != 4)
		return (0);
	start = (unsigned int) ft_atoi(argv[2]);
	len = (size_t) ft_atoi(argv[3]);*___/
	printf("%s\n", ft_substr("hola", 0, 18446744073709551615));
	//argv[1], start, len);
	return (0);
}
*/