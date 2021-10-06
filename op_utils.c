/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:29:07 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/06 10:28:43 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*
** Does operation 'op' 'n' times.
*/
void	op_n(void (*op)(t_data *), int n, t_data *frame)
{
	while (n > 0)
	{
		op(frame);
		n--;
	}
}

/*
** Rotates stack 'n' times. If 'n' is positive, op_ra is used. If 'n' is
** negative, op_rra is used.
*/
void	op_nra(int n, t_data *frame)
{
	if (n > A_STACK.len / 2)
		n -= A_STACK.len;
	if (n > 0)
		op_n(op_ra, n, frame);
	else if (n < 0)
		op_n(op_rra, -n, frame);
}

void	op_nrb(int n, t_data *frame)
{
	if (n > B_STACK.len / 2)
		n -= B_STACK.len;
	if (n > 0)
		op_n(op_rb, n, frame);
	else if (n < 0)
		op_n(op_rrb, -n, frame);
}

void	op_pa_in_num_pos(int num_pos, t_data *frame)
{
	if (num_pos >= -1 && num_pos <= 1)
	{
		op_pa(frame);
		if (num_pos == 1)
			op_sa(frame);
		else if (num_pos == -1)
			op_ra(frame);
	}
	else
	{
		op_nra(num_pos, frame);
		op_pa(frame);
	}
}
