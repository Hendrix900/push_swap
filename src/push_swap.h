/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 02:31:39 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/15 14:09:13 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <stdlib.h>
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"

typedef struct s_control
{
	int			n_elem_stack_a;
	int			n_elem_stack_b;
	int			*stack_a;
	int			*stack_b;
	int			*stack_sorted;
	int			error;
	int			n_movments;
}				t_control;

int				main(int argc, char **argv);
int				check_argv(char **argv, t_control *ctrl);
int				ft_atoi_range(const char *str, t_control *ctrl);
void			prnt_error_exit(char *s, t_control *ctrl);
void			swap_a(t_control *crtl);
void			swap_b(t_control *crtl);
void			swap_ab(t_control *crtl);
void			rotate_a(t_control *crtl);
void			rotate_b(t_control *crtl);
void			rotate_ab(t_control *crtl);
void			rotate_rev_a(t_control *crtl);
void			rotate_rev_b(t_control *crtl);
void			rotate_rev_ab(t_control *crtl);
void			push_a(t_control *crtl);
void			push_b(t_control *crtl);
#endif