/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   int64vect.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/16 13:55:22 by mraasvel      #+#    #+#                 */
<<<<<<< HEAD:vectors_c/src/int64vect.c
/*   Updated: 2020/12/19 21:09:40 by mraasvel      ########   odam.nl         */
=======
/*   Updated: 2020/12/18 16:50:26 by mraasvel      ########   odam.nl         */
>>>>>>> 9261496d9f2f38b5b41c790f3cb1e2e4cc4dfcee:vectors_c/int64vect.c
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "vectors.h"

static void	*vect_memcpy(void *dest, void *src, size_t size)
{
	size_t	i;

	if (dest == src)
		return (dest);
	i = 0;
	while (i < size)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	return (dest);
}

t_int64vect	*int64vect_init(size_t initial_size)
{
	t_int64vect	*vector;

	if (initial_size == 0)
		initial_size = 2;
	vector = (t_int64vect*)malloc(1 * sizeof(t_int64vect));
	if (vector == NULL)
		return (NULL);
<<<<<<< HEAD:vectors_c/src/int64vect.c
	vector->table = (long long*)malloc(initial_size * sizeof(long long));
=======
	vector->table = (long long*)malloc(initial_size * sizeof(long));
>>>>>>> 9261496d9f2f38b5b41c790f3cb1e2e4cc4dfcee:vectors_c/int64vect.c
	if (vector->table == NULL)
	{
		free(vector);
		return (NULL);
	}
	vector->size = initial_size;
	vector->nmemb = 0;
	return (vector);
}

void		int64vect_free(t_int64vect *vector)
{
	free(vector->table);
	free(vector);
}

static int	int64vect_realloc(t_int64vect *vector)
{
	size_t		new_size;
	long long	*new_table;

	new_size = vector->size * 2;
	new_table = (long long*)malloc(new_size * sizeof(long long));
	if (new_table == NULL)
		return (-1);
	vect_memcpy(new_table, vector->table, vector->nmemb * sizeof(long long));
	free(vector->table);
	vector->table = new_table;
	vector->size = new_size;
	return (0);
}

int			int64vect_pushback(long long value, t_int64vect *vector)
{
	if (vector->nmemb == vector->size)
	{
		if (int64vect_realloc(vector) == -1)
		{
			int64vect_free(vector);
			return (-1);
		}
	}
	vector->table[vector->nmemb] = value;
	vector->nmemb += 1;
	return (0);
}
