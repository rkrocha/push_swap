/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkochhan <rkochhan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 09:19:02 by rkochhan          #+#    #+#             */
/*   Updated: 2021/09/09 10:00:31 by rkochhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stack.h"

int	main(void)
{
	t_dlist	*lst;
	size_t	i;

	i = 42;
	lst = NULL;
	while (i > 0)
	{
		ft_putstr("alloc new list member\n");
		dlst_add_front(&lst, dlst_new(i));
		i--;
	}
	dlst_iter(lst, ft_putnbr);
	ft_putchar('\n');
	dlst_clear(&lst);
	return (0);
}
