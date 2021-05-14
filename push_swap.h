/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 02:31:39 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/14 22:10:33 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "./lib/libft/libft.h"
# include "./lib/get_next_line/get_next_line.h"

typedef struct s_control
{
	int			n_elem_stack;
	int			*stack_original;
	int			*stack_organized;
	int			error;
}				t_control;

int				main(int argc, char **argv);
int				check_argv(char **argv, t_control *ctrl);
void			p_error_exit(char *s, t_control *ctrl);
#endif