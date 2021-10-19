/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/12 09:42:35 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/15 10:53:52 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define A_STACK	frame->a_stack
# define B_STACK	frame->b_stack

# include "stack.h"

/*
** max_chunks: maximum number of chunks
** iter_chunks: chunk iterator
** chunk_size: max len of chunks for this sort
** chunk_array: contains all integers pertaining to this chunk
** chunk_len: the amount of integers inside chunk_array
** largest_num: the largest integer in any stack or chunk
** sources: [0] is its value, [1] is its position in a_stack
** destin: the position where a source must be placed in b_stack
** setup_actions: ops needed to set up a pb. [0] is rr, [1] is ra, [2] is rb
*/
typedef struct s_data
{
	t_stack	a_stack;
	t_stack	b_stack;
	int		lis;
	int		lds;
	int		max_chunks;
	int		iter_chunks;
	int		chunk_size;
	int		chunk_array[45];
	int		chunk_len;
	int		largest_num;
	int		source_top[2];
	int		destin_top[2];
	int		source_bot[2];
	int		destin_bot[2];
	int		setup_actions[3];
}	t_data;

/*
** sort_small.c:
*/
void	sort_small(t_data *frame);

/*
** sort_large.c:
*/
void	sort_large(t_data *frame);

/*
** chunks.c:
*/
int		def_chunk_array(t_data *frame);
void	def_chunks_params(t_data *frame);

/*
** chunks_utils.c:
*/
void	peek_sources(t_data *frame);
void	peek_destination(int source_num, int *destin, t_data *frame);

/*
** parse_args.c:
*/
void	parse_args(t_data *frame, int argc, const char **argv);

/*
** peek_utils.c:
*/
int		peek_num_position(t_stack *stack, int num);
int		peek_smallest_num(t_stack *stack, bool return_num);
int		peek_largest_num(t_stack *stack, bool return_num);
void	peek_lis(t_stack *stack, t_data *frame);
void	peek_lds(t_stack *stack, t_data *frame);

/*
** op_utils.c:
*/
void	op_n(void (*op)(t_data *), int n, t_data *frame);
void	op_nra(int n, t_data *frame);
void	op_nrb(int n, t_data *frame);
void	op_nrr(int n, t_data *frame);
void	op_pa_in_num_pos(int num_pos, t_data *frame);

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

/*
** utils.c:
*/
void	free_stacks(t_data *frame);
void	error_exit(t_data *frame);
int		value(t_dlist *elem);

#endif
