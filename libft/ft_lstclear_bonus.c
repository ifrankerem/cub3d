/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:36:39 by iarslan           #+#    #+#             */
/*   Updated: 2024/10/27 17:33:35 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*erase;
	t_list	*current;

	if (!*lst || !*del || !lst)
		return ;
	current = *lst;
	while (current)
	{
		erase = current;
		current = current->next;
		del(erase->content);
		free(erase);
	}
	*lst = NULL;
}
