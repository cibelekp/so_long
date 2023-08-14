/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:36:29 by ckojima-          #+#    #+#             */
/*   Updated: 2022/11/20 20:29:58 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n;

	n = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		n++;
	}
	return (n);
}

/*
Counts the number of nodes in a list.
Returns the length of the list (int).

lst: The beginning of the list.
*/