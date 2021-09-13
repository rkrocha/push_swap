/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:44:35 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/13 15:36:39 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	op_reverse_rotate(t_stack *stack)
{
	t_dlist	*popped;

	if (stack->len < 2)
		return ;
	popped = stack->bottom;
	stack->bottom = popped->prev;
	stack->bottom->next = NULL;
	stack_push(stack, popped);
	(stack->len)--;
}

void	op_rra(t_data *frame)
{
	op_reverse_rotate(&frame->a_stack);
	ft_putendl("rra");
}

void	op_rrb(t_data *frame)
{
	op_reverse_rotate(&frame->b_stack);
	ft_putendl("rrb");
}

void	op_rrr(t_data *frame)
{
	op_reverse_rotate(&frame->a_stack);
	op_reverse_rotate(&frame->b_stack);
	ft_putendl("rrr");
}
