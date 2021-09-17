/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:22:45 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/17 16:37:57 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_two(t_data *frame)
{
	op_sa(frame);
}

void	sort_three(t_data *frame)
{
	if (content(A_STACK.top) > content(A_STACK.top->next))
		op_sa(frame);
	if (content(A_STACK.bottom) < content(A_STACK.bottom->prev)
		|| content(A_STACK.top) > content(A_STACK.bottom))
		op_rra(frame);
	if (content(A_STACK.top) > content(A_STACK.top->next))
		op_sa(frame);
}

void	sort_small(t_data *frame)
{
	if (A_STACK.len == 2)
		sort_two(frame);
	else if (A_STACK.len == 3)
		sort_three(frame);
}
