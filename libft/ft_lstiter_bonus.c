/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:13:13 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:21:19 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL || (*f) == NULL)
		return ;
	while (lst != NULL)
	{
		(*f)(lst->content);
		if (lst->next != NULL)
			lst = lst->next;
		else
			return ;
	}
}
