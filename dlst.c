/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:30:04 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/07 15:58:01 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "stack.h"

t_dlist	*dlst_new(int content)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	dlst_add_front(t_dlist **lst, t_dlist *new)
{
	new->next = *lst;
	new->prev = NULL;
	(*lst)->prev = new;
	*lst = new;
}

void	dlst_clear(t_dlist **lst)
{
	t_list	*temp;
	t_list	*tracker;

	if (!lst)
		return ;
	tracker = *lst;
	while (tracker != NULL)
	{
		temp = tracker->next;
		free(tracker);
		tracker = temp;
	}
	*lst = NULL;
}
