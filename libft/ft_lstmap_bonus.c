/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmechaly <gmechaly@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:19:36 by gmechaly          #+#    #+#             */
/*   Updated: 2024/10/30 21:21:25 by gmechaly         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_element;
	void	*temp;

	new_lst = NULL;
	if (lst == NULL || (*f) == NULL || (*del) == NULL)
		return (NULL);
	while (lst)
	{
		temp = (*f)(lst->content);
		new_element = ft_lstnew(temp);
		if (new_element == NULL)
		{
			(*del)(temp);
			ft_lstclear(&new_lst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_element);
		lst = lst->next;
	}
	return (new_lst);
}
