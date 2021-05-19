/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 01:37:10 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/19 04:41:44 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(int *stack_org, int *stack_dest, int n_elm_org, int n_elm_des)
{
	int	l;
	int	first_org;
	int	last_dest;
	int dest;

	first_org = 0;
	l = 0;
	first_org = stack_org[0];
	dest = n_elm_des;
//	printf("dest es %d\n", dest);
//	printf("stack_org[%d]\n", first_org);
	while (l != n_elm_org)
	{
//		printf("stack_org[%d]\n", stack_org[l]);
//		printf("stack_org[l + 1][%d]\n", stack_org[l + 1]);
		stack_org[l] = stack_org[l + 1];
		l++;
	}
	if (n_elm_des > 0)
	{
		last_dest = stack_dest[n_elm_des];
		while (n_elm_des > 0)
		{
//			printf("stack_dest[%d]\n", stack_dest[n_elm_des]);
//			printf("stack_dest - 1[%d]\n", stack_dest[n_elm_des - 1]);
			stack_dest[n_elm_des] = stack_dest[n_elm_des - 1];
//			printf("stack_dest[%d]\n", stack_dest[n_elm_des]);
			stack_dest[n_elm_des - 1] = last_dest;
//			printf("stack_dest - 1[%d]\n", stack_dest[n_elm_des - 1]);
			n_elm_des--;
		}
	}
	stack_dest[0] = first_org;
}

void	push_a(t_control *crtl)
{
	int	n_elem_org;
	int	n_elem_des;

	n_elem_org = crtl->n_elem_stack_b;
	n_elem_des = crtl->n_elem_stack_a;
	push(crtl->stack_b, crtl->stack_a, n_elem_org, n_elem_des);
	crtl->n_elem_stack_a += 1;
	crtl->n_elem_stack_b -= 1;
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_control *crtl)
{
	int	n_elem_org;
	int	n_elem_des;

	n_elem_org = crtl->n_elem_stack_a;
	n_elem_des = crtl->n_elem_stack_b;
	push(crtl->stack_a, crtl->stack_b, n_elem_org, n_elem_des);
	crtl->n_elem_stack_a -= 1;
	crtl->n_elem_stack_b += 1;
	ft_putstr_fd("pb\n", 1);
}
