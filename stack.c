/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 09:57:57 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/09 13:49:23 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

void	stack_push(t_stack *stack, t_dlist *new)
{
	if (!new)
		return ;
	if (stack->len == 0)
		stack->bottom = new;
	dlst_add_front(&(stack->top), new);
	(stack->len)++;
}

t_dlist	*stack_pop(t_stack *stack)
{
	t_dlist	*popped;

	if (stack->len == 0)
		return (NULL);
	popped = stack->top;
	if (stack->len == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
	}
	else
	{
		stack->top = popped->next;
		stack->top->prev = NULL;
	}
	(stack->len)--;
	popped->next = NULL;
	popped->prev = NULL;
	return (popped);
}

void	stack_clear(t_stack *stack)
{
	if (!stack)
		return ;
	dlst_clear(&(stack->top));
	stack->len = 0;
	stack->bottom = NULL;
}

void	stack_print(t_stack *stack, char *title)
{
	t_dlist	*lst;

	if (!stack)
		return ;
	if (title)
		ft_putendl(title);
	ft_putendl("-----");
	lst = stack->top;
	while (lst)
	{
		ft_putnbr(lst->content);
		ft_putchar('\n');
		lst = lst->next;
	}
	ft_putstr("-----\nstack len = ");
	ft_putnbr(stack->len);
	ft_putchar('\n');
	ft_putendl("end of stack\n");
}
