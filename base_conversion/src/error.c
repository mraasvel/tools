/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/14 19:11:43 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/02/15 21:15:49 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "base.h"

void FtPerror(ErrNum type, const char* message) {
	static const char* table[] = {
		"Success",
		"Invalid number of arguments",
		"Invalid argument",
		"Number doesn't belong to given base",
		"Malloc failed"
	};

	if (message != NULL) {
		printf("%s: %s\n", table[type], message);
	} else {
		printf("%s\n", table[type]);
	}
}
