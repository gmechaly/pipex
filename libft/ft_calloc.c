/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:39:47 by gmechaly          #+#    #+#             */
/*   Updated: 2024/11/22 18:37:54 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*array;

	if (nmemb && size && (size * nmemb) / size != nmemb)
		return (0);
	array = malloc(size * nmemb);
	if (array == NULL)
		return (0);
	ft_bzero(array, size * nmemb);
	return (array);
}

/*int	main(void)
{
	char	*str1;
	char	*str2;

	str1 = (char *)ft_calloc(30, 1);
	str2 = (char *)calloc(30, 1);
	if (!str1)
		write(1, "NULL", 4);
	else
	{
		write(1, str1, 30);
		write(1, "\n", 1);
		write(1, str2, 30);
	}
}
*/