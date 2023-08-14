/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:33:38 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/21 14:41:10 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

/*
Takes as a parameter a node and frees the memory of
the node’s content using the function ’del’ given
as a parameter and free the node. The memory of
’next’ must not be freed.

lst: The node to free.
del: The address of the function used to delete
the content.
*/