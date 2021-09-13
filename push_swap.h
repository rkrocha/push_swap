/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 09:42:35 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/13 15:00:45 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

typedef struct s_data
{
	t_stack	a_stack;
	t_stack	b_stack;
}	t_data;

/*
** op_swap.c:
*/
void	op_sa(t_data *frame);
void	op_sb(t_data *frame);
void	op_ss(t_data *frame);

/*
** op_push.c:
*/
void	op_pa(t_data *frame);
void	op_pb(t_data *frame);

/*
** op_rotate.c:
*/
void	op_ra(t_data *frame);
void	op_rb(t_data *frame);
void	op_rr(t_data *frame);

/*
** op_reverse_rotate.c:
*/
void	op_rra(t_data *frame);
void	op_rrb(t_data *frame);
void	op_rrr(t_data *frame);

#endif
