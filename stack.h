/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:57:33 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/07 16:24:31 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

typedef struct s_dlist
{
	int		content;
	t_dlist	*next;
	t_dlist	*prev;
}	t_dlist;

typedef struct s_stack
{
	size_t	len;
	t_dlist	*top;
	t_dlist	*bottom;
}	t_stack;

/*
** dlst.c:
*/
t_dlist	*dlst_new(int content);
void	dlst_add_front(t_dlist **lst, t_dlist *new);
void	dlst_clear(t_dlist **lst);

#endif
