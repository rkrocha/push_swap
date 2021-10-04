/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 09:29:07 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/20 11:08:55 by rkochhan         ###   ########.fr       */
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
	if (n > 0)
		op_n(op_ra, n, frame);
	else if (n < 0)
		op_n(op_rra, -n, frame);
}

void	op_nrb(int n, t_data *frame)
{
	if (n > 0)
		op_n(op_rb, n, frame);
	else if (n < 0)
		op_n(op_rrb, -n, frame);
}
