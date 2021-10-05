/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 14:57:33 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/05 09:49:46 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct s_stack
{
	int		len;
	t_dlist	*top;
	t_dlist	*bottom;
}	t_stack;

/*
** dlst.c:
*/
t_dlist	*dlst_new(int content);
void	dlst_add_front(t_dlist **lst, t_dlist *new);
void	dlst_clear(t_dlist **lst);
void	dlst_iter(t_dlist *lst, void (*f)(int));

/*
** stack.c:
*/
void	stack_push(t_stack *stack, t_dlist *new);
t_dlist	*stack_pop(t_stack *stack);
bool	stack_issorted(t_stack *stack);
void	stack_print(t_stack *stack, char *title);
void	stack_clear(t_stack *stack);

#endif
