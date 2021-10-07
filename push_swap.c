/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 08:10:25 by rkochhan          #+#    #+#             */
/*   Updated: 2021/10/07 11:42:33 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	sort_stack(t_data *frame)
{
	if (A_STACK.len == 1 || stack_issorted(&A_STACK) == true)
		return ;
	if (A_STACK.len <= 5)
		sort_small(frame);
	// else if (A_STACK.len <= 100)
	// 	sort_in_halves(frame);
	// else
	// 	sort_in_quarters(frame);
}

int	main(int argc, const char **argv)
{
	t_data	frame;

	if (argc == 1)
		return (0);
	ft_bzero(&frame, sizeof(frame));
	parse_args(&frame, argc, argv);
	sort_stack(&frame);
	free_stacks(&frame);
	return (0);
}
