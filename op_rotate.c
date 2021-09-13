/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 13:59:42 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/13 15:36:30 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	op_rotate(t_stack *stack)
{
	t_dlist	*popped;

	if (stack->len < 2)
		return ;
	popped = stack_pop(stack);
	(stack->len)++;
	popped->prev = stack->bottom;
	stack->bottom->next = popped;
	stack->bottom = popped;
}

void	op_ra(t_data *frame)
{
	op_rotate(&frame->a_stack);
	ft_putendl("ra");
}

void	op_rb(t_data *frame)
{
	op_rotate(&frame->b_stack);
	ft_putendl("rb");
}

void	op_rr(t_data *frame)
{
	op_rotate(&frame->a_stack);
	op_rotate(&frame->b_stack);
	ft_putendl("rr");
}
