/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 02:35:48 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/14 22:24:09 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_control	ctrl;
	int			n;

	ctrl.error = 0;
	ctrl.n_elem_stack = argc - 1;
	ctrl.stack_original = malloc(sizeof(int) * argc - 1);
	ctrl.stack_organized = malloc(sizeof(int) * argc - 1);
	if (argc < 2)
		p_error_exit("ERROR MENOS DE 2 ARGUMENTOS", &ctrl);
	check_argv(argv, &ctrl);
	printf("Stack A             -------------            Stack B\n");
	n = 0;
	while (n != argc - 1)
	{
		printf("%d                  -------------                 %d\n",
			ctrl.stack_original[n], ctrl.stack_organized[n]);
		n++;
	}
	free(ctrl.stack_original);
	free(ctrl.stack_organized);
	return (0);
}
