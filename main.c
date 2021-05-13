/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccastill <ccastill@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 02:35:48 by ccastill          #+#    #+#             */
/*   Updated: 2021/05/13 03:59:22 by ccastill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int     main(int argc, char *argv[])
{
    int *argv_numbers = malloc(sizeof(int) * argc - 1);
    int l;
    int n;  
    
    l = 1;
    n = 0;
    while (l != argc)
    {
        argv_numbers[n] = atoi(argv[l]);
        l++;
        n++; 
    }
    n = 0;
    while (argv_numbers[n] != '\0')
    {
        printf("tiene : %d\n", argv_numbers[n]);
        n++; 
    }
    free(argv_numbers);
    return (0);
}