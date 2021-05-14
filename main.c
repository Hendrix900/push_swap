/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 02:35:48 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/15 00:00:43 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_ctrl_parameters(int argc, t_control *ctrl)
{
	ctrl->n_movments = 0;
	ctrl->error = 0;
	ctrl->n_elem_stack = argc - 1;
	ctrl->stack_a = malloc(sizeof(int) * ctrl->n_elem_stack);
	ctrl->stack_b = malloc(sizeof(int) * ctrl->n_elem_stack);
	ctrl->stack_sorted = malloc(sizeof(int) * argc - 1);
}

int	main(int argc, char **argv)
{
	t_control	ctrl;
	int			n;

	init_ctrl_parameters(argc, &ctrl);
	if (argc < 2)
		p_error_exit("ERROR The number of arguments are incorrect", &ctrl);
	check_argv(argv, &ctrl);
	printf("Stack A            -------------        Stack Sorted\n");
	n = 0;
	while (n != argc - 1)
	{
		printf("%d                  -------------                 %d\n",
			ctrl.stack_a[n], ctrl.stack_sorted[n]);
		n++;
	}
	printf("numero de movimientos es : %d\n", ctrl.n_movments);
	free(ctrl.stack_a);
	free(ctrl.stack_b);
	free(ctrl.stack_sorted);
	return (0);
}
