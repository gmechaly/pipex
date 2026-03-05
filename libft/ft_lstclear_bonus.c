/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:03:24 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:21:15 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		size;
	t_list	*temp;

	temp = *lst;
	size = ft_lstsize(*lst);
	while (size--)
	{
		(*del)(temp->content);
		temp = temp->next;
		free(*lst);
		*lst = temp;
	}
	lst = NULL;
}
