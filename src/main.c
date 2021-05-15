/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 02:35:48 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/15 14:21:15 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ctrl_parameters(int argc, t_control *ctrl)
{
	int	l;

	ctrl->n_movments = 0;
	ctrl->error = 0;
	ctrl->n_elem_stack_a = argc - 1;
	ctrl->n_elem_stack_b = 0;
	ctrl->stack_a = malloc(sizeof(int) * ctrl->n_elem_stack_a);
	ctrl->stack_b = malloc(sizeof(int) * ctrl->n_elem_stack_a);
	ctrl->stack_sorted = malloc(sizeof(int) * argc - 1);
	l = 0;
	
	while(l != ctrl->n_elem_stack_a )
	{
		ctrl->stack_b[l] = 0;
		l++;
	}
}

int	main(int argc, char **argv)
{
	t_control	ctrl;
	int			n;

	init_ctrl_parameters(argc, &ctrl);
	if (argc < 2)
		prnt_error_exit("ERROR The number of arguments are incorrect", &ctrl);
	check_argv(argv, &ctrl);
	
	// ------ Print Stack A and Stack Sorted ---- //
	printf("Stack A            -------------        Stack Sorted\n");
	n = 0;
	while (n != argc - 1)
	{
		printf("%d                  -------------                 %d\n",
			ctrl.stack_a[n], ctrl.stack_sorted[n]);
		n++;
	}
	printf("\n\n");
		
	//---- Instruccions ----//
	push_b(&ctrl); 
	push_b(&ctrl); 
	swap_ab(&ctrl); 
	
	//---- Examples of Stack A and B after instruccions ----//
	n = 0;
	printf("Stack A\n");
	while (n != ctrl.n_elem_stack_a)
	{
		printf("%d\n",ctrl.stack_a[n]);
		n++;
	}
	n = 0;
	printf("Stack B\n");
	while (n != ctrl.n_elem_stack_b)
	{
		printf("%d\n",ctrl.stack_b[n]);
		n++;
	}
	
	// --- Some control parameters --- ///
	printf("Numero de movimientos: %d\n", ctrl.n_movments);
	printf("Numero de elementos en argv: %d\n", ctrl.n_elem_stack_a);

	// ---- Free memory allocated ----
	free(ctrl.stack_a);
	free(ctrl.stack_b);
	free(ctrl.stack_sorted);
	return (0);
}
