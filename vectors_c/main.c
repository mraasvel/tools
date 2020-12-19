/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 14:03:09 by mraasvel      #+#    #+#                 */
<<<<<<< HEAD
/*   Updated: 2020/12/19 21:02:22 by mraasvel      ########   odam.nl         */
=======
/*   Updated: 2020/12/18 16:51:15 by mraasvel      ########   odam.nl         */
>>>>>>> 9261496d9f2f38b5b41c790f3cb1e2e4cc4dfcee
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>
#include "vectors.h"

void	print_vector(t_uint64vect *vector)
{
<<<<<<< HEAD
	t_ldblvect	*vector;
	
	
	vector = ldblvect_init(0);
	ldblvect_pushback(vector, 234.394857389475);
	printf("%Lf\n", vector->table[0]);
	ldblvect_free(vector);
=======
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
>>>>>>> 9261496d9f2f38b5b41c790f3cb1e2e4cc4dfcee
	return (0);
}
