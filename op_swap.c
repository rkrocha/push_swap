/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 09:23:35 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/17 16:16:46 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	op_swap(t_stack *stack)
{
	t_dlist	*popped;

	if (stack->len < 2)
		return ;
	popped = stack->top->next;
	stack->top->next = popped->next;
	popped->next->prev = popped->prev;
	stack_push(stack, popped);
	(stack->len)--;
}

void	op_sa(t_data *frame)
{
	op_swap(&frame->a_stack);
	ft_putendl("sa");
}

void	op_sb(t_data *frame)
{
	op_swap(&frame->b_stack);
	ft_putendl("sb");
}

void	op_ss(t_data *frame)
{
	op_swap(&frame->a_stack);
	op_swap(&frame->b_stack);
	ft_putendl("ss");
}
