/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 14:03:09 by mraasvel      #+#    #+#                 */
/*   Updated: 2020/12/18 16:51:15 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "vectors.h"

void	print_vector(t_uint64vect *vector)
{
	for (size_t i = 0; i < vector->nmemb; i++)
	{
		printf("%lu: %llu\n", i, vector->table[i]);
	}
}

int	main(void)
{
	t_uint64vect	*values;
	
	values = uint64vect_init(0);
	uint64vect_pushback(0, values);
	uint64vect_pushback(-1, values);
	print_vector(values);
	printf("-1: %llu\n", (unsigned long long)-1);
	uint64vect_pushback(-1, values);
	uint64vect_free(values);
	return (0);
}
