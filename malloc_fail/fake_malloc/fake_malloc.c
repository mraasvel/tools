/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fake_malloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 08:47:39 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/04/27 08:57:55 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

#ifndef MALLOC_FAIL
# define MALLOC_FAIL 10
#endif

#ifndef MALLOC_PRINT
# define MALLOC_PRINT 0
#endif

void	*fake_malloc(size_t size)
{
	static int	counter = 0;

	counter++;
	if (MALLOC_PRINT)
		printf("MALLOC: %d - FAIL AT: %d\n", counter, MALLOC_FAIL);
	if (counter == MALLOC_FAIL)
		return (NULL);
	return (malloc(size));
}
