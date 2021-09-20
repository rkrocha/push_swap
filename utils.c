/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 08:57:30 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/20 08:34:37 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	free_stacks(t_data *frame)
{
	stack_clear(&frame->a_stack);
	stack_clear(&frame->b_stack);
}

void	error_exit(t_data *frame)
{
	free_stacks(frame);
	ft_putendl_fd("Error", 2);
	exit(EXIT_FAILURE);
}

int	value(t_dlist *elem)
{
	return (elem->content);
}
