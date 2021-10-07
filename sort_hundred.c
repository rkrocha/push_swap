/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:01:29 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/07 16:35:22 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static int	ft_abs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

static int	abs_smallest(int pos_one, int pos_two)
{
	if (ft_abs(pos_one) < ft_abs(pos_two))
		return (pos_one);
	return (pos_two);
}

void	sort_hundred(t_data *frame)
{
	int	pos[2];

	while (A_STACK.len > 0)
	{
		pos[0] = peek_smallest_num(&A_STACK, false);
		if (pos[0] > A_STACK.len / 2)
			pos[0] -= A_STACK.len;
		pos[1] = peek_largest_num(&A_STACK, false);
		if (pos[1] > A_STACK.len / 2)
			pos[1] -= A_STACK.len;
		op_nra(abs_smallest(pos[0], pos[1]), frame);
		op_pb(frame);
		if (B_STACK.len > 1 && pos[1] == abs_smallest(pos[0], pos[1]))
			op_rb(frame);
	}
	while (B_STACK.len > 0)
		op_pa(frame);
	op_nra(peek_smallest_num(&A_STACK, false), frame);
}
