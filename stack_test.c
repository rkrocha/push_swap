/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:17:50 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/09 13:51:28 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

void	basic_test(t_stack *stack)
{
	stack_print(stack, NULL);
	stack_push(stack, dlst_new(1));
	stack_push(stack, dlst_new(2));
	stack_push(stack, dlst_new(3));
	stack_print(stack, NULL);
	stack_clear(stack);
	stack_print(stack, NULL);
	ft_putendl("---------------\n");
}

void	push_pop_test(t_stack *a_stack, t_stack *b_stack)
{
	stack_pop(a_stack);
	stack_push(a_stack, dlst_new(1));
	stack_push(a_stack, dlst_new(2));
	stack_push(a_stack, dlst_new(3));
	stack_push(b_stack, stack_pop(a_stack));
	stack_print(a_stack, "a");
	stack_print(b_stack, "b");
	stack_push(a_stack, stack_pop(b_stack));
	stack_print(a_stack, "a");
	stack_print(b_stack, "b");
	stack_clear(a_stack);
	stack_clear(b_stack);
	ft_putendl("---------------\n");
}

int	main(int argc, char **argv)
{
	t_stack	a_stack;
	t_stack	b_stack;

	ft_bzero(&a_stack, sizeof(t_stack));
	ft_bzero(&b_stack, sizeof(t_stack));
	if (argc == 1 || (argc > 1 && !ft_strncmp (argv[1], "1", 2)))
		basic_test(&a_stack);
	else if (argc > 1 && !ft_strncmp (argv[1], "2", 2))
		push_pop_test(&a_stack, &b_stack);
	return (0);
}
