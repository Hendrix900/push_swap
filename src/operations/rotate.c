/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 01:39:51 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/19 01:57:07 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(int n_elem, int *stack)
{
	int	tmp;
	int	l;
	int	first;

	tmp = 0;
	first = 0;
	l = 0;
	first = stack[0];
	while (l != n_elem)
	{
		stack[l] = stack[l + 1];
		l++;
	}
	stack[n_elem] = first;
}

void	rotate_a(t_control *crtl)
{
	int	n_elem;

	n_elem = crtl->n_elem_stack_a;
	rotate(n_elem, crtl->stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_control *crtl)
{
	int	n_elem;

	n_elem = crtl->n_elem_stack_b;
	rotate(n_elem, crtl->stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_ab(t_control *crtl)
{
	int	n_elem;

	n_elem = crtl->n_elem_stack_a;
	rotate(n_elem, crtl->stack_a);
	n_elem = crtl->n_elem_stack_b;
	rotate(n_elem, crtl->stack_b);
	ft_putstr_fd("rr\n", 1);
}
