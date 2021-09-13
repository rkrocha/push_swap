/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 09:46:59 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/13 15:35:39 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	op_pa(t_data *frame)
{
	stack_push(&frame->a_stack, stack_pop(&frame->b_stack));
	ft_putendl("pa");
}

void	op_pb(t_data *frame)
{
	stack_push(&frame->b_stack, stack_pop(&frame->a_stack));
	ft_putendl("pb");
}
