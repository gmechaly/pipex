/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 17:30:22 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:19:00 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_isalpha(int character)
{
	if ((character >= 65 && character <= 90) || \
	(character >= 97 && character <= 122))
		return (1024);
	else
		return (0);
}
