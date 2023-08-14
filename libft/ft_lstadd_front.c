/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:25:23 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/20 19:46:24 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new || !lst)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
Adds the node ’new’ at the beginning of an existing list.

lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.
*/